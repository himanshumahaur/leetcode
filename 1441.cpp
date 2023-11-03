class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> stk;
        vector<string> ans;

        int i = 0;
        int num = 1;

        while(i<target.size()) {
            stk.push(num);
            ans.push_back("Push");
            num++;

            if(stk.top()==target[i]) {
                i++;
            }
            else {
                stk.pop();
                ans.push_back("Pop");
            }
        }

        return ans;
    }
};