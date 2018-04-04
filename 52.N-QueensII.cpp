class Solution {
public:
    int totalNQueens(int n) {
        int sum = 0;
        vector<int> v(n);
        dfs(v, 0, sum);
        return sum;
    }

    void dfs(vector<int>& v, int i, int& sum){
        if(i == v.size()){
            sum++;
            return;
        }
        for(int j = 0; j < v.size(); j++){
            if(isValid(v, i, j)){
                v[i] = j;
                dfs(v, i+1, sum);
            }
        }
    }

    bool isValid(vector<int>& v, int i, int j){
        if(i == 0) return true;
        for(int k = 0; k < i; k++){
            if(v[k] == j) return false;
            int diff = i - k;
            if(v[k] == j - diff || v[k] == j + diff) return false;
        }
        return true;
    }
};
