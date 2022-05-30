#include "../include/KeyValue.h"
KeyValue::KeyValue(const char *key_, size_t key_size, const char *value_, size_t value_size) : key(Key(key_, key_size)), value(value_, value_size) {
}
Key KeyValue::getKey() const {
    return key;
}
Value KeyValue::getValue() const {
    return value;
}
Value::Value(const char *value_, size_t size_) : value(value_), size(size_) {
}
const char *Value::getValue() const {
    return value;
}
size_t Value::getSize() const {
    return size;
}
size_t Key::getSize() const {
    return size;
}
const char *Key::getKey() const {
    return key;
}
Key::Key(const char *value, size_t size_) : key(value), size(size_) {
}