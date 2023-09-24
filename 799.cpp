class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> cups;
        cups.push_back(vector<double>(1, poured));
        while(true) {
            vector<double> *ref = &cups[cups.size()-1];
            vector<double> &cur = *ref;
            vector<double> nxt(cur.size()+1, 0);
            for(int i=0; i<cur.size(); i++) {
                if(cur[i]>1) {
                    nxt[i] += (cur[i]-1)/2;
                    nxt[i+1] += (cur[i]-1)/2;
                    cur[i] = 1;
                }
                if(i==query_glass && cups.size()-1==query_row) {
                    return cur[i];
                }
            }
            cups.push_back(nxt);
        }
        return 0;
    }
};