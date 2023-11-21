class Solution {
public:
    int modMul(int a, int b, int mod) { 
        long long res = 0;
        while (b) {
            if (b & 1) res = (res + a) % mod;
            a = (2 * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> memo;

        int mod = 1000000007;
        int n = nums.size();
        vector<int> diff;

        for(auto num:nums) {
            string tmp = to_string(num);
            reverse(tmp.begin(), tmp.end());
            int sub = num - stoi(tmp);
            diff.push_back(sub);
        }

        int res = 0;

        for(auto i:diff) {
            memo[i]++;
        }

        for(auto i:memo) {
            if(i.second>1) {
                int num = i.second-1;
                if(num%2) res += modMul(num, (num+1)/2, mod);
                else res += modMul(num/2, num+1, mod);
                if(res>=mod) res = res % mod;
            }
        }

        return res;
    }
};