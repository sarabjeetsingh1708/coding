#include <iostream>
#include <vector>

using namespace std;

// Define the maze dimensions (rows and columns)
const int ROWS = 3;
const int COLS = 3;

// Check if a cell is within the maze boundaries
bool isValid(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

// Recursive function to explore the maze
bool exploreMaze(vector<vector<int>>& maze, int x, int y) {
    // Base case: If we reach the destination (bottom-right corner), return true
    if (x == ROWS - 1 && y == COLS - 1) {
        return true;
    }

    // Mark the current cell as visited
    maze[x][y] = 2; // 2 represents visited cell

    // Explore all four possible directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0}; // Change in x-coordinate
    int dy[] = {0, 0, -1, 1}; // Change in y-coordinate

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY) && maze[newX][newY] == 0) {
            if (exploreMaze(maze, newX, newY)) {
                return true; // Found a path
            }
        }
    }

    // No path found from this cell, backtrack
    return false;
}

int main() {
    vector<vector<int>> maze = {
        {0, 0, 0},
        {1, 1, 0},
        {0, 0, 0}
    };

    // Take input for the maze (2D vector)
    cout << "Enter the maze (3x3):" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cin >> maze[i][j];
        }
    }

    bool canEscape = exploreMaze(maze, 0, 0);

    if (canEscape) {
        cout << "Path exists. You can escape the maze!" << endl;
    } else {
        cout << "No path found. You are trapped!" << endl;
    }

    return 0;
}
