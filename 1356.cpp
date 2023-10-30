bool cmp(const int& a, const int& b) {
    int nosa = __builtin_popcount(a);
    int nosb = __builtin_popcount(b);
    if(nosa<nosb) return true;
    if(nosa>nosb) return false;
    return a < b;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};