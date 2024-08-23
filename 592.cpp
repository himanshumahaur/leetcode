#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

class Solution {
public:
    string fractionAddition(string exp) {
        vector<pair<bool, pair<int, int>>> fra;
        bool neg = false;
        exp = exp + "+";
    
        if(exp[0] == '-') {
            neg = true;
            exp.erase(0, 1);
        }
        else {
            neg = false;
        }

        string str;
        for(auto i:exp) {
            if(i=='+' || i=='-') {
                string ns;
                string ds;

                bool trg = false;

                for(auto j:str) {
                    if(j=='/') trg = true;
                    else if(trg) ds += j;
                    else ns += j;
                }

                fra.push_back({neg, {stoi(ns), stoi(ds)}});
                str.clear();

                if(i=='+') neg = false;
                else neg = true;
            }
            else {
                str += i;
            }
        }

        long long int d = 1;
        long long int n = 0;

        for(auto i:fra) {
            d *= i.second.second;
        }

        for(auto i:fra) {
            long long int cur = i.second.first * d / i.second.second;
            if(i.first) n -= cur;
            else n += cur;
        }

        if(n) {
            long long int g;
            
            if(abs(n)>abs(d)) g = gcd(abs(n), abs(d));
            else g = gcd(abs(d), abs(n));
            
            if((n>0 && d<0) || (n<0 && d>0)) return "-" + to_string(abs(n)/g) + "/" + to_string(abs(d)/g);
            return to_string(abs(n)/g) + "/" + to_string(abs(d)/g);
        }
        else {
            return "0/1";
        }
    }
};