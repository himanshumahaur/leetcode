class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> onesRow;
        vector<int> onesCol;

        for(int i=0; i<m; i++) {
            int count = 0;
            for(int j=0; j<n; j++) {
                if(grid[i][j]) count++;
            }
            onesRow.push_back(count);
        }

        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<m; j++) {
                if(grid[j][i]) count++;
            }
            onesCol.push_back(count);
        }

        vector<vector<int>> diff;

        for(int i=0; i<m; i++) {
            vector<int> temp;
            for(int j=0; j<n; j++) {
                temp.push_back(onesRow[i]+onesCol[j]-((m+n)-(onesRow[i]+onesCol[j])));
            }
            diff.push_back(temp);
        }

        return diff;
    }
};
