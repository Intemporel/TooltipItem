#ifndef TOOLTIPITEM_H
#define TOOLTIPITEM_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>

enum TOOLTIP_POSITION {
    NAME,
    HEROIC_FLAG,
    BONDING,
    UNIQUE_FLAG,
    SUBCLASS,
    PLAYER_CLASS,
    DAMAGE_OR_ARMOR,
    DPS,
    STAT_UP,
    RESISTANCE,
    SOCKET,
    SOCKET_BONUS,
    DURABILITY,
    LEVEL_REQUIRED,
    STAT_DOWN,
    DESCRIPTION,
    SELL_PRICE,
    SUBCLASS_RIGHT,
    SPEED
};

enum QUALITY_COLOR {
    POOR,
    COMMUN,
    UNCOMMUN,
    RARE,
    EPIC,
    LEGENDARY,
    ARTIFACT,
    HEIRLOOMS,
    NORMAL
};

enum BONDING_TYPE {
    NO_BOUND,
    BIND_WHEN_PICKED_UP,
    BIND_WHEN_EQUIPPED,
    BIND_WHEN_USED,
    BIND_QUEST_ITEM,
    BIND_QUEST_ITEM1
};

enum SOCKET_COLOR {
    PRISMATIC,
    RED,
    YELLOW,
    BLUE
};

enum MONEY_TYPE {
    COPPER,
    SILVER,
    GOLD
};

enum CLASS {
    CONSUMABLE,
    CONTAINER, // done
    WEAPON,
    GEM,
    ARMOR,
    REAGENT,
    PROJECTILE,
    TRADE_GOODS,
    GENERIC,
    RECIPE,
    MONEY,
    QUIVER,
    QUEST,
    KEY,
    PERMANENT,
    MISCELLANEOUS,
    GLYPH
};

enum SUBCLASS_CONSUMABLE {
    CONSUMABLE_BASE,
    CONSUMABLE_POTION,
    CONSUMABLE_ELIXIR,
    CONSUMABLE_FLASK,
    CONSUMABLE_SCROLL,
    CONSUMABLE_FOOD_DRINK,
    CONSUMABLE_ITEM_ENHANCEMENT,
    CONSUMABLE_BANDAGE,
    CONSUMABLE_OTHER
};

enum SUBCLASS_CONTAINER {
    CONTAINER_BAG,
    CONTAINER_SOUL_BAG,
    CONTAINER_HERB_BAG,
    CONTAINER_ENCHANTING_BAG,
    CONTAINER_ENGINEERING_BAG,
    CONTAINER_GEM_BAG,
    CONTAINER_MINING_BAG,
    CONTAINER_LEATHERWORKING_BAG,
    CONTAINER_INSCRIPTION_BAG
};

enum SUBCLASS_WEAPON {
    WEAPON_AXE_ONE_HANDED,
    WEAPON_AXE_TWO_HANDED,
    WEAPON_BOW,
    WEAPON_GUN,
    WEAPON_MACE_ONE_HANDED,
    WEAPON_MACE_TWO_HANDED,
    WEAPON_POLEARM,
    WEAPON_SWORD_ONE_HANDED,
    WEAPON_SWORD_TWO_HANDED,
    WEAPON_OBSOLETE,
    WEAPON_STAFF,
    WEAPON_EXOTIC_1,
    WEAPON_EXOTIC_2,
    WEAPON_FIST_WEAPON,
    WEAPON_MISCELLANEOUS_WEAPON,
    WEAPON_DAGGER,
    WEAPON_THROWN,
    WEAPON_SPEAR,
    WEAPON_CROSSBOW,
    WEAPON_WAND,
    WEAPON_FISHING_POLE
};

enum SUBCLASS_GEM {
    GEM_RED,
    GEM_BLUE,
    GEM_YELLOW,
    GEM_PURPLE,
    GEM_GREEN,
    GEM_ORANGE,
    GEM_META,
    GEM_SIMPLE,
    GEM_PRISMATIC
};

