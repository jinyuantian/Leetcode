class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.empty()) return res;
        vector<string> ans ;
        help(s, ans, res, 0);
        return res;
    }

    void help(string s, vector<string>& ans, vector<string>& res, int i){
        if(ans.size() == 4 && i < s.size())
            return;
        if(i == s.size()){
            if(ans.size() == 4){
                string t = ans[0];
                for(int i = 1; i < 4; i++)
                    t += ("." + ans[i]);
                res.push_back(t);
            }
            return;
        }

        for(int j = i; j < i+3 && j < s.size(); j++){
            if(j == i && s[j] == '0'){
                ans.push_back("0");
                help(s, ans, res, i+1);
                ans.pop_back();
                return;
            }
            int len = j - i + 1;
            string t = s.substr(i, len);
            if(stoi(t) <= 255){
                ans.push_back(t);
                help(s, ans, res, j+1);
                ans.pop_back();
            }
        }
    }
};
