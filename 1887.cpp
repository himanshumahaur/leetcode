class Solution {
public:
    static bool cmp(const int& a, const int& b) {
        return a>b;
    }

    int reductionOperations(vector<int>& nums) {
        int ops = 0;
        sort(nums.begin(), nums.end(), cmp);

        for(int i=1; i<nums.size(); i++) {
            if(nums[i-1]>nums[i]) {
                ops += i;
            }
        }

        return ops;
    }
};