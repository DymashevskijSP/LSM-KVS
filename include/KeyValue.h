#ifndef LSM_KVS_KEYVALUE_H
#define LSM_KVS_KEYVALUE_H
#include <cstdio>
class Key {
public:
    Key(const char * value, size_t size);
    [[nodiscard]] const char* getKey() const;
    [[nodiscard]] size_t getSize() const;
private:
    const char* key;
    const size_t size;
};

class Value {
public:
    Value(const char * value, size_t size);
    [[nodiscard]] const char* getValue() const;
    [[nodiscard]] size_t getSize() const;
private:
    const char* value;
    const size_t size;
};

class KeyValue {
public:
    KeyValue(const char * key, size_t key_size, const char * value, size_t value_size);
    [[nodiscard]] Key getKey() const;
    [[nodiscard]] Value getValue() const;
private:
    const Value value;
    const Key key;
};


#endif//LSM_KVS_KEYVALUE_H
