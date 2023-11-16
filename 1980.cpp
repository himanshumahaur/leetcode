class Solution {
public:
    void check(vector<string>& nums, string res, string& ans) {
        if(ans.length()) {
            return;
        }
        else if(res.length()<nums.size()) {
            check(nums, res + '0', ans);
            check(nums, res + '1', ans);
        }
        else {
            for(int i=0; i<nums.size(); i++) {
                if(res==nums[i]) return;
            }
            ans = res;
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        check(nums, "", ans);
        return ans;
    }
};