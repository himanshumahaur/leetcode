class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> memo(26, 0);
        
        for(auto i:s) memo[int(i - 'a')]++;
        for(auto i:t) memo[int(i - 'a')]--;

        for(auto i:memo) if(i) return false;

        return true;
    }
};
