/*
I was not able to code the question with the desired output but I have a approach with which it can be solved.

APPROACH-->

we have following cases for the special castle to move in the 9X9 board :
    1.	It can only move front.
    2.	When it ‘kills’ a soldier, will only move to ‘its left’
    3.	When it ‘kills’ a soldier, the cell becomes empty
    4.	It can ‘jump’ over soldiers.

so it seems like similar to N queen problem

so what I think it can be solved using backtracking and recursion same as we do in N queen problem

the base case can be if we are going outside of the board we return the dfs funcion 
    i.e  if(x<1 || x>9 || y<1 || y>9) return;
we need to be in the boundary of the board

if we are on some coordinate lets say (row, col) then we need to check the following possibility
    1. there is a soldier S on that coordinate
        if yes then
            1. special castle kills the S and move to left OR
            2.  jump over the S
            these are the choices to make to kill or to jump
    2. there is no soldier S on that coordinate
        then we keep moving until we find a soldier and maintain the same direction in which we were  moving
    
And when we have explored all the possible paths and reached the destination we return or backtrack from there and explore other paths


REFERENCE-->
N queen problem
chat gpt

*/

#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isSafe(int x, int y, vector<vector<char>> &board, int n)
    {
        return x >= 0 && x < n && y >= 0 && y < n && board[x][y] == 'S';
    }

    void printBoard(const vector<vector<char>> &board)
    {
        for (const auto &row : board)
        {
            for (const auto &cell : row)
            {
                cout << cell << ' ';
            }
            cout << endl;
        }
    }

    void backtrack(int x, int y, vector<vector<char>> &board, vector<string> &path, vector<vector<string>> &results, int n, int soldiersLeft, pair<int, int> start, vector<pair<int, int>> &directions)
    {
        if (soldiersLeft == 0 && x == start.first && y == start.second)
        {
            // All soldiers are killed and castle is back at the start
            results.push_back(path);
            return;
        }

        // Try all directions
        for (auto &dir : directions)
        {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (isSafe(nx, ny, board, n))
            {
                // Kill the soldier
                if (board[nx][ny] == 'S')
                {
                    board[nx][ny] = '.';
                    stringstream move;
                    move << "Kill (" << nx + 1 << "," << ny + 1 << "). Turn Left";
                    path.push_back(move.str());

                    // Print board and path for debugging
                    cout << "Moving to: (" << nx + 1 << "," << ny + 1 << ")" << endl;
                    printBoard(board);
                    cout << "Path so far:" << endl;
                    for (const auto &p : path)
                    {
                        cout << p << endl;
                    }
                    cout << endl;

                    // Recursively explore
                    backtrack(nx, ny, board, path, results, n, soldiersLeft - 1, start, directions);

                    // Restore the board
                    board[nx][ny] = 'S';
                    path.pop_back();
                }
            }
        }
    }

    vector<vector<string>> findPaths(int n, vector<pair<int, int>> &soldiers, pair<int, int> &start)
    {
        vector<vector<string>> results;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<string> path;
        vector<pair<int, int>> directions = {{1, 0}, {0, -1}}; // Move forward or turn left

        // Place soldiers on the board
        for (const auto &soldier : soldiers)
        {
            board[soldier.first - 1][soldier.second - 1] = 'S';
        }

        // Start the backtracking process
        backtrack(start.first - 1, start.second - 1, board, path, results, n, soldiers.size(), start, directions);

        return results;
    }
};

int main()
{
    int n = 9;
    Solution sol;

    cout << "Enter coordinates for soldiers:" << endl;
    vector<pair<int, int>> soldiers;
    for (int i = 1; i <= 11; ++i)
    {
        int x, y;
        cout << "Enter coordinates for soldier " << i << ": ";
        cin >> x >> y;
        soldiers.emplace_back(x, y);
    }

    int castle_x, castle_y;
    cout << "Enter the coordinates for your “special” castle: ";
    cin >> castle_x >> castle_y;
    pair<int, int> start = {castle_x, castle_y};

    vector<vector<string>> paths = sol.findPaths(n, soldiers, start);

    cout << "\nTotal unique paths needed to kill all soldiers: " << paths.size() << endl;
    for (const auto &path : paths)
    {
        cout << "\nPath:\n";
        for (const auto &move : path)
        {
            cout << move << endl;
        }
    }

    return 0;
}
