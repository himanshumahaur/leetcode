int m = 1000000007;

long long getseq(set<int> order) {
    static map<set<int>, int> myhash;
    long long ans = 0;
    if(order.size()) {
        for(auto i:order) {
            if((i<0 && !order.contains(-i)) || (i>0)) {
                set<int> temp = order;
                temp.erase(i);
                if(myhash.count(temp)) {
                    ans += myhash[temp];
                }
                else {
                    ans += getseq(temp);
                }
            }
            ans = ans % m;
        }
    }
    else {
        return 1;
    }
    myhash[order] = ans; 
    return ans;
}

class Solution {
public:
    int countOrders(int n) {
        set<int> order;
        for(int i=0; i<n; i++) {
            order.insert(i+1);
            order.insert(-i-1);
        }
        int res  = getseq(order);
        return res;
    }
};