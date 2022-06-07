#include "log.h"
log::log(size_t log_size_, size_t key_size_, size_t offset_size_):log_size(log_size_), key_size(key_size_), offset_size(offset_size_) {
    log_bytes = new char[log_size_ * (key_size + offset_size)];
}

log_errors log::add(Key k, const char* offset){
    if (log_position + k.getSize() / 8 + offset_size < log_size) {
        for (int i = 0; i < k.getSize() / 8; i++) {
            log_bytes[i + log_position] = k.getKey()[i];
        }
        log_position += k.getSize() / 8;
        for (size_t i = 0; i < offset_size; i++) {
            log_bytes[log_position + i] = offset[i];
        }
        log_position += offset_size;
        return log_errors::SUCCESS;
    }
    return log_errors::LOG_OVERFLOW;
}
int log::find_offset(Key key, char *offset) {
    int log_pos = -1;
    for (size_t i = 0; i < log_position * (key_size / 8 + offset_size); i += key_size / 8 + offset_size) {
        for (int byte = 0; byte < key_size / 8; byte++) {
            if (log_bytes[i + byte] != key.getKey()[byte]) {
                break;
            }
            if (byte + 1 == key_size / 8) {
                log_pos = i;
            }
        }
    }
    if(log_pos == -1){
        return log_errors::NOT_FOUND;
    }
    for(int i = 0; i < offset_size;i++){
        offset[i] = log_bytes[log_pos+key_size/8+i];
    }
    return log_errors::SUCCESS;
}