enum SUBCLASS_ARMOR {
    ARMOR_MISCELLANEOUS,
    ARMOR_CLOTH,
    ARMOR_LEATHER,
    ARMOR_MAIL,
    ARMOR_PLATE,
    ARMOR_BUCKLER,
    ARMOR_SHIELD,
    ARMOR_LIBRAM,
    ARMOR_IDOL,
    ARMOR_TOTEM,
    ARMOR_SIGIL
};

enum SUBCLASS_REAGENT {
    REAGENT_BASE
};

enum SUBCLASS_PROJECTILE {
    PROJECTILE_WAND,
    PROJECTILE_BOLT,
    PROJECTILE_ARROW,
    PROJECTILE_BULLET,
    PROJECTILE_THROWN
};

enum SUBCLASS_TRADE_GOODS {
    TRADE_GOODS_BASE,
    TRADE_GOODS_PARTS,
    TRADE_GOODS_EXPLOSIVES,
    TRADE_GOODS_DEVISES,
    TRADE_GOODS_JEWELCRAFTING,
    TRADE_GOODS_CLOTH,
    TRADE_GOODS_LEATHER,
    TRADE_GOODS_METAL_STONE,
    TRADE_GOODS_MEAT,
    TRADE_GOODS_HERB,
    TRADE_GOODS_ELEMENTAL,
    TRADE_GOODS_OTHER,
    TRADE_GOODS_ENCHANTING,
    TRADE_GOODS_MATERIALS,
    TRADE_GOODS_ARMOR_ENCHANTMENT,
    TRADE_GOODS_WEAPON_ENCHANTMENT
};

enum SUBCLASS_GENERIC {
    GENERIC_BASE
};

enum SUBCLASS_RECIPE {
    RECIPE_BOOK,
    RECIPE_LEATHERWORKING,
    RECIPE_TAILORING,
    RECIPE_ENGINEERING,
    RECIPE_BLACKSMITHING,
    RECIPE_COOKING,
    RECIPE_ALCHEMY,
    RECIPE_FIRST_AID,
    RECIPE_ENCHANTING,
    RECIPE_FISHING,
    RECIPE_JEWELCRAFTING
};

enum SUBCLASS_MONEY {
    MONEY_BASE
};

enum SUBCLASS_QUIVER {
    QUIVER_1,
    QUIVER_2,
    QUIVER_BASE,
    QUIVER_AMMO_POUCH
};

enum SUBCLASS_QUEST {
    QUEST_BASE
};

enum SUBCLASS_KEY {
    KEY_BASE,
    KEY_LOCKPICK
};

enum SUBCLASS_PERMANENT {
    PERMANENT_BASE,
    PERMANENT_JUNK
};

enum SUBCLASS_MISCELLANEOUS {
    MISC_REAGENT,
    MISC_PET,
    MISC_HOLIDAY,
    MISC_OTHER,
    MISC_MOUNT
};

enum SUBCLASS_GLYPH {
    NO_ZERO_GLYPH,
    GLYPH_WARRIOR,
    GLYPH_PALADIN,
    GLYPH_HUNTER,
    GLYPH_ROGUE,
    GLYPH_PRIEST,
    GLYPH_DEATH_KNIGHT,
    GLYPH_SHAMAN,
    GLYPH_MAGE,
    GLYPH_WARLOCK,
    NO_TEN_GLYPH,
    GLYPH_DRUID
};

