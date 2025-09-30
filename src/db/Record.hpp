// Definition of the data record (struct/class with attributes).  
#pragma once
#include <stdio.h>
#include <bits/stdc++.h>

using std::string;
using std::vector;


class Record {
public:
    int id{};
    string name;
    int age{};
    vector<string> interests;

    Record() = default;

    Record(int id, const string& name, int age, const vector<string>& interests = {})
        : id(id), name(name), age(age), interests(interests) {}
};
