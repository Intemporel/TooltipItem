#include "tooltipitem.h"
#include <QDebug>

TooltipItem::TooltipItem(){ }

void TooltipItem::setName(QString name, int quality){
    list_data[TOOLTIP_POSITION::NAME] = true;
    str_data[TOOLTIP_POSITION::NAME] = name;
    clr_data[TOOLTIP_POSITION::NAME] = quality;
}

void TooltipItem::setHeroicFlag(bool isHeroic){
    list_data[TOOLTIP_POSITION::HEROIC_FLAG] = isHeroic;
}

void TooltipItem::setBonding(int bounding_type){
    if (bounding_type <= BONDING_TYPE::NO_BOUND or bounding_type > BONDING_TYPE::BIND_QUEST_ITEM1)
        return;

    list_data[TOOLTIP_POSITION::BONDING] = true;
    str_data[TOOLTIP_POSITION::BONDING] = BOUND[bounding_type];
}

void TooltipItem::setUniqueFlag(bool isUnique){
    list_data[TOOLTIP_POSITION::UNIQUE_FLAG] = isUnique;
}

void TooltipItem::setClassAndSubclassAndSlot(int _class, int subclass, int slot){
    if (_class == CLASS::ARMOR)
        subclass = slot;

    if (STR_SUBCLASS[_class][subclass] == "" and STR_SUBCLASS_RIGHT[_class][subclass] == "")
        return;

    if (STR_SUBCLASS[_class][subclass] != "") {
        list_data[TOOLTIP_POSITION::SUBCLASS] = true;

        if (_class == CLASS::CONTAINER) {
            str_data[TOOLTIP_POSITION::SUBCLASS] = QString(STR_SUBCLASS[_class][subclass]).arg(slot);
        } else {
            str_data[TOOLTIP_POSITION::SUBCLASS] = STR_SUBCLASS[_class][subclass];
        }
    }

    if (STR_SUBCLASS_RIGHT[_class][subclass] != "") {
        list_data[TOOLTIP_POSITION::SUBCLASS_RIGHT] = true;
        str_data[TOOLTIP_POSITION::SUBCLASS_RIGHT] = STR_SUBCLASS_RIGHT[_class][subclass];
    }
}

void TooltipItem::setDamage(int min, int max, qreal speed){
    if (min > max)
        return;

    if (speed==0)
        return;

    list_data[TOOLTIP_POSITION::DAMAGE] = true;
    list_data[TOOLTIP_POSITION::DPS] = true;
    list_data[TOOLTIP_POSITION::SPEED] = true;

    str_data[TOOLTIP_POSITION::DAMAGE] = QString("Dégâts : %1 - %2").arg(min).arg(max);
    str_data[TOOLTIP_POSITION::DPS] = QString("(%1 dégâts par seconde)").arg(qFloor(((min/speed)+(max/speed))/2));
    str_data[TOOLTIP_POSITION::SPEED] = QString("Vitesse %1").arg(speed);
}

void TooltipItem::setStat(QVector<int> stat_type, QVector<int> stat_value){

    if (stat_type.length() != stat_value.length()
            or stat_type.length() == 0
            or stat_value.length() == 0)
        return;

    if (stat_type.length() > MAX_STAT)
        return;

    for (int i=0; i<stat_type.length() ; i++) {

        if (stat_type[i] == STAT_TYPE_2_NONE)
            return;

        if (stat_type[i] >= STAT_TYPE::ITEM_MOD_MANA and stat_type[i] <= STAT_TYPE::ITEM_MOD_STAMINA)
            list_data[TOOLTIP_POSITION::STAT_UP] = true;

        if (stat_type[i] >= STAT_TYPE::ITEM_MOD_DEFENSE_SKILL_RATING and stat_type[i] <= STAT_TYPE::ITEM_MOD_BLOCK_VALUE)
            list_data[TOOLTIP_POSITION::STAT_DOWN] = true;
    }

    STAT_TYPE = stat_type;
    STAT_VALUE = stat_value;
}

void TooltipItem::setSocket(QVector<int> socketList){
    if (socketList.length() < SOCKET_COLOR::PRISMATIC or socketList.length() > SOCKET_COLOR::BLUE)
        return;

    list_data[TOOLTIP_POSITION::SOCKET] = true;
    SOCKET_LIST = socketList;
}

void TooltipItem::setDurability(int durability){
    if (durability < 0)
        return;

   list_data[TOOLTIP_POSITION::DURABILITY] = true;
   str_data[TOOLTIP_POSITION::DURABILITY] = QString("Durabilité %1/%1").arg(durability);
}

