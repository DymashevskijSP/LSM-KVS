#ifndef LSM_KVS_LSM_H
#define LSM_KVS_LSM_H

#include <cstdio>
#include <string>
#include <bitset>

struct lsm {
public:
    static const int KEY_SIZE = 8;//in bits
    static const int VALUE_SIZE = 2;//in bytes
    static const int LOG_SIZE = 1000;

    static const int OFFSET_SIZE = 4;/*TODO change to offset size, now it's int size*/
    explicit lsm(const std::string &path);

    void add(const char *key,const char *value);

    char *find(const char *key);

    ~lsm();

private:
    char* write_value(const char* value);
    char* read_value(const char* offset);
    FILE *data;
    int file_end = 0;
    char* log;
    int log_position = 0;


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
