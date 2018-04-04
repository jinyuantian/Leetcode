class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        if(grid.empty() || grid[0].empty()) return ans;

        int nrow = grid.size(), ncol = grid[0].size();

        for(int i = 0; i < nrow; i++){
            for(int j = 0; j < ncol; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    paint(grid, i, j);
                }
            }
        }

        return ans;
    }

    void paint(vector<vector<char>>& grid, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j]!='1')
            return;
        grid[i][j] = '#';

        paint(grid, i+1, j);
        paint(grid, i-1, j);
        paint(grid, i, j+1);
        paint(grid, i, j-1);
    }
};
