#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool isSafe(const vector<int> &board, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

bool solveNQueens(vector<int> &board, int row, int n)
{
    if (row == n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            if (solveNQueens(board, row + 1, n))
            {
                return true;
            }
        }
    }
    return false;
}

string getChessNotation(int row, int col)
{
    char columnChar = 'a' + col;
    string position = string(1, columnChar) + to_string(row + 1);
    return position;
}

vector<string> nQueensSolution(int n)
{
    vector<int> board(n, -1);
    vector<string> result;

    if (solveNQueens(board, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            result.push_back(getChessNotation(i, board[i]));
        }
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n < 1)
    {
        cout << "Invalid input. n must be at least 1." << endl;
        return 1;
    }

    vector<string> solution = nQueensSolution(n);

    if (!solution.empty())
    {
        cout << "Solution for " << n << " queens:" << endl;
        for (const string &pos : solution)
        {
            cout << pos << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No solution exists for " << n << " queens." << endl;
    }

    return 0;
}
