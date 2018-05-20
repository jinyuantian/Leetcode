class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> height(n+1, 0);
        int res = 0;
        for(int row = 0; row < m; row++){
            stack<int> s; // store the index of the ascending height series
            for(int i = 0; i <= n; i++){
                if(i < n){
                    height[i] = matrix[row][i] == '1'? height[i] + 1 : 0;
                }
                while(s.size() && height[s.top()] > height[i]){
                    int h = height[s.top()];
                    s.pop();
                    int cur = h * (s.empty() ? i : i - s.top() - 1);
                    res = max(res, cur);
                }
                s.push(i);
            }
        }
        return res;
    }
};
