#include "spell_item_enchantment_reader.h"
#include <sstream>
#include <iostream>

spell_item_enchantment_reader::spell_item_enchantment_reader(QString file, int lang) {

    // prevent lang out of range
    if (lang < LANG_enUS or lang > LANG_UNK){
        delete this;
        return;
    }

    // set lang file
    LANG=lang;

    // only read SpellItemEnchantment.dbc
    if (not file.contains("SpellItemEnchantment")) {
        delete this;
        return;
    }

    this->setFileName(file);
    this->open(QIODevice::ReadOnly);

    buffer = readAll();

    // header
    magic             = buffer.mid(0,LENGTH);
    record_count      = ValueFrom(LENGTH*1);
    field_count       = ValueFrom(LENGTH*2);
    record_size       = ValueFrom(LENGTH*3);
    string_block_size = ValueFrom(LENGTH*4);

    GenerateStrSort();

    // only read dbc file
    if (magic.toStdString() != "WDBC")
        delete this;
}

QString spell_item_enchantment_reader::reverseHex(QByteArray bytes) {
    QString reverse;
    QString hex [4];

    for (int i = 0; i < 4; i ++)
        hex[i] = QString("%1%2").arg(bytes.toHex()[0+(2*i)]).arg(bytes.toHex()[1+(2*i)]);

    for (int i = 3 ; i >= 0 ; i -- )
        reverse.push_back(hex[i]);

    return reverse;
}

void spell_item_enchantment_reader::GenerateStrSort() {
    quint32 pos;

    for (quint32 i = 0; i < record_count ; i ++) {
        pos = HEADER_SIZE + (i*record_size) + (LENGTH*LANG);

        if (not str_sort.contains(ValueFrom(pos)))
            str_sort << ValueFrom(pos);
    }

    std::sort(str_sort.begin(), str_sort.end());
}

quint32 spell_item_enchantment_reader::searchRecordByID(quint32 valueToFound) {
    quint32 record = 0;
    quint32 position;

    for (quint32 i = 0 ; i < record_count ; i++) {
        position = HEADER_SIZE + (i*record_size);

        if (valueToFound == ValueFrom(position))
            return i;
    }

    return record;
}

quint32 spell_item_enchantment_reader::ValueFrom(quint32 pos) {
    if (pos > (record_count*record_size+HEADER_SIZE)) return 0; //data out of range

    return strHexToUint32(reverseHex(buffer.mid(pos,LENGTH)));
}

quint32 spell_item_enchantment_reader::ValueWhere(quint32 record, quint32 field) {
    if (record > record_count or field > field_count) return 0; //data out of range

    return ValueFrom(HEADER_SIZE + (record*record_size) + (LENGTH*field));
}

QVector<quint32> spell_item_enchantment_reader::getStatKey(quint32 record) {
    quint32 position = HEADER_SIZE + (record*record_size) + (LENGTH*SPELL_DISPEL_TYPE_1);
    QVector<quint32> toReturn;

    for (int i = 0; i <= (SPELL_DISPEL_TYPE_3-SPELL_DISPEL_TYPE_1); i++) {
        toReturn.push_back(ValueFrom(position));
        position+=LENGTH;
    }

    return toReturn;
}

QVector<quint32> spell_item_enchantment_reader::getStatType(quint32 record) {
    quint32 position = HEADER_SIZE + (record*record_size) + (LENGTH*OBJECT_ID_1);
    QVector<quint32> toReturn;

    for (int i = 0; i <= (OBJECT_ID_3-OBJECT_ID_1); i ++) {
        toReturn.push_back(ValueFrom(position));
        position+=LENGTH;
    }

    return toReturn;
}

QVector<QVector<quint32> > spell_item_enchantment_reader::getStatValue(quint32 record) {
    quint32 position = HEADER_SIZE + (record*record_size) + (LENGTH*MIN_AMOUNT_1);
    QVector<QVector<quint32>> toReturn;
        QVector<quint32> subArray;

        for (int i = 0; i <= (MIN_AMOUNT_3-MIN_AMOUNT_1); i ++) {
            subArray = {ValueFrom(position), ValueFrom((position+LENGTH*3))};
            toReturn.push_back(subArray);
            position+=LENGTH;
        }

        return toReturn;
}

QString spell_item_enchantment_reader::getText(quint32 record) {
    quint32 position_start = HEADER_SIZE + (record*record_size) + (LENGTH*LANG);
    quint32 data_position_start = ValueFrom(position_start);
    quint32 str_lenght;

    quint32 str_at = str_sort.indexOf(data_position_start);
    quint32 str_to = (str_at == str_sort.count()) ? String_Block_Size() : str_sort[str_at+1];
    str_to--;

    str_lenght = str_to - str_sort[str_at];

    return buffer.mid(StringBlockStart()+ValueFrom(position_start), str_lenght);
}
