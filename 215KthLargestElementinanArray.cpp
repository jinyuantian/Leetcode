// Quick Selection
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        return findKthLargest(nums, k, 0, nums.size()-1);
    }

    int findKthLargest(vector<int>& nums, int k, int s, int e){
        if(s == e) return nums[e];

        int pivot = split(nums, s, e);

        if(pivot - s + 1 == k)
            return nums[pivot];
        else if(pivot - s + 1 > k)
            return findKthLargest(nums, k, s, pivot-1);
        else
            return findKthLargest(nums, k - (pivot - s + 1), pivot + 1, e);
    }

    int split(vector<int>& nums, int s, int e){
        int pre = s - 1, i = s;
        while(i < e){
            if(nums[i] > nums[e])
                swap(nums[++pre], nums[i]);
            i++;
        }
        swap(nums[++pre], nums[e]);
        return pre;
    }
};
