// Definition of the database interface (class with methods to interact with the data store).  
#pragma once
#include <unordered_map>
#include "Record.hpp"

using std::string;
using std::unordered_map;

class InMemoryDB {
    unordered_map<string, UserRecord> store;

public:
    void put(const string& key, const UserRecord& record);
    UserRecord* get(const string& key);
    void remove(const string& key);
    bool checkIfExists(const string& key);
};
