#include <set>
#include <unordered_set> 
#include <iostream>
using namespace std;

// An 'unordered_set' is implemented using a hash table where
// heys are hashed into indices of a hash table so that 
// the insertion is always randomized.

// 'set' is an ordered sequence of unique keys whereas unordered_set
// is a set in which key can be stored in any order.
// 'set' is implemented as a balanced tree structure that is why it is
// possible to maintain order between the elements.

void _unorderedSet();
void printDuplicates();
void _set();


int main(void) {

	_unorderedSet();
	printDuplicates();
	_set();

}

void _unorderedSet() {
	unordered_set<string> stringSet;

	stringSet.insert("code");
	stringSet.insert("in");
	stringSet.insert("c++");
	stringSet.insert("is");
	stringSet.insert("fast");

	// find returns end iterator if key is not found,
	// else it returns iterator to that key
	string key = "slow";
	if (stringSet.find(key) == stringSet.end()) {
		cout << key << " not found" << endl;
	} else {
		cout << "Found " << key << endl;
	}

	key = "c++";
	if (stringSet.find(key) == stringSet.end()) {
		cout << key << " not found\n";
	} else {
		cout << "Found " << key << endl;
	}

	// now iterating over whole set and printing its content
	cout << "\nAll elements: \n";
	unordered_set<string>::iterator itr;
	for (itr = stringSet.begin(); itr != stringSet.end(); itr++) {
		cout << (*itr) << endl;
	}
}

void printDuplicates() {

	// Example input
	int arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};
	int n = sizeof(arr) / sizeof(arr[0]);

	unordered_set<int> intSet;
	unordered_set<int> duplicate;

	for (int i = 0; i < n; i++) {
		if (intSet.find(arr[i]) == intSet.end()) {
			intSet.insert(arr[i]);
		} else {
			duplicate.insert(arr[i]);
		}
	}

	// printing the result
	cout << "\nDuplicate item are: ";
	for (auto d: duplicate) {
		cout << d << " ";
	}
	cout << endl;
}

void _set() {

	// The ordering of the objects is determined by the second argument.
	// By default, it is 'std::less<Key>'.
	set<int, greater<int>> s1;
	s1.insert(40);
	s1.insert(30);
	s1.insert(60);
	s1.insert(20);
	s1.insert(50);

	// only one 50 will be added to the set
	s1.insert(50);
	s1.insert(10);

	// printing set s1
	set<int, greater<int>>::iterator itr;
	cout << "\nThe set s1 is: \n";
	for (itr = s1.begin(); itr != s1.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;

	// assigning the elements from s1 to s2
	set<int> s2(s1.begin(), s1.end());

	// print all elements of the set s2
	cout << "\nThe set s2 after assign from s1 is: \n";
	for (auto s: s2) {
		cout << s << " ";
	}
	cout << endl;

	// remove all elements up to 20 in s2
	cout << "\ns2 after removal of elements less than 30: \n";
	s2.erase(s2.begin(), s2.find(30));
	for (auto s: s2) {
		cout << s << " ";
	}
	cout << endl;

	// remove element with value 50 in s2
	int num = s2.erase(50);
	cout << "\ns2.erase(50): ";
	cout << num << " removed\n";
	for (auto s: s2) {
		cout << s << " ";
	}
	cout << endl << endl;

	// lower bound and upper bound for set s1
	cout << "s1.lower_bound(40): \n";
	cout << *s1.lower_bound(40) << endl;
	cout << "s1.upper_bound(40): \n";
	cout << *s1.upper_bound(40) << endl;

	// lower bound and upper bound for set s2
	cout << "s2.lower_bound(40): \n";
	cout << *s2.lower_bound(40) << endl;
	cout << "s2.upper_bound(40): \n";
	cout << *s2.upper_bound(40) << endl;
}
