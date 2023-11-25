class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> res;
        
        int psum = 0;
        int nsum = 0;

        for(int i=nums.size()-1; i>=0; i--) {
            nsum += nums[i];
        }

        for(int i=0; i<nums.size(); i++) {
            int cur = 0;
            nsum -= nums[i];
            cur += (i * nums[i]) - psum;
            cur += nsum - (nums[i] * (nums.size()-1-i));
            psum += nums[i];
            res.push_back(cur);
        }

        return res;
    }
};