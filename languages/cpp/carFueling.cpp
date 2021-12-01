// https://python.plainenglish.io/the-car-fueling-problem-8d7deb07a351
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int minRefill(int distance, int maxDistanceOnFullTank, vector<int> stations);
	int minRefill2(int distance, int maxDistanceOnFullTank, vector<int> stations);
};

int main(void) {
	Solution solution;
	int distance = 950, maxDistanceOnFullTack = 400;
	vector<int> stations = {230, 375, 550, 750};
	int ans = solution.minRefill2(distance, maxDistanceOnFullTack, stations);
	cout << "ans: " << ans << endl;
}

int Solution::minRefill(int distance, int maxDistanceOnFullTank, vector<int> stations) {

	int remainFuel = maxDistanceOnFullTank - stations[0];
	if (remainFuel < 0) return -1;

	int totalDistance = stations[0];
	int numRefill = 0;
	stations.push_back(distance);
	for (int i = 1; i < stations.size() - 1; i++) {
		// --- No need to refill ---
		if (totalDistance + remainFuel >= distance) {
			return numRefill;
		}

		// --- Update fuel ---
		int distanceFromLastStation = stations[i] - stations[i - 1];
		int distanceToNextStation = stations[i + 1] - stations[i];
		remainFuel = remainFuel - distanceFromLastStation;

		// Impossible to go to destination?
		bool canGoToNextStation = distanceToNextStation <= maxDistanceOnFullTank;
		bool canComeFromLastStation = remainFuel >= 0;
		if (!canGoToNextStation || !canComeFromLastStation) return -1;

		// Should refill here?
		bool shouldRefillHere = remainFuel < distanceToNextStation;
		if (shouldRefillHere) {
			numRefill++;
			remainFuel = maxDistanceOnFullTank;
			totalDistance = stations[i];
		}
	}

	return totalDistance + remainFuel >= distance ? numRefill : -1;
}

int Solution::minRefill2(int distance, int maxDistanceOnFullTank, vector<int> stations) {

	int furthestDistanceThatCanGo = maxDistanceOnFullTank;
	int curStationIndex = 0;
	int lenStations = stations.size();
	int numRefill = 0;
	while (furthestDistanceThatCanGo < distance) {

		if (curStationIndex >= lenStations || stations[curStationIndex] > furthestDistanceThatCanGo) {
			return -1;
		}

		// Find the furthest station to refill
		while (curStationIndex < lenStations - 1 && stations[curStationIndex + 1] <= furthestDistanceThatCanGo) {
			curStationIndex++;
		}

		numRefill++;
		furthestDistanceThatCanGo = stations[curStationIndex] + maxDistanceOnFullTank;
		curStationIndex++;
	}

	return numRefill;
}