enum STAT_TYPE {
    ITEM_MOD_MANA,
    ITEM_MOD_HEALTH,
    STAT_TYPE_2_NONE,
    ITEM_MOD_AGILITY,
    ITEM_MOD_STRENGTH,
    ITEM_MOD_INTELLECT,
    ITEM_MOD_SPIRIT,
    ITEM_MOD_STAMINA,
    STAT_TYPE_8_NONE,
    STAT_TYPE_9_NONE,
    STAT_TYPE_10_NONE,
    STAT_TYPE_11_NONE,
    ITEM_MOD_DEFENSE_SKILL_RATING,
    ITEM_MOD_DODGE_RATING,
    ITEM_MOD_PARRY_RATING,
    ITEM_MOD_BLOCK_RATING,
    ITEM_MOD_HIT_MELEE_RATING,
    ITEM_MOD_HIT_RANGED_RATING,
    ITEM_MOD_HIT_SPELL_RATING,
    ITEM_MOD_CRIT_MELEE_RATING,
    ITEM_MOD_CRIT_RANGED_RATING,
    ITEM_MOD_CRIT_SPELL_RATING,
    ITEM_MOD_HIT_TAKEN_MELEE_RATING,
    ITEM_MOD_HIT_TAKEN_RANGED_RATING,
    ITEM_MOD_HIT_TAKEN_SPELL_RATING,
    ITEM_MOD_CRIT_TAKEN_MELEE_RATING,
    ITEM_MOD_CRIT_TAKEN_RANGED_RATING,
    ITEM_MOD_CRIT_TAKEN_SPELL_RATING,
    ITEM_MOD_HASTE_MELEE_RATING,
    ITEM_MOD_HASTE_RANGED_RATING,
    ITEM_MOD_HASTE_SPELL_RATING,
    ITEM_MOD_HIT_RATING,
    ITEM_MOD_CRIT_RATING,
    ITEM_MOD_HIT_TAKEN_RATING,
    ITEM_MOD_CRIT_TAKEN_RATING,
    ITEM_MOD_RESILIENCE_RATING,
    ITEM_MOD_HASTE_RATING,
    ITEM_MOD_EXPERTISE_RATING,
    ITEM_MOD_ATTACK_POWER,
    ITEM_MOD_RANGED_ATTACK_POWER,
    ITEM_MOD_FERAL_ATTACK_POWER,
    ITEM_MOD_SPELL_HEALING_DONE,
    ITEM_MOD_SPELL_DAMAGE_DONE,
    ITEM_MOD_MANA_REGENERATION,
    ITEM_MOD_ARMOR_PENETRATION_RATING,
    ITEM_MOD_SPELL_POWER,
    ITEM_MOD_HEALTH_REGEN,
    ITEM_MOD_SPELL_PENETRATION,
    ITEM_MOD_BLOCK_VALUE
};

enum RES_TYPE {
    RES_HOLY,
    RES_FIRE,
    RES_NATURE,
    RES_FROST,
    RES_SHADOW,
    RES_ARCANE
};

// add player_class enum
enum PLAYER_CLASS {
    NONE_0,
    CLASS_WARRIOR,
    CLASS_PALADIN,
    CLASS_HUNTER,
    CLASS_ROGUE,
    CLASS_PRIEST,
    CLASS_DEATH_KNIGHT,
    CLASS_SHAMAN,
    CLASS_MAGE,
    CLASS_WARLOCK,
    NONE_10,
    CLASS_DRUID
};

class TooltipItem : public QGraphicsScene {
public:
    TooltipItem();

    // GRAPHICS
    QGraphicsPixmapItem * tooltip = new QGraphicsPixmapItem();
    QGraphicsRectItem * back = new  QGraphicsRectItem();
    QVector<QGraphicsTextItem *> data;

    // SET FUNCTIONS
    void setName(QString, int);
    void setHeroicFlag(bool);
    void setBonding(int);
    void setUniqueFlag(bool);
    void setClassSubclassAndSlot(int,int,int);
    void setDamage(int, int, qreal);
    void setArmor(int);
    void setStat(QVector<int>, QVector<int>);
    void setRes(QVector<int>);
    void setSocket(QVector<int>);
    void setDurability(int);
    void setLevelRequired(int);
    void setDescription(QString);
    void setSellPrice(int);

    // GRAPHICS FUNCTIONS
    void drawTooltip();
    void resizeTooltip();
    QString resizeText(QString);
    void checkSubclassAndSubclassRightColliding();
        int subclassRightPosition = 0;

private:
    bool list_data [19] = {
        false, //name
        false, //heroic_flag
        false, //bonding
        false, //unique_flag
        false, //subclass
        false, //player class
        false, //damage or armor
        false, //dps
        false, //stat [0,7]
        false, //resistance
        false, //socket
        false, //socket_bonus
        false, //durability
        false, //level_requiered
        false, //other_stat [12,48]
        false, //description
        false, //sell_price
        false, //subclass_right
        false  //speed
    };

