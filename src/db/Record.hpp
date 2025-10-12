// Definition of the data record (struct/class with attributes).  
#pragma once
#include <stdio.h>
#include <bits/stdc++.h>

using std::string;
using std::vector;


class UserRecord {
public:
    int id{};
    string name;
    int age{};
    vector<string> interests;

    UserRecord() = default;

    UserRecord(int id, const string& name, int age, const vector<string>& interests = {})
        : id(id), name(name), age(age), interests(interests) {}
};
