class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0;
        int n = garbage.size();
        int m = 0, p = 0, g = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<garbage[i].size(); j++) {
                res++;
                switch(garbage[i][j]) {
                    case 'M':
                        m = i;
                        break;
                    case 'P':
                        p = i;
                        break;
                    case 'G':
                        g = i;
                        break;
                }
            }
        }

        int sum = 0;

        for(int i=0; i<n-1; i++) {
            sum += travel[i];
            if(i==m-1) res += sum;
            if(i==p-1) res += sum;
            if(i==g-1) res += sum;
        }

        return res;
    }
};