class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> memo;
        for(auto path:paths) {
            memo[path[0]] = path[1];
        }
        for(auto paths:memo) {
            if(memo.count(paths.second)==0) return paths.second;
        }
        return "";
    }
};
