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
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (1 << 30);
const ll inf = (1LL << 60LL);
const ll MOD =  1234567LL;
const int maxn = 1e5 + 10;
int n, k;
string s;
int dp[55][55][105];
int rek(int at, int k_left, int last_used){
    if(k_left == 0){
        return 0;
    }
    if(at == n){
        return INF;
    }
    if(dp[at][k_left][last_used] != -1){
        return dp[at][k_left][last_used];
    }
    int ret = INF;
    int curr = (s[at] - 'a');
    if(last_used + 1 < curr){
        ret = min(ret, rek(at + 1, k_left - 1, curr) + curr + 1);
    }
    ret = min(ret, rek(at + 1, k_left, last_used));
    return dp[at][k_left][last_used] = ret;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());
    memset(dp, -1, sizeof dp);
    int ret = INF;
    for(int i =0 ; i < n; i ++){
        ret = min(ret, rek(i + 1, k - 1, (s[i] - 'a')) + (s[i] - 'a') + 1);
    }
    if(ret >= INF)ret = -1;
    cout << ret;
    return 0;
}
