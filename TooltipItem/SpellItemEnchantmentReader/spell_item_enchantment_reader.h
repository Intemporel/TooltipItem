#ifndef SPELL_ITEM_ENCHANTMENT_READER_H
#define SPELL_ITEM_ENCHANTMENT_READER_H

#include <QFile>
#include <QList>
#include <QDebug>
#include <QByteArray>
#include <algorithm>

enum STRUCT_SPELL_ITEM_ENCHANTMENT_READER {
    ID,
    CHARGES,
    SPELL_DISPEL_TYPE_1, // if SPELL_DISPEL_TYPE = 5 then OBJECT_ID is STAT_TYPE else SPELL_ID
    SPELL_DISPEL_TYPE_2, // if SPELL_DISPEL_TYPE = 5 then OBJECT_ID is STAT_TYPE else SPELL_ID
    SPELL_DISPEL_TYPE_3, // if SPELL_DISPEL_TYPE = 5 then OBJECT_ID is STAT_TYPE else SPELL_ID
    MIN_AMOUNT_1,
    MIN_AMOUNT_2,
    MIN_AMOUNT_3,
    MAX_AMOUNT_1,
    MAX_AMOUNT_2,
    MAX_AMOUNT_3,
    OBJECT_ID_1,
    OBJECT_ID_2,
    OBJECT_ID_3,
    LANG_enUS,
    LANG_enGB,
    LANG_koKR,
    LANG_frFR,
    LANG_deDE,
    LANG_enCN,
    LANG_zhCN,
    LANG_enTW,
    LANG_zhTW,
    LANG_esES,
    LANG_esMX,
    LANG_ruRU,
    LANG_ptPT,
    LANG_ptBR,
    LANG_itIT,
    LANG_UNK,
    LANG_MASK,
    ITEM_VISUAL,
    FLAGS,
    ITEM_CACHE,
    SPELL_ITEM_ENCHANTMENT_CONDITION,
    SKILL_LINE,
    SKILL_LEVEL,
    REQUIRED_LEVEL
};

typedef enum STRUCT_SPELL_ITEM_ENCHANTMENT_READER SpellItemEnchantmentStructure;

class spell_item_enchantment_reader : public QFile {
public:
    spell_item_enchantment_reader(QString, int lang=LANG_enUS);

    QString Magic() { return magic; };
    quint32 Record_Count() { return record_count; };
    quint32 Field_Count() { return field_count; };
    quint32 Record_Size() { return record_size; };
    quint32 String_Block_Size() { return string_block_size; };
    quint32 StringBlockStart() { return (size() - String_Block_Size()); };

    quint32 searchRecordByID(quint32);
    quint32 ValueFrom(quint32);
    quint32 ValueWhere(quint32, quint32);
    QVector<quint32> getStatKey(quint32);
    QVector<quint32> getStatType(quint32);
    QVector<QVector<quint32>> getStatValue(quint32);
    QString getText(quint32);

private:
    void GenerateStrSort();
    QString reverseHex(QByteArray);
    quint32 strHexToUint32(QString hex) { return hex.toUInt(&ok, 16); };

    QByteArray * file;
    QList<quint32> str_sort;
    QByteArray buffer;
    int LANG;
    bool ok = false;

    // HEADER
    QString magic;
    quint32 record_count;
    quint32 field_count;
    quint32 record_size;
    quint32 string_block_size;

    const int HEADER_SIZE = 20;
    const int LENGTH = 4;
};

#endif // SPELL_ITEM_ENCHANTMENT_READER_H
