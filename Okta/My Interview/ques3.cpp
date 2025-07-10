#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 10; // Grid size (10x10)
// Type alias for a shape
typedef vector<vector<int>> Shape;
// Function to print the final grid
void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}
// Function to check if a shape can be placed at position (r, c)
bool canPlace(const vector<vector<int>>& grid, const Shape& shape, int r, int c) {
    int h = shape.size();
    int w = shape[0].size();
    // Check if shape would exceed grid boundaries
    if (r + h > N || c + w > N)
        return false;
    // Check for overlapping existing shapes
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (shape[i][j] == 1 && grid[r + i][c + j] != 0)
                return false;
        }
    }
    return true;
}
// Function to place a shape on the grid with a unique ID (1-based index)
void placeShape(vector<vector<int>>& grid, const Shape& shape, int r, int c, int fillID) {
    int h = shape.size();
    int w = shape[0].size();
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (shape[i][j] == 1)
                grid[r + i][c + j] = fillID;
        }
    }
}
int main() {
    // Initialize grid with 0s
    vector<vector<int>> grid(N, vector<int>(N, 0));
    // Define the shapes A to E
    map<char, Shape> shapes;
    // A = Single block
    shapes['A'] = {{1}};
    // B = Horizontal line (1x2)
    shapes['B'] = {{1, 1}};
    // C = Offset 2x2 block
    shapes['C'] = {
        {0, 1, 1},
        {0, 1, 1}
    };
    // D = L-like shape
    shapes['D'] = {
        {1, 0},
        {1, 1},
        {1, 0}
    };
    // E = Upside-down T
    shapes['E'] = {
        {0, 1, 0},
        {1, 1, 1}
    };
    // Input vector of shape labels
    vector<char> sequence = {'B', 'A', 'C', 'D', 'E', 'A', 'C'};
    // Go through each shape in the sequence and attempt to place it
    for (int index = 0; index < sequence.size(); ++index) {
        char ch = sequence[index];
        int fillID = index + 1; // 1-based index to be written into the grid
        const Shape& shape = shapes[ch];
        bool placed = false;
        // Try placing the shape in the grid row by row
        for (int i = 0; i < N && !placed; ++i) {
            for (int j = 0; j < N && !placed; ++j) {
                if (canPlace(grid, shape, i, j)) {
                    placeShape(grid, shape, i, j, fillID);
                    placed = true;
                }
            }
        }
        if (!placed) {
            cout << "Shape " << ch << " (#" << fillID << ") could not be placed.\n";
        }
    }
    // Print the final grid
    cout << "Final Grid:\n";
    printGrid(grid);
    return 0;
}
