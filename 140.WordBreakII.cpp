class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(s.empty() || wordDict.empty()) return vector<string>();

        unordered_map<int, vector<string>> ans;

        unordered_set<string> dict;
        for(string w: wordDict){
            dict.insert(w);
        }
        return help(s, dict, ans, 0);
    }

    vector<string> help(string s, unordered_set<string>& dict, unordered_map<int, vector<string>>& ans, int i){
        if(ans.count(i))
            return ans[i];
        ans[i] = vector<string>();

        for(int j = i+1; j <= s.size(); j++){
            string t = s.substr(i, j-i);
            if(dict.count(t)){
                if(j == s.size())
                    ans[i].push_back(t);
                else{
                    vector<string> arr = help(s, dict, ans, j);
                    if(arr.size()){
                        for(string a : arr)
                            ans[i].push_back(t + " " + a);
                    }
                }
            }
        }
        return ans[i];
    }
};
