class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> result;
        int m = img.size();
        int n = img[0].size();
        for(int i=0; i<m; i++) {
            vector<int> row;
            for(int j=0; j<n; j++) {
                int sum = 0;
                int count = 0;
                for(int p=i-1; p<=i+1; p++) {
                    for(int q=j-1; q<=j+1; q++) {
                        if(p>=0 && p<m && q>=0 && q<n) {
                            count++;
                            sum+=img[p][q];
                        }
                    }
                }
                row.push_back(sum/count);
            }
            result.push_back(row);
        }
        return result;
    }
};
