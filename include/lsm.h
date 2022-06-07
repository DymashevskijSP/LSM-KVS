#ifndef LSM_KVS_LSM_H
#define LSM_KVS_LSM_H

#include "ByteArray.h"
#include "ByteArrayImpl.h"
#include "KeyValue.h"
#include "log.h"
#include <bitset>
#include <cstdio>
#include <optional>
#include <string>

namespace lsm {

    static const int KEY_SIZE = 8;  //in bits
    static const int VALUE_SIZE = 2048;//in bytes
    static const int LOG_SIZE = 1000;
    static const int OFFSET_SIZE = 4; /*TODO change to offset size, now it's int size*/
    struct lsm {
    public:
        explicit lsm(const std::string &path);
        void add(KeyValue kv);

        std::optional<Value> find(Key k);

    private:
        ByteArray2 print_writer;
        log lsm_log;
    };

}// namespace lsm

template<int size>
struct filter {
public:
    std::bitset<size> bits;
    bool contains() {
        return true;
    }
};


#endif//LSM_KVS_LSM_H
