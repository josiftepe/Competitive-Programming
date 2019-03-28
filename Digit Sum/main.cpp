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
const int  maxn = 1e4 + 10;
const ll MOD = 1e9 +  7;
string s;
int D, n;
int dp[10005][105][3];
int rek(int at, int modulo, int is_bigger){
    if(at == n){
        if(modulo == 0){
            return 1;
        }
        return 0;
    }
    if(dp[at][modulo][is_bigger] != -1){
        return dp[at][modulo][is_bigger];
    }
    int ret = 0;
    int till;
    if(is_bigger == 0){
        till = (s[at] - '0');
    }
    else{
        till = 9;
    }
    for(int i = 0; i <= till; i ++){
        int new_modulo = modulo;
        new_modulo += i;
        new_modulo %= D;
        int big_tmp = is_bigger;
        if(is_bigger == 0 and i < (s[at] - '0')){
            big_tmp = 1;
        }
        ret += rek(at + 1, new_modulo, big_tmp);
        if(ret >= MOD){
            ret -= MOD;
        }
    }
    return dp[at][modulo][is_bigger] = ret;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    ifstream  cin("in.txt");
    cin >> s >> D;
    n = (int)s.length();
    memset(dp, -1, sizeof dp);
    int ret = rek(0, 0, 1);
    ret -= 1;
    if(ret < 0){
        ret += MOD;
    }
    cout << ret << endl;
    return 0;
}
