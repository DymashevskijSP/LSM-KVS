//#include "include/lsm.h"

#include <cstdio>
#include <cstdlib>
#include <time.h>
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
    printf("hello");
    fflush(stdout);
//    lsm db("/home/megaserg01/Soft/LSM-KVS/db.file");
//    printf("key: ");
//    char* key = generate_value(lsm::KEY_SIZE/8, 'x');
//    printf("value1: ");
//    char* value = generate_value(lsm::VALUE_SIZE, 'a');
//    db.add(KeyValue(key, lsm::KEY_SIZE, value, lsm::VALUE_SIZE));
//    std::optional<Value> res = db.find(Key(key, lsm::KEY_SIZE));
//    printf("result1: ");
//    for(int i = 0; i < lsm::VALUE_SIZE;i++){
//        printf("%c", res.value().getValue()[i]);
//    }
//    printf("\nvalue2: ");
//    value = generate_value(lsm::VALUE_SIZE, 'b');
//    db.add(KeyValue(key, lsm::KEY_SIZE, value, lsm::VALUE_SIZE));
//    std::optional<Value> res2 = db.find(Key(key, lsm::KEY_SIZE));
//    printf("result2: ");
//    for(int i = 0; i < lsm::VALUE_SIZE;i++){
//        printf("%c", res2.value().getValue()[i]);
//    }
    return 0;
}
