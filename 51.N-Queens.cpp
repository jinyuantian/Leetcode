class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if(n <= 0) return ans;
        vector<string> board(n, string(n, '.'));
        dfs(board, ans, 0);
        return ans;
    }

    void dfs(vector<string>& board, vector<vector<string>>& ans, int i){
        if(i == board.size()){
            ans.push_back(board);
            return;
        }
        for(int j = 0; j < board.size(); j++){
            if(isValid(board, i, j)){
                board[i][j] = 'Q';
                dfs(board, ans, i+1);
                board[i][j] = '.';
            }
        }
    }

    bool isValid(vector<string>& board, int i, int j){
        if(i == 0) return true;

        for(int k = 0; k < i; k++){
            if(board[k][j] == 'Q')
                return false;
            int diff = i - k;
            if(j - diff >= 0 && board[k][j-diff] == 'Q')
                return false;
            if(j + diff < board.size() && board[k][j+diff] == 'Q')
                return false;
        }
        return true;
    }
};
