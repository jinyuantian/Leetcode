class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        // the stack keeps the indice of the heights in ascending order
        stack<int> s;
        for(int i = 0; i <= heights.size(); i++){
            int cur_h = i == heights.size()? 0 : heights[i];
            while(s.size() && heights[s.top()] > cur_h){
                int h = heights[s.top()];
                s.pop();
                int idx = s.size()? s.top() : -1;
                res = max(res, h * (i-idx-1));
            }
            s.push(i);
        }
        return res;
    }
};
