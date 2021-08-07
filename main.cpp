#include <QApplication>

#include <TooltipItem/tooltipitem.h>

TooltipItem * item;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsView * view = new QGraphicsView();

    item = new TooltipItem();

        item->setName("Cuir de morceaux de Fléau cousus", EPIC);
        item->setHeroicFlag(true);
        item->setBonding(BONDING_TYPE::BIND_WHEN_PICKED_UP);
        item->setClassSubclassAndSlot(ARMOR, SUBCLASS_ARMOR::ARMOR_LEATHER, 7);
        item->setArmor(608);
        item->setStat({
                          STAT_TYPE::ITEM_MOD_STAMINA,
                          STAT_TYPE::ITEM_MOD_INTELLECT,
                          STAT_TYPE::ITEM_MOD_SPIRIT,
                          STAT_TYPE::ITEM_MOD_SPELL_POWER,
                          STAT_TYPE::ITEM_MOD_HASTE_RATING},
                      {
                          139,139,122,185,98
                      });
        item->setRes({10,0,0,54,8,50});
        item->setSocket({
                            SOCKET_COLOR::BLUE,
                            SOCKET_COLOR::RED,
                            SOCKET_COLOR::YELLOW
                        });
        item->setDurability(90);
        item->setLevelRequired(80);
        item->setSellPrice(132939);


        item->drawTooltip();

    view->setScene(item);
    view->show();

    return a.exec();
}
