#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
// Function to build the power array from a given Z
vector<int> buildPowerArray(const vector<int>& Z) {
    vector<int> X(20, 0);  // Power array of size 20
    int n = Z.size();
    // For each bit position i from 0 to 19
    for (int i = 0; i < 20; ++i) {
        int j = 0;
        // Count how long from start all Z[j] have the i-th bit set
        while (j < n && ((Z[j] >> i) & 1)) {
            ++j;
        }
        X[i] = j;
    }
    return X;
}
int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    // The idea is to greedily build Z by picking elements with highest significant bits first
    vector<bool> used(n, false);
    vector<int> Z;
    set<int> usedValues;
    // For each bit from highest (19) to lowest (0)
    for (int bit = 19; bit >= 0; --bit) {
        for (int i = 0; i < n; ++i) {
            // If bit is set in A[i] and not yet used
            if (((A[i] >> bit) & 1) && !used[i]) {
                Z.push_back(A[i]);
                used[i] = true;
            }
        }
    }
    // Add remaining unused elements to Z
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            Z.push_back(A[i]);
        }
    }
    // Build the power array from the chosen Z
    vector<int> X = buildPowerArray(Z);
    // Print the result
    for (int x : X) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
