#include "Database.hpp"
#include<iostream>

using std::string;

void InMemoryDB::put(const string& key, const UserRecord& record) {
    store[key] = record;
}

UserRecord* InMemoryDB::get(const string& key) {
    auto it = store.find(key);
    return it != store.end() ? &it->second : nullptr;
}

void InMemoryDB::remove(const string& key) {
    std::cout << "Removing key '" << key << "\n";
    store.erase(key);
}

bool InMemoryDB::checkIfExists(const string& key) {
    auto it = store.find(key);
    if (it != store.end()) {
        return true;
        std::cout << "Record with key '" << key << "' exists.\n";
    } else {
        std::cout << "Record with key '" << key << "' does not exist.\n";
        return false;
    }
}

