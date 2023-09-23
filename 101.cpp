bool check(TreeNode* a, TreeNode* b) {
    if(!a && !b) return true;
    if(!a) return false;
    if(!b) return false;

    if(a->val!=b->val) return false;
    else return (check(a->left, b->right) && check(a->right, b->left));
    
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};