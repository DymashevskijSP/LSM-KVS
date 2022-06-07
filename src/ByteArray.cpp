#include "ByteArray.h"
#include <zconf.h>
ByteArray::ByteArray(const std::string &path) {
    data = fopen(path.c_str(), "rw+");
    if (!data) {
        perror("can't open file");
    }
}

char *ByteArray::read_value(const char *offset, const size_t offset_size, const size_t value_size) {
    uint32_t off = 0;
    for (int i = 0; i < offset_size; i++) {
        off <<= 8u;
        off += offset[i];
    }
    if (fseek(data, off, SEEK_SET)) {
        perror("can't read from disk");
    }
    char *value = new char[value_size + 1];

    if (fgets(value, value_size + 1, data) == NULL) {
        perror("can't read data");
    }
    if (fseek(data, 0, SEEK_END)) {
        perror("can't read from disk");
    }
    return value;
}


char *ByteArray::write_value(Value value) {
    if (write(fileno(data), value.getValue(), value.getSize()) != value.getSize()) {
        perror("can't write value");
    }
    fflush(data);
    uint32_t offset = file_end;//TODO change from int to byte array
    file_end += value.getSize();
    char *res = new char[4]{(char) (offset >> 24u), (char) ((offset << 8u) >> 24u), (char) ((offset << 16u) >> 24u), (char) ((offset << 24u) >> 24u)};
    return res;
}