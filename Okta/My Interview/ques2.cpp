#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to compute total walk distance
int computeWalk(int target, vector<int>& stations) {
    // Add starting point (0) and target to the stations
    stations.push_back(0);
    stations.push_back(target);
    // Sort the stations so we can process them in order
    sort(stations.begin(), stations.end());
    int walk = 0;        // Total distance walked
    int position = 0;    // Current position of drone
    int i = 0;           // Index to traverse stations
    int n = stations.size();
    // Continue until the drone can't reach target directly
    while (position + 10 < target) {
        int j = i;
        // Move to the farthest station within 10 units from current position
        while (j + 1 < n && stations[j + 1] <= position + 10) {
            j++;
        }
        // If no further station is reachable, break the loop
        if (stations[j] == position) {
            break;  // Stuck, can't reach any new station
        }
        // You walk from current position to the next station
        walk += stations[j] - position;
        // Update drone's position
        position = stations[j];
        // Move index to the new position
        i = j;
    }
    // Final walk if drone still hasn't reached target
    if (position < target) {
        walk += target - position;
    }
    return walk;
}
int main() {
    // Example test case
    int target = 100;
    vector<int> stations = {12, 25, 38, 55};
    int totalWalk = computeWalk(target, stations);
    cout << "Total units walked: " << totalWalk << endl;
    return 0;
}
