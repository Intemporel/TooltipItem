#include <QApplication>

#include <TooltipItem/tooltipitem.h>

TooltipItem * item;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsView * view = new QGraphicsView();

    item = new TooltipItem();

        item->setName("Chute-des-cieux, kriss des mille mensonges", EPIC);
        item->setHeroicFlag(true);
        item->setBonding(BIND_WHEN_PICKED_UP);
        item->setClassAndSubclassAndSlot(WEAPON, SUBCLASS_WEAPON::WEAPON_DAGGER, 0);
        item->setStat({ITEM_MOD_AGILITY,ITEM_MOD_STAMINA,ITEM_MOD_ATTACK_POWER,ITEM_MOD_CRIT_MELEE_RATING,ITEM_MOD_HASTE_MELEE_RATING},{76,84,111,48,56});
        item->setSocket({SOCKET_COLOR::RED});
        item->setDamage(381,572,1.8);
        item->setDurability(75);
        item->setLevelRequired(80);
        item->setDescription("Le mensonge hait ceux qu'il écrase, mais la flatterie provoque la ruine.");
        item->setSellPrice(272274);

        item->drawTooltip();

    view->setScene(item);
    view->show();

    return a.exec();
}
