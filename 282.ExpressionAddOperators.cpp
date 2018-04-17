class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if(num.empty()) return res;
        string ans = "";
        help(num, target, ans, res, 0, 0, 0);
        return res;
    }

    void help(string num, int target, string ans, vector<string>& res, long cur, long pre, int pos){
        if(pos == num.size()){
            if(cur == target)
                res.push_back(ans);
            return;
        }

        for(int i = pos; i < num.size(); i++){
            if(num[pos] == '0' && i > pos)
                return;

            string nstr = num.substr(pos, i - pos + 1);
            long val = stol(nstr);
            if(pos == 0){
                help(num, target, ans+nstr, res, val, val, i+1);
            }
            else{
                help(num, target, ans + "+" + nstr, res, cur + val, val, i+1);
                help(num, target, ans + "-" + nstr, res, cur - val, -val, i+1);
                help(num, target, ans + "*" + nstr, res, cur - pre + pre * val, pre * val, i+1);
            }
        }
    }
};
