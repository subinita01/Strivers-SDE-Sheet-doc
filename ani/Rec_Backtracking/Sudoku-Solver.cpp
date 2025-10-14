// Sudoku Solver using Backtracking
// LC 37. Sudoku Solver
// Time Complexity: O(9^(n*n)) in worst case
// Space Complexity: O(n*n) for the board storage
// https://leetcode.com/problems/sudoku-solver/


class Solution {
public:
    bool isSafe(vector<vector<char>>& board, char ch, int row, int col, int n) {
        for(int j = 0; j < n; j++) {
            if(board[row][j] == ch) return false; // horizontal
        }
        for(int i = 0; i < n; i++) {
            if(board[i][col] == ch) return false; // vertical
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[startRow + i][startCol + j] == ch)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') {
                    for(char ch = '1'; ch <= '9'; ch++) {
                        if(isSafe(board, ch, row, col, 9)) {
                            board[row][col] = ch;
                            if(solve(board)) return true;
                            board[row][col] = '.';
                        }
                    }
                    return false; // no valid number found
                }
            }
        }
        return true;
    }


    void solveSudoku(vector<vector<char>>& board) {
        int row=0;
        solve(board);
    }
};
