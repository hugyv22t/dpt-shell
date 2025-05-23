//
// Created by luoyesiqiu
//

#include "MultiDexCode.h"

dpt::data::MultiDexCode* dpt::data::MultiDexCode::getInst(){
    static auto *m_inst = new MultiDexCode();
    return m_inst;
}

void dpt::data::MultiDexCode::init(uint8_t* buffer, size_t size){
    this->m_buffer = buffer;
    this->m_size = size;
}

uint16_t dpt::data::MultiDexCode::readVersion(){
    return readUInt16(0);
}

uint16_t dpt::data::MultiDexCode::readDexCount(){
    return readUInt16(2);
}

uint32_t* dpt::data::MultiDexCode::readDexCodeIndex(int* count){
    uint16_t dexCount = readDexCount();
    *count = dexCount;
    return (uint32_t*)(m_buffer + 4);
}

dpt::data::CodeItem* dpt::data::MultiDexCode::nextCodeItem(uint32_t* offset) {
    uint32_t methodIdx = readUInt32(*offset);
    uint32_t insnsSize = readUInt32(*offset + 4);
    auto* insns = (uint8_t*)(m_buffer + *offset + 8);
    *offset = (*offset + 8 + insnsSize);
    auto* codeItem = new CodeItem(methodIdx, insnsSize, insns);

    return codeItem;
}

uint8_t dpt::data::MultiDexCode::readUInt8(uint32_t offset){
    uint8_t t = 0;
    memcpy(&t, m_buffer + offset, sizeof(uint8_t));
    return t;
}

uint16_t dpt::data::MultiDexCode::readUInt16(uint32_t offset){
    uint16_t t = 0;
    memcpy(&t, m_buffer + offset, sizeof(uint16_t));
    return t;
}

uint32_t dpt::data::MultiDexCode::readUInt32(uint32_t offset){
    uint32_t t = 0;
    memcpy(&t, m_buffer + offset, sizeof(uint32_t));
    return t;
}