#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms);
};

int main(void) {
    Solution solution;
    vector<vector<int>> rooms = {{1}, {}};
    bool ans = solution.canVisitAllRooms(rooms);
    cout << "ans: " << ans << endl;
}

bool Solution::canVisitAllRooms(vector<vector<int>> &rooms) {

    int lenRooms = rooms.size();

    // Visited array with default value false 
    bool visited[lenRooms];
    for (int i = 0; i < lenRooms; i++) {
        visited[i] = false;
    }
    visited[0] = true;

    stack<int> keys;
    keys.push(0);
    while (!keys.empty()) {
        int key = keys.top();
        keys.pop();
        for (int neyKey: rooms[key]) {
            if (visited[neyKey]) continue;
            visited[neyKey] = true;
            keys.push(neyKey);
        }
    }

    bool allVisited = true;
    for (int i = 0; i < lenRooms; i++) {
        allVisited = allVisited && visited[i];
    }

    return allVisited;
}