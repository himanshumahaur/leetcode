// with constant space - nlogn;
bool cmp(const int& a, const int& b) {
    if(a%2==0 && b%2!=0) return true;
    return false;
}

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};

// with O(n) space - n;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res;
        for(auto i:nums) {
            if(i%2==0) {
                res.push_back(i);
            }
        }
        for(auto i:nums) {
            if(i%2!=0) {
                res.push_back(i);
            }
        }
        return res;
    }
};