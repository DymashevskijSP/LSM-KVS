//
// Created by megaserg01 on 29.05.2022.
//

#ifndef LSM_KVS_BYTEARRAY_H
#define LSM_KVS_BYTEARRAY_H
#include <cstdio>
#include <string>
#include "KeyValue.h"
struct ByteArray{
public:
    explicit ByteArray(const std::string& path);
    char* write_value(Value value);
    char* read_value(const char* offset, size_t offset_size, size_t value_size);
private:
    FILE *data;
    int file_end = 0;
};
#endif//LSM_KVS_BYTEARRAY_H
