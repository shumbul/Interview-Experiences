1. Given: Integer array A of length N, and any permutation P of length N.  
Define array Z = [A[P₁], A[P₂], …, A[Pₙ]].  
Build a power array X of size 20:  
X[i] = max j such that for all k ≤ j, (Z[k] & 2^(i−1)) ≠ 0.  
Compare power arrays lexicographically: one is greater if at the first index i where they differ, its X[i] is larger.  
Task: Find the lexicographically largest power array possible for any permutation of A.  
Constraints: 1 ≤ N ≤ 2×10^5 0 ≤ A[i] < 2^20
[solution](https://github.com/Manasvee16/Interview-Experiences/blob/main/Media.Net/My%20Interview/ques1.cpp)

2. You are given a matrix A of size N×N.
Each cell A[i][j] is either:
A non-negative integer, or -1, indicating a blocked cell.
A cell with value -1 has a "sed-value" of -1.
For any unblocked cell A[i][j], its sed-value S[i][j] is defined as:
The sum of values of all cells A[x][y] such that:
A[x][y] is a multiple of A[i][j].
(x, y) is not reachable from (i, j) via up/down/left/right moves through unblocked cells.
The passcode P is: (Sum of all sed-values S[i][j]) mod 1 000 000 007
[solution](https://github.com/Manasvee16/Interview-Experiences/blob/main/Media.Net/My%20Interview/ques2.cpp)

3. https://leetcode.com/problems/trapping-rain-water-ii/description/
