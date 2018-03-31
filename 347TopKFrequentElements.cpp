class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty()) return vector<int>{};

        unordered_map<int, int> dict;
        for(int n : nums){
            dict[n]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto item : dict){
            pq.push(make_pair(item.second, item.first));
        }
        vector<int> ans;
        while(k > 0){
            k--;
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};
