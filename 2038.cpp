class Solution {
public:
    bool winnerOfGame(string colors) {
        char type = colors[0];
        int size = 1;

        int n = colors.length();
        colors += "Z";

        int turns = 0;

        for(int i=0; i<n; i++) {
            if(colors[i]==colors[i+1]) size++;
            else {
                if(size>2) {
                    if(colors[i]=='A') turns += (size-2);
                    else if(colors[i]=='B') turns -= (size-2);
                }
                type = colors[i+1];
                size = 1;
            }
        }

        if(turns>0) return true;
        return false;
    }
};