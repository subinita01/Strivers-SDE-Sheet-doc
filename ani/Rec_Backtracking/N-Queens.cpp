// LC 51. N-Queens
// https://leetcode.com/problems/n-queens/

class Solution {
public:
    bool isSafe(vector<string> rows, int row, int col, int n) {
        // check vertical ((0,0),(1,0),(2,0)..) , for all column col
        for (int i = row; i >= 0; i--) {
            if (rows[i][col] == 'Q') {
                return false;
            }
        }
        // check diagonal (top-left)
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (rows[i][j] == 'Q') {
                return false;
            }
        }
        // check diagonal (top-right)
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (rows[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void solve(int n, int row, vector<string>& rows, vector<vector<string>>& output) {
        if (row == n) {
            output.push_back(rows);
            return;
        }
        for (int col = 0; col < n; col++) {
            // agr ye condition false toh col ka loop aage bdhega and the queen
            // will be placed wherever she is safe, in the next rows
            if (isSafe(rows, row, col, n)) {
                rows[row][col]='Q';
                solve(n, row + 1, rows, output);
                // backtrack
                // 2 cases

                // Case 1: all 4 queen placed, output vector m ek possible
                // answer push back honejane k baad return null to upr wala
                // recurssion and put "." in that place and same loop chlega
                // until
                // col<n, jb last row ka all column explored back track to
                // previous row and similarly explore
                // aur if possible configuratiuon found then again next row
                // explore

                // Case 2: not all queen placed but loop end hogya then return
                // null and backtrack to previous
                // row and put dot in the place where queen was placed then loop
                // aage bdhega and will put queen
                // where she is safe in that row then go to next row...the
                // process goes on
                rows[row][col]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        // each position of array initialized with n dots
        vector<string> rows(n, string(n, '.')); // all rows in one vector
        int row = 0;
        solve(n, row, rows, output);
        return output;
    }
};