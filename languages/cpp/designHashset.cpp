#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

#define hashSetSize 100
class MyHashSet {
private:
    vector<list<int>> store;
    int size = hashSetSize;
public:
    MyHashSet();
    void add(int key);
    void remove(int key);
    bool contains(int key);
    int getHash(int key);
    list<int>::iterator search(int key);

};

int main(void) {
    MyHashSet myHashSet;
    myHashSet.add(1);
    myHashSet.add(2);
    cout << "contains 1: " << myHashSet.contains(1) << endl;
    cout << "contians 3: " << myHashSet.contains(3) << endl;
    myHashSet.add(2);
    cout << "contians 2: " << myHashSet.contains(2) << endl;
    myHashSet.remove(2);
    cout << "contians 2: " << myHashSet.contains(2) << endl;
}

MyHashSet::MyHashSet() {
    store.resize(this->size);
}

void MyHashSet::add(int key) {
    if (this->contains(key)) return;
    int hash = this->getHash(key); 
    this->store[hash].push_back(key);
}

void MyHashSet::remove(int key) {
    if (!this->contains(key)) return;
    int hash = this->getHash(key);
    this->store[hash].remove(key);
}

bool MyHashSet::contains(int key) {
    int hash = this->getHash(key);
    return this->search(key) != this->store[hash].end();
}

int MyHashSet::getHash(int key) {
    int hash = key % this->size;
    return hash;
}

list<int>::iterator MyHashSet::search(int key) {
    int hash = this->getHash(key);
    return find(this->store[hash].begin(), this->store[hash].end(), key);
}