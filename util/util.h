#ifndef UTIL
#define UTIL

#include <vector>
#include <iostream>
using namespace std;

// ---- METHODS DEFINITION ----
template <typename T>
void displayVector(vector<T> input);
vector<string> split(string s, string delim);

// ---- METHODS IMPLEMENTATION ----
template <typename T>
void displayVector(vector<T> input) {
    for (auto i: input) {
        cout << i << " ";
    }
    cout << endl;
}

vector<string> split(string s, string delim) {
    vector<string> result;
    int pos = s.find(delim);
    while (pos != -1) {
       string token = s.substr(0, pos);
       result.push_back(token);
       s = s.substr(pos + 1);
       pos = s.find(delim);
    }
    result.push_back(s);
    return result;
}


#endif
