#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void addSolution(vector<vector<string>> &ans, vector<vector<char>> &board, int n)
    {
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {
            string str;
            for (int j = 0; j < n; j++)
            {
                str.push_back(board[i][j]);
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<char>> &board, int n)
    {
        int x = row;
        int y = col;

        // Check for same row
        while (y >= 0)
        {
            if (board[x][y] == 'Q')
            {
                return false;
            }
            y--;
        }

        x = row;
        y = col;

        // Check for upper diagonal
        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 'Q')
            {
                return false;
            }
            x--;
            y--;
        }

        x = row;
        y = col;

        // Check for lower diagonal
        while (x < n && y >= 0)
        {
            if (board[x][y] == 'Q')
            {
                return false;
            }
            x++;
            y--;
        }

        return true;
    }

    void solve(int col, vector<vector<string>> &ans, vector<vector<char>> &board, int n)
    {
        // Base case
        if (col == n)
        {
            addSolution(ans, board, n);
            return;
        }

        // Solve one case and the rest recursion will take care of
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                // If placing is safe
                board[row][col] = 'Q';
                solve(col + 1, ans, board, n);
                // Backtrack
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans;
    }
};

int main()
{
    Solution solution;
    int n = 4; // Change this to the desired value of n
    vector<vector<string>> result = solution.solveNQueens(n);

    // Print the solutions
    for (const auto &solution : result)
    {
        for (const auto &row : solution)
        {
            printf("%s\n", row.c_str());
        }
        printf("\n");
    }

    return 0;
}
