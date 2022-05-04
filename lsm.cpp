#include "lsm.h"
#include <zconf.h>

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
    int log_pos = -1;
    for (int i = 0; i < log_position*(KEY_SIZE/8+OFFSET_SIZE); i += KEY_SIZE / 8 + OFFSET_SIZE) {
        for (int byte = 0; byte < KEY_SIZE / 8; byte++) {
            if (log[i + byte] != key[byte]) {
                break;
            }
            if (byte + 1 == KEY_SIZE / 8) {
                log_pos = i;
            }
        }
    }
    if(log_pos>=0)return read_value(log + log_pos + KEY_SIZE / 8);
    return nullptr;//TODO find in sstables
}

lsm::lsm(const std::string &path) {
    data = fopen(path.c_str(), "rw+");
    if (!data) {
        perror("can't open file");
    }
    log = new char[LOG_SIZE*(KEY_SIZE+OFFSET_SIZE)];
}

lsm::~lsm() {
    if (data) {
        fclose(data);
    }
}
char *lsm::write_value(const char *value) {//need to be changed when offset is not int
    if(write(fileno(data), value, VALUE_SIZE)!= VALUE_SIZE){
        perror("can't write value");
    }
    fflush(data);
    uint32_t offset = file_end;
    file_end+=VALUE_SIZE;
    char *res = new char[4]{(char)(offset>>24), (char)((offset<<8)>>24), (char)((offset<<16)>>24), (char)((offset<<24)>>24)};
    return res;
}
char *lsm::read_value(const char *offset) {
    int32_t off = 0;
    for(int i = 0; i < OFFSET_SIZE;i++){
        off<<=8;
        off+=offset[i];
    }
    if(fseek(data, off, SEEK_SET)){
        perror("can't read from disk");
    }
    char* value = new char[VALUE_SIZE+1];

    if(fgets(value, VALUE_SIZE+1, data) == NULL){
        perror("can't read data");
    }
    if(fseek(data, 0, SEEK_END)){
        perror("can't read from disk");
    }
    return value;
}
