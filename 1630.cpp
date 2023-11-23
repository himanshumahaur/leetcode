class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;

        for(int i=0; i<l.size(); i++) {
            vector<int> subArr;

            subArr.assign(nums.begin()+l[i], nums.begin()+r[i]+1);

            sort(subArr.begin(), subArr.end());

            int diff = subArr[1] - subArr[0];

            for(int j=1; j<subArr.size(); j++) {
                if(subArr[j]-subArr[j-1]!=diff) {
                    res.push_back(false);
                    break;
                }
                if(j==subArr.size()-1) res.push_back(true);
            }
        }

        return res;
    }
};