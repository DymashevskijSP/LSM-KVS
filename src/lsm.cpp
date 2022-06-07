#include "lsm.h"

namespace lsm {
    void lsm::add(KeyValue kv) {
        char *offset = print_writer.write_value(kv.getValue());//write to file and get offset
        int code = lsm_log.add(kv.getKey(), offset);
        if (code == log_errors::LOG_OVERFLOW) {
            //TODO
        }
    }

    std::optional<Value> lsm::find(Key key) {
        char *offset = new char[OFFSET_SIZE];
        std::optional<Value> res = std::optional<Value>();
        if (lsm_log.find_offset(key, offset) == log_errors::SUCCESS) {
            char *ans = print_writer.read_value(offset, OFFSET_SIZE, VALUE_SIZE);
            res.emplace(ans, VALUE_SIZE);
            return res;
        }
        return res;//TODO find in sstables
    }

    lsm::lsm(const std::string &path) : print_writer(/*path*/), lsm_log(log(LOG_SIZE, KEY_SIZE, OFFSET_SIZE)) {
    }

}


