class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy && t==1) return false; 

        int x = sx-fx;
        int y = sy-fy;

        if(x<0) x = -1*x;
        if(y<0) y = -1*y;

        if(x<y) {
            if(x+(y-x)<=t) return true;
        }
        else {
            if(y+(x-y)<=t) return true;
        }

        return false;
    }
};