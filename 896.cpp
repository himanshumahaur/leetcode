class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int d = 0;
        int i = 0;
        while(i<n-1) {
            if(!d) {
                d = nums[i] - nums[i+1];
            }
            else if(d>0 && nums[i] - nums[i+1]<0) {
                return false;
            }
            else if(d<0 && nums[i] - nums[i+1]>0) {
                return false;
            }
            i++;
        }
        return true;
    }
};