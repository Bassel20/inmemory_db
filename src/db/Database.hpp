#pragma once
#include <unordered_map>
#include "Record.hpp"

using std::string;
using std::unordered_map;

class InMemoryDB {
    unordered_map<string, Record> store;

public:
    void put(const string& key, const Record& record) {
        store[key] = record;
    }

    Record* get(const string& key) {
        auto it = store.find(key);
        return it != store.end() ? &it->second : nullptr;
    }

    void remove(const string& key) {
        store.erase(key);
    }
};
