#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <fstream>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1 << 30);
const ll inf = (1LL << 60LL);
const int  maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
ll a, b;
vector<int> digits;
ll dp[20][3][10][10];
ll rek(int at, int F, int last, int before_last){
    if(at == (int)digits.size()) {
        
        if(last != -1 and before_last != -1){
            return 1;
        }
        return 0;
    }
    if(last != -1 and before_last != -1 and dp[at][F][last][before_last] != -1) {
        return dp[at][F][last][before_last];
    }
    ll ret = 0;
    int L;
    if(!F) {
        L = digits[at];
    }
    else{
        L = 9;
    }
    for(int i = 0; i <= L; ++i) {
        bool new_f = F;
        if(i < digits[at] and !F){
            new_f = true;
        }
        if(i == 0 and last == -1){
            ret += rek(at + 1, 1, last, before_last);
        }
        else if(i > 0 or last != -1){
            if(i == last or i == before_last) continue;
            ret += rek(at + 1, new_f, i, last);
        }
    }
    if(last != -1 and before_last != -1) {
        dp[at][F][last][before_last] = ret;
    }
    return ret;
}
bool is_pal(const string &s) {
    int i = 0, j = (int)s.size() - 1;
    while(i <= j) {
        if(s[i] != s[j]) return false;
        ++i;
        --j;
    }
    return true;
}
int brute_force(ll L, ll R){
    int ret = 0;
    for(ll i = L; i <= R; ++i) {
        string s = "";
        ll tmp = i;
        while(tmp){
            s += (tmp % 10) + '0';
            tmp /= 10;
        }
        reverse(s.begin(), s.end());
        bool ok = true;
        for(int j = 0; j < (int)s.size(); ++j) {
            string t = "";
            for(int k = j; k < (int)s.size(); ++k) {
                t += s[k];
                if((int)t.size() > 1 and is_pal(t)) {
                    ok = false;
                    break;
                }
            }
            if(!ok) {
                break;
            }
            
        }
        ret += ok;
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
//    ifstream cin("in.txt");
    cin >> a >> b;
    if(b - a <= 200000){
        return 0 * printf("%d\n", brute_force(a, b));
    }
    ll B = b;
    while(B){
        digits.push_back(B % 10);
        B /= 10;
    }
    reverse(digits.begin(), digits.end());
    memset(dp, -1, sizeof dp);
    ll ret = 0;
    ret += rek(0, 0, -1, -1);
    //    if(a == 0) ++a;
    B = a - 1;digits.clear();
    while(B){
        digits.push_back(B % 10);
        B /= 10;
    }
    reverse(digits.begin(), digits.end());
    memset(dp, -1, sizeof dp);
    
    cout << ret - rek(0, 0, -1, -1) << endl;
    return 0;
}