void TooltipItem::setLevelRequired(int level){
    if (level <= 0)
        return;

    list_data[TOOLTIP_POSITION::LEVEL_REQUIRED] = true;
    str_data[TOOLTIP_POSITION::LEVEL_REQUIRED] = QString("Niveau %1 requis").arg(level);
}

void TooltipItem::setDescription(QString description){
    list_data[TOOLTIP_POSITION::DESCRIPTION] = true;
    str_data[TOOLTIP_POSITION::DESCRIPTION] = QString("\"%1\"").arg(resizeTextWithName(description));
}

void TooltipItem::setSellPrice(int amount){

    int gold = qFloor(amount/qPow(10,4));
    int silver = qFloor((amount-(gold*qPow(10,4)))/qPow(10,2));
    int copper = ((amount-(gold*qPow(10,4)))-(silver*qPow(10,2)));

    list_data[TOOLTIP_POSITION::SELL_PRICE] = true;
    str_data[TOOLTIP_POSITION::SELL_PRICE] = QString("Prix de vente : %1%2 %3%4 %5%6").arg(gold).arg(MONEY[2]).arg(silver).arg(MONEY[1]).arg(copper).arg(MONEY[0]);
}

void TooltipItem::drawTooltip(){
    data.clear();

    //Remove current item in scene
    QList<QGraphicsItem *> toClear = items();
    for (int i=0; i<items().size(); i++)
        removeItem(toClear[i]);

    toClear.clear();

    back->setBrush(QBrush(QColor(backgroundColor)));
    addItem(back);

    tooltip->setPos(0,0);
    addItem(tooltip);

    int count = 0;
    int position_subclass = 0;
    int position_speed = 0;

    int offset_stat = 0;
    int offset_description = 0;

    int stat_up_index = 0;
    int stat_down_index = 0;
    int socket_index = 0;

    int index_data = 0;

    for (int i=TOOLTIP_POSITION::NAME; i<=TOOLTIP_POSITION::SELL_PRICE; i++){
        index_data = i + stat_up_index + stat_down_index + socket_index;

        if ( i != TOOLTIP_POSITION::STAT_UP and i != TOOLTIP_POSITION::STAT_DOWN and i != TOOLTIP_POSITION::SOCKET)
            data.push_back(new QGraphicsTextItem());

        if (( i == TOOLTIP_POSITION::STAT_UP or i == TOOLTIP_POSITION::STAT_DOWN or i == TOOLTIP_POSITION::SOCKET) and not list_data[i])
            data.push_back(new QGraphicsTextItem());

        if (list_data[i]) {
            if (i == TOOLTIP_POSITION::SUBCLASS)
                position_subclass = count;

            if (i == TOOLTIP_POSITION::DAMAGE)
                position_speed = count;

            if (i == TOOLTIP_POSITION::STAT_UP or i == TOOLTIP_POSITION::STAT_DOWN) {
                int range [2] = {0,0};
                int current_index = 0;
                if (i == TOOLTIP_POSITION::STAT_UP) {
                    stat_up_index = -1;
                    range[0] = STAT_TYPE::ITEM_MOD_MANA;
                    range[1] = STAT_TYPE::ITEM_MOD_STAMINA;
                } else {
                    stat_down_index = -1;
                    range[0] = STAT_TYPE::ITEM_MOD_DEFENSE_SKILL_RATING;
                    range[1] = STAT_TYPE::ITEM_MOD_BLOCK_VALUE;
                }

                for (int y = 0; y < STAT_TYPE.length() ; y++ ) {

                    if (STAT_VALUE[y] == 0)
                        continue;

                    if (STAT_TYPE[y] >= range[0] and STAT_TYPE[y] <= range[1]) {
                        data.push_back(new QGraphicsTextItem);

                        data[index_data+current_index]->setPos(4, count*OFFSET_SLOT_Y+offset_stat);
                        data[index_data+current_index]->setDefaultTextColor(QColor(QUALITY[clr_data[i]]));
                        data[index_data+current_index]->setFont(QFont(POLICY, size_str_data[i]));
                        QString st = resizeTextWithName(STR_STAT[STAT_TYPE[y]].arg(STAT_VALUE[y]));
                        data[index_data+current_index]->setHtml(st);
                        addItem(data[index_data+current_index]);

                        if (i == TOOLTIP_POSITION::STAT_UP) stat_up_index++;
                        else stat_down_index++;

                        int minus_offset = 0;
                        if (st.count("<br>") != 0 ) minus_offset = 6;

                        offset_stat += st.count("<br>")*size_str_data[i]+minus_offset;
                        current_index++;
                        count++;
                    }
                }

                continue;
            }

            if (i == TOOLTIP_POSITION::SOCKET) {
                socket_index = -1;

                for (int y=0; y<SOCKET_LIST.length(); y++) {
                    data.push_back(new QGraphicsTextItem());

                    data[index_data+y]->setPos(4, count*OFFSET_SLOT_Y+offset_stat);
                    data[index_data+y]->setDefaultTextColor(QColor(QUALITY[clr_data[i]]));
                    data[index_data+y]->setFont(QFont(POLICY, size_str_data[i]));
                    data[index_data+y]->setHtml(STR_SOCKET[SOCKET_LIST[y]].arg(SOCKET[SOCKET_LIST[y]]));
                    addItem(data[index_data+y]);

                    socket_index++;
                    count++;
                }

                continue;
            }

            if (i == TOOLTIP_POSITION::SELL_PRICE) {
                if (list_data[TOOLTIP_POSITION::DESCRIPTION]) {
                    offset_description = size_str_data[TOOLTIP_POSITION::DESCRIPTION]*str_data[TOOLTIP_POSITION::DESCRIPTION].count("<br>")+6;
                }
            }

                data[index_data]->setPos(4,count*OFFSET_SLOT_Y+offset_stat+offset_description);
                data[index_data]->setDefaultTextColor(QColor(QUALITY[clr_data[i]]));
                data[index_data]->setFont(QFont(POLICY, size_str_data[i]));
                data[index_data]->setHtml(str_data[i]);
                addItem(data[index_data]);

                count++;
        }
    }

    if (list_data[TOOLTIP_POSITION::SUBCLASS]) {
        data.push_back(new QGraphicsTextItem());

        int new_subclass_right = TOOLTIP_POSITION::SUBCLASS_RIGHT + stat_up_index + stat_down_index + socket_index;

        if (list_data[TOOLTIP_POSITION::SUBCLASS_RIGHT]) {
            QFont F(POLICY, size_str_data[TOOLTIP_POSITION::SUBCLASS_RIGHT]);
            QFontMetrics FM(F);

            data[new_subclass_right]->setPos(width()-FM.horizontalAdvance(str_data[TOOLTIP_POSITION::SUBCLASS_RIGHT])-4,position_subclass*OFFSET_SLOT_Y);
            data[new_subclass_right]->setDefaultTextColor(QColor(QUALITY[clr_data[TOOLTIP_POSITION::SUBCLASS_RIGHT]]));
            data[new_subclass_right]->setFont(F);
            data[new_subclass_right]->setHtml(str_data[TOOLTIP_POSITION::SUBCLASS_RIGHT]);
            addItem(data[new_subclass_right]);
        }
    }

    if (list_data[TOOLTIP_POSITION::DAMAGE]) {
        data.push_back(new QGraphicsTextItem());

        int new_speed = TOOLTIP_POSITION::SPEED + stat_up_index + stat_down_index + socket_index;

        if (list_data[TOOLTIP_POSITION::SPEED]) {
            QFont F(POLICY, size_str_data[TOOLTIP_POSITION::SPEED]);
            QFontMetrics FM(F);

            data[new_speed]->setPos(width()-FM.horizontalAdvance(str_data[TOOLTIP_POSITION::SPEED])-4,position_speed*OFFSET_SLOT_Y);
            data[new_speed]->setDefaultTextColor(QColor(QUALITY[clr_data[TOOLTIP_POSITION::SPEED]]));
            data[new_speed]->setFont(F);
            data[new_speed]->setHtml(str_data[TOOLTIP_POSITION::SPEED]);
            addItem(data[new_speed]);
        }
    }

    resizeTooltip();
}


void TooltipItem::resizeTooltip(){
    tooltip->setPixmap(background.scaled(width()+8, height(), Qt::IgnoreAspectRatio));
    back->setRect(0,0,width(),height());
}

QString TooltipItem::resizeTextWithName(QString st){
    if (not list_data[TOOLTIP_POSITION::NAME])
        return st;

    if (str_data[TOOLTIP_POSITION::NAME].length() < st.length()) {
        int mult_size = qFloor(st.length()/str_data[TOOLTIP_POSITION::NAME].length());

        for (int i=1; i<=mult_size; i++) {
            int where_to_insert = i*str_data[0].length();

            while (st.at(where_to_insert) != QChar(' ')) {
                if (where_to_insert < 0)
                    break;

                where_to_insert--;
            }

            st.insert(where_to_insert, "<br>");
        }
    }

    return st;
}

