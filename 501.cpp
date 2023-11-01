class Solution {
public:
    void getcount(TreeNode* root, unordered_map<int, int>& hash, vector<int>& res, int& max) {
        if(root) {
            hash[root->val]++;
            if(max<hash[root->val]) {
                res.clear();
                max = hash[root->val];
            }
            if(max==hash[root->val]) {
                res.push_back(root->val);
            }
            getcount(root->left, hash, res, max);
            getcount(root->right, hash, res, max);
        }
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        unordered_map<int, int> hash;
        int max = 0;
        getcount(root, hash, res, max);
        return res;
    }
};