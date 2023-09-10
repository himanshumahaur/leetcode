// int m = 1000000007;

// long long getseq(set<int> order) {
//     static map<set<int>, int> myhash;
//     long long ans = 0;
//     if(order.size()) {
//         for(auto i:order) {
//             if((i<0 && !order.contains(-i)) || (i>0)) {
//                 set<int> temp = order;
//                 temp.erase(i);
//                 if(myhash.count(temp)) {
//                     ans += myhash[temp];
//                 }
//                 else {
//                     ans += getseq(temp);
//                 }
//             }
//             ans = ans % m;
//         }
//     }
//     else {
//         return 1;
//     }
//     myhash[order] = ans; 
//     return ans;
// }

// class Solution {
// public:
//     int countOrders(int n) {
//         set<int> order;
//         for(int i=0; i<n; i++) {
//             order.insert(i+1);
//             order.insert(-i-1);
//         }
//         int res  = getseq(order);
//         return res;
//     }
// };

int m = 1000000007;

int mult(int a, int b) {
    int res = 0;
    if(a<b) {
        int t = b;
        b = a;
        a = t;
    }
    for(int i=0; i<b; i++) {
        res += a;
        if(res>m) {
            res = res%m;
        }
    }
    return res;
}

int getseq(int n) {
    static unordered_map<int, int> hash;
    int ans = 0;
    if(n>2) {
        for(int i=1; i<=n-1; i++) {
            if(hash.count(n-2)) {
                ans += mult(i, hash[n-2]);
            }
            else {
                hash[n-2] = getseq(n-2);
                ans += mult(i, hash[n-2]);
            }
            ans = ans % m;
        }
    }
    else {
        return 1;
    }
    hash[n] = ans;
    return ans;
}

class Solution {
public:
    int countOrders(int n) {
        return getseq(2*n);
        return 0;
    }
};