    QString str_data [19] = {
        "", //name
        "Héroïque", //heroic_flag
        "", //bonding
        "Unique", //unique_flag
        "", //subclass
        "", //player class
        "", //damage or armor
        "", //dps
        "", //stat [0,7]
        "", //resistance
        "", //socket
        "", //socket_bonus
        "", //durability
        "", //level_requiered
        "", //other_stat [12,48]
        "", //description
        "", //sell_price
        "", //subclass_right
        ""  //speed
    };

    int clr_data [19] = {
        COMMUN, //name
        UNCOMMUN, //heroic_flag
        COMMUN, //bonding
        COMMUN, //unique_flag
        COMMUN, //subclass
        COMMUN, //player class
        COMMUN, //damage or armor
        COMMUN, //dps
        COMMUN, //stat [0,7]
        COMMUN, //resistance
        POOR, //socket
        POOR, //socket_bonus
        COMMUN, //durability
        COMMUN, //level_requiered
        UNCOMMUN, //other_stat [12,48]
        NORMAL, //description
        COMMUN, //sell_price
        COMMUN, //subclass_right
        COMMUN  //speed
    };

    int size_str_data [19] = {
        13, //name
        12, //heroic_flag
        12, //bonding
        12, //unique_flag
        12, //subclass
        12, //player class
        12, //damage or armor
        12, //dps
        12, //stat [0,7]
        12, //resistance
        12, //socket
        12, //socket_bonus
        12, //durability
        12, //level_requiered
        12, //other_stat [12,48]
        12, //description
        12, //sell_price
        12, //subclass_right
        12  //speed
    };

    QVector<int> STAT_TYPE;
    QVector<int> STAT_VALUE;
    QVector<int> SOCKET_LIST;
    QVector<int> RES_VALUE;

    QVector<QVector<QString>> STR_SUBCLASS = {
        {"","","","","","","","",""}, // CONSUMABLE
        { // BAG
            "Sac %1 emplacements",
            "Sac d'âmes %1 emplacements",
            "Sac d'herbes %1 emplacements",
            "Sac d'enchanteur %1 emplacements",
            "Sac d'ingénieur %1 emplacements",
            "Sac de gemmes %1 emplacements",
            "Sac de mineur %1 emplacements",
            "Sac de travailleur du cuir %1 emplacements",
            "Sac de calligraphe %1 emplacements"
        },
        { // WEAPON
            "A une main",
            "Deux mains",
            "A distance",
            "A distance",
            "A une main",
            "Deux mains",
            "Deux mains",
            "A une main",
            "Deux mains",
            "",
            "Deux mains",
            "",
            "",
            "A une main",
            "Divers",
            "A une main",
            "Arme de jet",
            "Arme de jet",
            "A distance",
            "A distance",
            "Deux mains"
        },
        {"","","","","","","","",""}, // GEM
        { // ARMOR
            "",
            "Tête",
            "Cou",
            "Epaulière",
            "Chemise",
            "Plastron",
            "Ceinture",
            "Jambes",
            "Pieds",
            "Poignets",
            "Mains",
            "Doigt",
            "Bijou",
            "",
            "Main gauche",
            "",
            "Cape",
            "",
            "",
            "",
            "Robe",
            "",
            "",
            "",
            "",
            "",
            "",
            "",
            ""
        },
        {""}, // REAGENT
        {"","","","",""}, // PROJECTILE
        {"","","","","","","","","","","","","","","",""}, // TRADE_GOODS
        {""}, // GENERIC
        {"","","","","","","","","","",""}, // RECIPE
        {""}, // MONEY
        {"","","",""}, // QUIVER
        {""}, // QUEST
        {"",""}, // KEY
        {""}, // PERMANENT
        {"","","","","",""}, // MISCELLANEOUS
        {"","","","","","","","","","","",""} // GLYPH
    };

