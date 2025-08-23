#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int solution(vector<vector<int>> &A) {
    vector<pair<int, int>> stones;
    vector<pair<int, int>> targets;
    // Collect all stone positions and all target cell positions (3x3 grid)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int s = 0; s < A[i][j]; ++s)
                stones.push_back({i, j});
            targets.push_back({i, j});
        }
    }
    int n = stones.size(); // n == 9 (guaranteed by problem)
    // Build the cost matrix (Manhattan distances)
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cost[i][j] = abs(stones[i].first - targets[j].first) + abs(stones[i].second - targets[j].second);
    // Try all permutations (which stone goes to which final cell)
    vector<int> p(n);
    for (int i = 0; i < n; ++i) 
        p[i] = i;
    int minMoves = INT_MAX;
    do {
        int moves = 0;
        for (int i = 0; i < n; ++i)
            moves += cost[i][p[i]];
        minMoves = min(minMoves, moves);
    } while (next_permutation(p.begin(), p.end()));
    return minMoves;
}
