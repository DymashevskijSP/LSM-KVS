//
// Created by megaserg01 on 04.05.2022.
//

#include "lsm.h"

void lsm::add(const char *key, const char *value) {
    char *offset = write_value(value);//write to file and get offset
    if (log_position + KEY_SIZE / 8 + OFFSET_SIZE < LOG_SIZE) {
        for (int i = 0; i < KEY_SIZE / 8; i++) {
            log[i + log_position] = key[i];
        }
        log_position += KEY_SIZE / 8;
        for (size_t i = 0; i < OFFSET_SIZE; i++) {
            log[log_position + i] = offset[i];
        }
        log_position += OFFSET_SIZE;
    }
}

char *lsm::find(const char *key) {
    for (int i = 0; i < log_position; i += KEY_SIZE / 8 + OFFSET_SIZE) {
        for (int byte = 0; byte < KEY_SIZE / 8; byte++) {
            if (log[i + byte] != key[byte]) {
                break;
            }
            if (byte + 1 == KEY_SIZE / 8) {
                return read_value(log + i + KEY_SIZE / 8);
            }
        }
    }
    return nullptr;//TODO find in sstables
}

lsm::lsm(const std::string &path) {
    data = fopen(path.c_str(), "rw+");
    if (!data) {
        perror("can't open file");
    }
}

lsm::~lsm() {
    if (data) {
        fclose(data);
    }
}
char *lsm::write_value(const char *value) {
    char *res = new char[4]{0, 0, 0, 0};
    return res;
}
char *lsm::read_value(const char *offset) {
    return new char[VALUE_SIZE];
}
