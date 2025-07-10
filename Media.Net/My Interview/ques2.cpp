#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX_VAL = 1e6 + 5;
int n;
vector<vector<int>> grid;
vector<vector<bool>> visited;
// Global frequency and sum maps of all numbers in matrix
vector<long long> freq(MAX_VAL, 0);
vector<long long> total_sum(MAX_VAL, 0);
// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
// BFS to collect all cells in one connected component
void dfs(int x, int y, vector<pair<int, int>>& component) {
    stack<pair<int, int>> stk;
    stk.push({x, y});
    visited[x][y] = true;
    while (!stk.empty()) {
        auto [i, j] = stk.top();
        stk.pop();
        component.push_back({i, j});
        for (int d = 0; d < 4; ++d) {
            int ni = i + dx[d];
            int nj = j + dy[d];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && !visited[ni][nj] && grid[ni][nj] != -1) {
                visited[ni][nj] = true;
                stk.push({ni, nj});
            }
        }
    }
}
int main() {
    cin >> n;
    grid.assign(n, vector<int>(n));
    visited.assign(n, vector<bool>(n, false));
    // Input and global stats
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] != -1) {
                int val = grid[i][j];
                freq[val]++;
                total_sum[val] += val;
            }
        }
    long long answer = 0;
    // Traverse the matrix to process each connected component
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != -1 && !visited[i][j]) {
                // Collect component
                vector<pair<int, int>> component;
                dfs(i, j, component);
                // Count and sum inside this component
                vector<long long> comp_freq(MAX_VAL, 0);
                vector<long long> comp_sum(MAX_VAL, 0);
                for (auto [x, y] : component) {
                    int val = grid[x][y];
                    comp_freq[val]++;
                    comp_sum[val] += val;
                }
                // For each cell, compute sed-value
                for (auto [x, y] : component) {
                    int val = grid[x][y];
                    long long total = 0, inside = 0;
                    // Iterate over all multiples of val
                    for (int m = val; m < MAX_VAL; m += val) {
                        total += total_sum[m];
                        inside += comp_sum[m];
                    }
                    long long sed = (total - inside) % MOD;
                    answer = (answer + sed + MOD) % MOD;
                }
            }
        }
    cout << answer << "\n";
    return 0;
}