    QVector<QVector<QString>> STR_SUBCLASS_RIGHT = {
        {"","","","","","","","",""}, // CONSUMABLE
        {"","","","","","","","",""}, // BAG
        { // WEAPON
            "Hache",
            "Hache",
            "Arc",
            "Fusil",
            "Masse",
            "Masse",
            "Arme d'hast",
            "Epée",
            "Epée",
            "",
            "Bâton",
            "",
            "",
            "Arme de pugilat",
            "Divers",
            "Dague",
            "Arme de jet",
            "Arme de jet",
            "Arbalète",
            "Baguette",
            "Canne à pêche"
        },
        {"","","","","","","","",""}, // GEM
        { // ARMOR
            "Divers",
            "Armures en tissu",
            "Armures en cuir",
            "Armures en mailles",
            "Armures en plaques",
            "Bouclier",
            "Bouclier",
            "Libram",
            "Idole",
            "Totem",
            "Sigil"
        },
        {""}, // REAGENT
        {"","","","",""}, // PROJECTILE
        {"","","","","","","","","","","","","","","",""}, // TRADE_GOODS
        {""}, // GENERIC
        {"","","","","","","","","","",""}, // RECIPE
        {""}, // MONEY
        {"","","",""}, // QUIVER
        {""}, // QUEST
        {"",""}, // KEY
        {""}, // PERMANENT
        {"","","","","",""}, // MISCELLANEOUS
        {"","","","","","","","","","","",""} // GLYPH
    };

    QVector<QString> STR_STAT = {
        " +%1 Mana",
        " +%1 Vie",
        "STAT_TYPE_2_NONE",
        " +%1 Agilité",
        " +%1 Force",
        " +%1 Intelligence",
        " +%1 Esprit",
        " +%1 Endurance",
        "STAT_TYPE_8_NONE",
        "STAT_TYPE_9_NONE",
        "STAT_TYPE_10_NONE",
        "STAT_TYPE_11_NONE",
        "Equipé : Augmente ITEM_MOD_DEFENSE_SKILL_RATING +%1",
        "Equipé : Augmente ITEM_MOD_DODGE_RATING +%1",
        "Equipé : Augmente ITEM_MOD_PARRY_RATING +%1",
        "Equipé : Augmente ITEM_MOD_BLOCK_RATING +%1",
        "Equipé : Augmente ITEM_MOD_HIT_MELEE_RATING +%1",
        "Equipé : Augmente ITEM_MOD_HIT_RANGED_RATING +%1",
        "Equipé : Augmente ITEM_MOD_HIT_SPELL_RATING +%1",
        "Equipé : Augmente votre score de coup critique de +%1",
        "Equipé : Augmente ITEM_MOD_CRIT_RANGED_RATING +%1",
        "Equipé : Augmente ITEM_MOD_CRIT_SPELL_RATING +%1",
        "Equipé : Augmente ITEM_MOD_HIT_TAKEN_MELEE_RATING +%1",
        "Equipé : Augmente ITEM_MOD_HIT_TAKEN_RANGED_RATING +%1",
        "Equipé : Augmente ITEM_MOD_HIT_TAKEN_SPELL_RATING +%1",
        "Equipé : Augmente ITEM_MOD_CRIT_TAKEN_MELEE_RATING +%1",
        "Equipé : Augmente ITEM_MOD_CRIT_TAKEN_RANGED_RATING +%1",
        "Equipé : Augmente ITEM_MOD_CRIT_TAKEN_SPELL_RATING +%1",
        "Equipé : Augmente votre score de hâte de +%1",
        "Equipé : Augmente ITEM_MOD_HASTE_RANGED_RATING +%1",
        "Equipé : Augmente ITEM_MOD_HASTE_SPELL_RATING +%1",
        "Equipé : Augmente ITEM_MOD_HIT_RATING +%1",
        "Equipé : Augmente ITEM_MOD_CRIT_RATING +%1",
        "Equipé : Augmente ITEM_MOD_HIT_TAKEN_RATING +%1",
        "Equipé : Augmente ITEM_MOD_CRIT_TAKEN_RATING +%1",
        "Equipé : Augmente ITEM_MOD_RESILIENCE_RATING +%1",
        "Equipé : Augmente votre score de hâte de +%1",
        "Equipé : Augmente ITEM_MOD_EXPERTISE_RATING +%1",
        "Equipé : Augmente la puissance d'attaque de +%1",
        "Equipé : Augmente ITEM_MOD_RANGED_ATTACK_POWER +%1",
        "Equipé : Augmente ITEM_MOD_FERAL_ATTACK_POWER +%1",
        "Equipé : Augmente ITEM_MOD_SPELL_HEALING_DONE +%1",
        "Equipé : Augmente ITEM_MOD_SPELL_DAMAGE_DONE +%1",
        "Equipé : Augmente ITEM_MOD_MANA_REGENERATION +%1",
        "Equipé : Augmente ITEM_MOD_ARMOR_PENETRATION_RATING +%1",
        "Equipé : Augmente la puissance des sorts de +%1",
        "Equipé : Augmente ITEM_MOD_HEALTH_REGEN +%1",
        "Equipé : Augmente ITEM_MOD_SPELL_PENETRATION +%1",
        "Equipé : Augmente ITEM_MOD_BLOCK_VALUE +%1"
    };

