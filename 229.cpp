//alternate method using voting-moore

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int m = n/3;

        vector<int> res;

        sort(nums.begin(), nums.end());

        int count = 1;
        for(int i=0; i<n; i++) {
            if(i+1<n && nums[i]==nums[i+1]) count++;
            else {
                if(count>m) res.push_back(nums[i]);
                count = 1;
            }
        }

        return res;
    }
};