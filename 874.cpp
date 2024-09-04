class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<int, vector<int>> mem;

        for(auto i:obstacles) {
            mem[i[0]].push_back(i[1]);
            mem[i[1]].push_back(i[0]);
        }

        for(auto &i:mem) sort(i.second.begin(), i.second.end());

        for(auto i:mem) {
            cout << i.first << ": ";
            for(auto j:i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
        

        int d = 0;

        int x = 0;
        int y = 0;

        for(auto c:commands) {
            if(c==-2) {
                d-=1;
                d%=4;
            }
            else if(c==-1) {
                d+=1;
                d%=4;
            }
            else {
                int found = INT_MAX;
                switch(d) {
                    case 0:
                        for(auto i:mem[x]) if(y<=i && i<=y+c) {
                            found = i-1;
                            break;
                        }
                        if(found!=INT_MAX) y = found;
                        else y += c;
                        break;
                    case 1:
                        for(auto i:mem[y]) if(x<=i && i<=x+c) {
                            found = i-1;
                            break;
                        }
                        if(found!=INT_MAX) x = found;
                        else x += c;
                        break;
                    case 2:
                        for(auto i:mem[x]) if(y<=i && i<=y+c) y = i;
                        if(found!=INT_MAX) y = found-1;
                        else y -= c;
                        break;
                    case 3:
                        for(auto i:mem[y]) if(x<=i && i<=x+c) found = i;
                        if(found!=INT_MAX) x = found-1;
                        else x -= c;
                        break;
                }
                cout << x << " " << y << " " << d << endl;
            }
        }

        return pow(x, 2) + pow(y, 2);
    }
};