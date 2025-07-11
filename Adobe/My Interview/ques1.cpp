#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    int N, M, K;
    cin >> N >> M >> K;
    // dp[i][j] = number of sequences of length i ending with number j
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    // Base case: For sequences of length 1, there's 1 way to end with each number 1 to M
    for (int j = 1; j <= M; ++j) {
        dp[1][j] = 1;
    }
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            for (int prev = 1; prev <= M; ++prev) {
                if (abs(j - prev) >= K) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][prev]) % MOD;
                }
            }
        }
    }
    // Sum all sequences of length N
    int result = 0;
    for (int j = 1; j <= M; ++j) {
        result = (result + dp[N][j]) % MOD;
    }
    cout << result << endl;
    return 0;
}
