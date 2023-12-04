class Solution {
public:
    string largestGoodInteger(string num) {
        unordered_map<char, int> memo;

        char max = char(0);

        for(int i=0; i<3; i++) {
            memo[num[i]]++;
        }

        if(memo.size()==1) max = num[0];

        for(int i=3; i<num.size(); i++) {
            memo[num[i]]++;

            if(memo[num[i-3]]==1) memo.erase(num[i-3]);
            else memo[num[i-3]]--;

            if(memo.size()==1 && num[i]>max) max = num[i];
        }

        string res;

        if(!max) return res;

        for(int i=0; i<3; i++) {
            res += max;
        }

        return res;
    }
};