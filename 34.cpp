class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};

        int n = nums.size();
        int m = 0;
        int M = n-1;

        while(m<=M) {
            int idx = (M + m)/2;
            if(nums[idx]==target && (idx==0 || nums[idx-1]<target)) {
                res[0] = idx;
                break;
            }
            else if(nums[idx]>=target) {
                M = idx-1;
            }
            else {
                m = idx+1;
            }
        }

        m = 0;
        M = n-1;
        while(m<=M) {
            int idx = (M + m)/2;
            if(nums[idx]==target && (idx==n-1 || nums[idx+1]>target)) {
                res[1] = idx;
                break;
            }
            else if(nums[idx]<=target) {
                m = idx+1;
            }
            else {
                M = idx-1;
            }
        }

        return res;
    }
};