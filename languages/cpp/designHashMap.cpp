#include <iostream>
using namespace std;

class MyHashMap {
private:
	const int NOT_FOUND = -1;

	const static int ROW_SIZE = 1001;
	const static int COLUMN_SIZE = 1001;
	int storage[ROW_SIZE][COLUMN_SIZE] = {};

	int getRowIndex(int key);
	int getColumnIndex(int key);

public:
	MyHashMap() {}
	void put(int key, int value);
	int get(int key);
	void remove(int key);
};

int main(void) {
	MyHashMap *myHashMap = new MyHashMap();
	myHashMap->put(1, 1);
	myHashMap->put(2, 2);

	cout << "key 1: " << myHashMap->get(1) << endl;
	cout << "key 3: " << myHashMap->get(3) << endl;
}

int MyHashMap::get(int key) {
	int rowIndex = this->getRowIndex(key);
	int columnIndex = this->getColumnIndex(key);
	int value = this->storage[rowIndex][columnIndex] - 1;

	return value;
}

void MyHashMap::put(int key, int value) {
	int rowIndex = this->getRowIndex(key);
	int columnIndex = this->getColumnIndex(key);

	/* 
		Store "value + 1" because the default value of an array is 0.
		And, we'll return with "value - 1". That's mean if we've never 
		store key-value into the array we will return 0 - 1 which is -1.
	*/
	this->storage[rowIndex][columnIndex] = value + 1;
}

void MyHashMap::remove(int key) {
	int rowIndex = this->getRowIndex(key);
	int columnIndex = this->getColumnIndex(key);

	this->storage[rowIndex][columnIndex] = this->NOT_FOUND + 1;
}

int MyHashMap::getRowIndex(int key) {
	return key / this->ROW_SIZE;
}

int MyHashMap::getColumnIndex(int key) {
	return key % this->COLUMN_SIZE;
}

/* 

Capacity = 100
which row/column to input?

input: 57
row = 57 // row size = 5
column = 57 mod column size

input: 100
row = 100 // row size = 10
column = 100 mod column size = 10

1 2 3 4 5 ... 10
2
3
4
5
.
.
.
10


*/
