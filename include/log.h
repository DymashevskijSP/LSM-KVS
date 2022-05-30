#ifndef LSM_KVS_LOG_H
#define LSM_KVS_LOG_H

#include <cstdlib>
#include "KeyValue.h"
enum log_errors{
    SUCCESS = 0,
    LOG_OVERFLOW = 1,
    NOT_FOUND = 2
};
struct log{
public:

    log(size_t log_size_, size_t key_size, size_t offset);
    log_errors add(Key k, const char* offset);
    int find_offset(Key key, char* offset);

private:
    const size_t key_size;
    const size_t offset_size;
    char* log_bytes;
    const size_t log_size;
    size_t log_position = 0;

};

#endif//LSM_KVS_LOG_H
