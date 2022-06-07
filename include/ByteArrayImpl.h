#ifndef KVS_BYTEARRAYIMPL_H
#define KVS_BYTEARRAYIMPL_H
#include <vector>
#include "KeyValue.h"
struct ByteArray2 {
    std::vector<char> data;

    char *read_value(const char *offset, const size_t offset_size, const size_t value_size);
    char *write_value(Value value);
};
#endif//KVS_BYTEARRAYIMPL_H
