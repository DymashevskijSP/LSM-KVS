#include "doctest.h"
#include "lsm.h"
#include <cstdio>
#include <cstdlib>
#include <time.h>

char* generate_value(int size, char byte){
    char* res= new char[size];
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        res[i] = byte;

    }
    return res;
}

TEST_CASE("initial"){
     lsm::lsm db("/home/megaserg01/Soft/LSM-KVS/db.file");
    for(int i = 0; i < 26;i++){
        char* nkey = generate_value(lsm::KEY_SIZE, 'a'+i%26);
        CHECK(!db.find(Key(nkey, lsm::KEY_SIZE)).has_value());
        char* nvalue = generate_value(lsm::VALUE_SIZE, 'b');
        db.add(KeyValue(nkey, lsm::KEY_SIZE, nvalue, lsm::VALUE_SIZE));
        std::optional<Value> value = db.find(Key(nkey, lsm::KEY_SIZE));
        CHECK(value.value().getSize() == lsm::VALUE_SIZE);
        const char* res = value.value().getValue();
        for(int j = 0; j< lsm::VALUE_SIZE;j++){
            CHECK( res[j] == nvalue[j]);
        }
    }
}
