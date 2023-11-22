class Solution {
public:
    static bool cmp(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        int ai = a.first.first;
        int aj = a.first.second;

        int bi = b.first.first;
        int bj = b.first.second;

        if(ai+aj<bi+bj) {
            return true;
        }
        else if(ai+aj>bi+bj) {
            return false;
        }
        else {
            return aj<bj;
        }
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        vector<pair<pair<int, int>, int>> bag;

        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums[i].size(); j++) {
                bag.push_back({{i, j}, nums[i][j]});
            }
        }

        sort(bag.begin(), bag.end(), cmp);

        for(auto i:bag) {
            res.push_back(i.second);
        }

        return res;
    }
};