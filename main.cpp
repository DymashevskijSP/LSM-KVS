#include <iostream>
#include "lsm.h"

char* generate_value(int size, char byte){
    char* res= new char[size];
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        res[i] = byte;
        printf("%c", res[i]);
    }
    printf("\n");
    return res;
}

int main() {
    lsm db("/home/megaserg01/Soft/LSM-KVS/db.file");
    printf("key: ");
    char* key = generate_value(lsm::KEY_SIZE/8, 'x');
    printf("value1: ");
    char* value = generate_value(lsm::VALUE_SIZE, 'a');
    db.add(key, value);
    char* res = db.find(key);
    printf("result1: ");
    for(int i = 0; i < lsm::VALUE_SIZE;i++){
        printf("%c", res[i]);
    }
    printf("\nvalue2: ");
    value = generate_value(lsm::VALUE_SIZE, 'b');
    db.add(key, value);
    res = db.find(key);
    printf("result2: ");
    for(int i = 0; i < lsm::VALUE_SIZE;i++){
        printf("%c", res[i]);
    }
    return 0;
}
