class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;

        unordered_map<char, int> memo;

        for(auto i:chars) {
            memo[i]++;
        }

        for(auto i:words) {
            bool count = true;
            unordered_map<char, int> temp = memo;
            for(auto j:i) {
                if(temp[j]>0) temp[j]--;
                else {
                    count = false;
                    break;
                }
            }
            if(count) res += i.length();
        }

        return res;
    }
};