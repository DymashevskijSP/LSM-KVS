#ifndef LSM_KVS_LSM_H
#define LSM_KVS_LSM_H

#include <cstdio>
#include <string>
#include <bitset>
#include <optional>
#include "ByteArray.h"
#include "log.h"
#include "KeyValue.h"


struct lsm {
public:
    static const int KEY_SIZE = 8;//in bits
    static const int VALUE_SIZE = 2;//in bytes
    static const int LOG_SIZE = 1000;

    static const int OFFSET_SIZE = 4;/*TODO change to offset size, now it's int size*/
    explicit lsm(const std::string &path);

    void add(KeyValue kv);

    std::optional<Value> find(Key k);

private:
    ByteArray print_writer;
    log lsm_log;
};



template<int size>
struct filter {
public:
    std::bitset<size> bits;
    bool contains() {
        return true;
    }
};


#endif //LSM_KVS_LSM_H
