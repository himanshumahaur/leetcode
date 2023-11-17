class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size()/2;

        int m = 0;
        for(int i=0; i<n; i++) {
            m = max(m, nums[i]+nums[nums.size()-1-i]);
        }
        return m;
    }
};