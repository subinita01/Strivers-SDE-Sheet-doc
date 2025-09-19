// LC: 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

class Solution {
    public:
        void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited){
            int n = grid.size(); // row
            int m = grid[0].size(); // column
    
            // base case
    
            if(r<0 || c<0 || r>=n || c>=m || grid[r][c]!='1' || visited[r][c]){
                return ;
            }
            visited[r][c]=true;
    
            dfs(grid, r+1, c, visited); //right
            dfs(grid, r, c-1, visited); //up
            dfs(grid, r-1, c, visited); //left
            dfs(grid, r, c+1, visited); //down
        }
        int numIslands(vector<vector<char>>& grid) {
            int n = grid.size(); // row
            int m = grid[0].size(); // column
            int island = 0;
            vector<vector<bool>> visited(n, vector<bool>(m,false));
    
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]=='1' && !visited[i][j]){
                        dfs(grid, i, j, visited);
                        island++;
                    }
                }
            }
            return island;  
        }
    };