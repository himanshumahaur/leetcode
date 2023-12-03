class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int cost = 0;

        for(int i=1; i<points.size(); i++) {
            int ax = points[i][0];
            int ay = points[i][1];

            int bx = points[i-1][0];
            int by = points[i-1][1];

            int dx;
            int dy;

            if(ax>bx) {
                if(ay>by) {
                    dx = ax-bx;
                    dy = ay-by;
                }
                else{
                    dx = ax-bx;
                    dy = by-ay;
                }
            }
            else {
                if(ay>by) {
                    dx = bx-ax;
                    dy = ay-by;
                }
                else{
                    dx = bx-ax;
                    dy = by-ay;    
                }
            }

            int min_ = min(dx, dy);
            int max_ = max(dx, dy);

            cost += min_ + (max_ - min_);
        }

        return cost;
    }
};