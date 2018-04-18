class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a1  = 0, c1 = 0, a2 = 0, c2 = 0;
        for(int n : nums){
            if(n == a1)
                c1++;
            else if(n == a2)
                c2++;
            else if(c1 == 0){
                a1 = n;
                c1++;
            }
            else if(c2 == 0){
                a2 = n;
                c2++;
            }
            else{
                if(c1 > 0) c1--;
                if(c2 > 0) c2--;
            }
        }
        c1 = 0, c2 = 0;
        for(int n : nums){
            if(n == a1)
                c1++;
            if(n == a2)
                c2++;
        }
        vector<int> res;
        if(c1 > nums.size()/3)
            res.push_back(a1);
        if(a1 != a2 && c2 > nums.size()/3)
            res.push_back(a2);
        return res;
    }
};