    const QString STR_RES [6] = {
        QString("+%1 Résistance au Sacré"),
        QString("+%1 Résistance au Feu"),
        QString("+%1 Résistance à la Nature"),
        QString("+%1 Résistance au Givre"),
        QString("+%1 Résistance à l'Ombre"),
        QString("+%1 Résistance aux Arcanes")
    };

    const QString STR_SOCKET [4] = {
        "%1 Châsse prismatic",
        "%1 Châsse rouge",
        "%1 Châsse jaune",
        "%1 Châsse bleu"
    };

    const QString STR_BOUND [6] = {
        "",
        "Lié quand ramassé",
        "Lié quand équipé",
        "Bind when used",
        "Quest_item",
        "Quest_item1"
    };

    const QString STR_PLAYER_CLASS_BASE = QString("Classe : %1");
    const QString STR_PLAYER_CLASS [12] = {
        "",
        QString("<span style=\"color:#C69B6D;\">%1</span>").arg("Guerrier"),
        QString("<span style=\"color:#F48CBA;\">%1</span>").arg("Paladin"),
        QString("<span style=\"color:#AAD372;\">%1</span>").arg("Chasseur"),
        QString("<span style=\"color:#FFF468;\">%1</span>").arg("Voleur"),
        QString("<span style=\"color:#FFFFFF;\">%1</span>").arg("Prêtre"),
        QString("<span style=\"color:#C41E3B;\">%1</span>").arg("Chevalier de la mort"),
        QString("<span style=\"color:#2359FF;\">%1</span>").arg("Chaman"),
        QString("<span style=\"color:#68CCEF;\">%1</span>").arg("Mage"),
        QString("<span style=\"color:#9382C9;\">%1</span>").arg("Démoniste"),
        "",
        QString("<span style=\"color:#FF7C0A;\">%1</span>").arg("Druide")
    };

    //CONST
        const int OFFSET_SLOT_Y = 24;
        const QString POLICY = "Verdana";

        // MAX_STAT
        const int MAX_STAT = 10;
        // QUALITY TYPE
        const QString QUALITY [9] = {
            "#9D9D9D",
            "#FFFFFF",
            "#1EFF00",
            "#0070DD",
            "#A335EE",
            "#FF8000",
            "#E5CC80",
            "#E5CC80",
            "#FFD100"
        };
        // ASSET
            //background
            const QPixmap background = QPixmap(":/asset/asset/background/tooltip.png");
            const QString backgroundColor = "#23313f";

            //money
            const QString MONEY [3] = {
                QString("<img src=\":/asset/asset/money/money-copper.gif\"/>"),
                QString("<img src=\":/asset/asset/money/money-silver.gif\"/>"),
                QString("<img src=\":/asset/asset/money/money-gold.gif\"/>")
            };
            //socket
            const QString SOCKET [4] = {
                QString("<img src=\":/asset/asset/socket/socket-prismatic.gif\"/>"),
                QString("<img src=\":/asset/asset/socket/socket-red.gif\"/>"),
                QString("<img src=\":/asset/asset/socket/socket-yellow.gif\"/>"),
                QString("<img src=\":/asset/asset/socket/socket-blue.gif\"/>")
            };
};

#endif // TOOLTIPITEM_H
