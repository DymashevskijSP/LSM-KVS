#include "SStable.h"
std::optional<char*> SSTable::find(Key key) {
    std::optional<char*> value;
    if(data.find(std::string(key.getKey())) == data.end()){
        std::string res = data[std::string(key.getKey())];
        value.emplace(res.data());
    }
    return value;
}

void SSTable::merge(char* lsm_log, int key_size, int offset_size, int log_size ) {
    //TODO
}
