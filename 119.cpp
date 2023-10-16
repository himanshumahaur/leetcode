class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> vec;

        for(int i=0; i<n; i++) {
            vec.push_back(1);
            vector<int> tmp;
            tmp.push_back(1);
            for(int i=0; i<vec.size()-1; i++) {
                tmp.push_back(vec[i]+vec[i+1]);
            }
            vec.clear();
            vec = tmp;
        }
        vec.push_back(1);

        return vec;
    }
};