class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        if(wordList.empty())
            return res;
        unordered_set<string> s(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        if(s.count(beginWord)) s.erase(beginWord);
        queue<string> q;
        int level = 1;
        unordered_map<string, vector<string>> dict;
        q.push(beginWord);
        bool isFind = false;
        while(q.size()){
            if(isFind) break;
            int n = q.size();
            while(n > 0){
                n--;
                string t = q.front();
                q.pop();
                for(int i = 0; i < t.size(); i++){
                    string t1 = t;
                    for(char c = 'a'; c <= 'z'; c++){
                        t1[i] = c;
                        if(s.count(t1)){
                            if(!visited.count(t1)){
                                visited.insert(t1);
                                q.push(t1);
                            }
                            if(t1 == endWord)
                                isFind = true;
                            dict[t1].push_back(t);
                        }
                    }
                }
            }

            for(auto it : visited){
                s.erase(it);
            }
            visited.clear();
        }
        if(!isFind) return res;
        vector<string> ans;
        dfs(dict, beginWord, endWord, ans, res);
        return res;
    }

    void dfs(unordered_map<string, vector<string>>& dict, string s, string e, vector<string>& ans, vector<vector<string>>& res){
        if(e == s){
            ans.push_back(e);
            reverse(ans.begin(), ans.end());
            res.push_back(ans);
            reverse(ans.begin(), ans.end());
            ans.pop_back();
            return;
        }

        ans.push_back(e);
        for(string str : dict[e]){
            dfs(dict, s, str, ans, res);
        }
        ans.pop_back();
    }
};
