#include <bits/stdc++.h>
using namespace std;
// Globals for convenience
vector<vector<int>> children;
vector<long long> W;  // brightness
// Returns {off, on} for node u
// off = max sum if u is OFF (children free)
// on  = max sum if u is ON, with an EVEN number of ON children
pair<long long,long long> dfs(int u) {
    long long offSum = 0;
    // For ON: parity DP over children
    // dp[0] = best sum so far with even #ON children; starts at W[u] (u is ON, 0 ON-children yet)
    // dp[1] = best sum so far with odd  #ON children
    const long long NEG = LLONG_MIN / 4;
    long long dp_even = W[u], dp_odd = NEG;
    for (int v : children[u]) {
        auto [childOff, childOn] = dfs(v);
        // OFF state of u: children can be ON or OFF freely
        offSum += max(childOff, childOn);
        // ON state of u: maintain parity over children choices
        long long ndp_even = NEG, ndp_odd = NEG;
        // take child OFF (parity unchanged)
        ndp_even = max(ndp_even, dp_even + childOff);
        ndp_odd  = max(ndp_odd,  dp_odd  + childOff);
        // take child ON (parity flips)
        ndp_odd  = max(ndp_odd,  dp_even + childOn);
        ndp_even = max(ndp_even, dp_odd  + childOn);
        dp_even = ndp_even;
        dp_odd  = ndp_odd;
    }
    // If u is ON, we require EVEN number of ON-children → dp_even
    long long onSum = dp_even;
    return {offSum, onSum};
}
int main() {
    int n;
    cin >> n;
    vector<int> P(n);
    W.assign(n, 0);
    for (int i = 0; i < n; ++i) 
      {
        cin >> P[i];     // parent array: P[i] == -1 for root; otherwise parent_index = P[i]-1
      }
    for (int i = 0; i < n; ++i) 
      {
        cin >> W[i];     // brightness
      }
    children.assign(n, {});
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (P[i] == -1) {
            root = i;
        } 
        else {
            int parent = P[i] - 1;   // ✅ correct mapping: P[i] = 1 → parent index 0
            children[parent].push_back(i);
        }
    }
    auto [offRoot, onRoot] = dfs(root);
    cout << max(offRoot, onRoot) << "\n";
    return 0;
}
