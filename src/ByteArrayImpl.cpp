#include "ByteArrayImpl.h"
#include <cstdint>
char *ByteArray2::read_value(const char *offset, const size_t offset_size, const size_t value_size) {

    char *value = new char[value_size + 1];
    uint32_t off = 0;
    for (int i = 0; i < offset_size; i++) {
        off <<= 8u;
        off += offset[i];
    }
    for (int i = 0; i < value_size; i++) {
        value[i] = data[i + off];
    }
    return value;
}
char *ByteArray2::write_value(Value value) {
    uint32_t offset = data.size();
    for (int i = 0; i < value.getSize(); i++) {
        data.push_back(value.getValue()[i]);
    }
    char *res = new char[4]{(char) (offset >> 24u), (char) ((offset << 8u) >> 24u), (char) ((offset << 16u) >> 24u), (char) ((offset << 24u) >> 24u)};
    return res;
}
