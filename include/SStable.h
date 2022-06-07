#ifndef KVS_SSTABLE_H
#define KVS_SSTABLE_H
#include "ByteArray.h"
#include "log.h"
#include <map>
#include <optional>
class SSTable {
public:
    std::optional<char*> find(Key key);
    void merge(char *lsm_log, int key_size, int offset_size, int log_size);
private:
    int size = 0;
    std::map<std::string , char*> data;//TODO change
};

#endif//KVS_SSTABLE_H
