#include <bits/stdc++.h>
using namespace std;
int maxWaterTransfers(int n, int c, vector<int>& A) {
    long long totalWater = accumulate(A.begin(), A.end(), 0LL);
    long long totalCapacity = 1LL * n * c;
    long long totalEmpty = totalCapacity - totalWater;
    return min(totalWater, totalEmpty);
}
int main() {
    int n = 2, c = 3;
    vector<int> A = {2, 1};
    cout << maxWaterTransfers(n, c, A) << "\n"; // Output: 3
}
