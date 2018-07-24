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
const int maxn = 105;
const ll MOD =  1234567LL;
ll n, k;
ll bits[maxn];
ll dp_sum[maxn][maxn];
ll dp_cnt[maxn][maxn];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    ll tmp = n - 1;
    int crt = 0;
    while(tmp){
        bits[++crt] = tmp;
        tmp >>= 1LL;
    }
    ll sum = 0;
    ll p = 0;
    for(int i = crt; i > 0; i --){
        tmp = bits[i];
        ++p;
        sum += (tmp % 2LL);
        dp_sum[i][1] = ((1LL << p) - 1);
        dp_sum[i][1] %= MOD;
        dp_cnt[i][1] = p;
        for(ll j = 2; (1LL << j) - 1 <= tmp and j <= k; j ++){
            dp_sum[i][j] = 2 * dp_sum[i + 1][j];
            dp_sum[i][j] %= MOD;
            dp_sum[i][j] += 2 * dp_sum[i + 1][j - 1];
            dp_sum[i][j] %= MOD;
            dp_sum[i][j] += dp_cnt[i + 1][j - 1];
            dp_sum[i][j] %= MOD;
            dp_cnt[i][j] = dp_cnt[i + 1][j] + dp_cnt[i + 1][j - 1];
            dp_cnt[i][j] %= MOD;
            if(tmp % 2LL == 0 and sum + 1 == j){
                dp_sum[i][j] = (dp_sum[i][j] + MOD) - ((tmp + 1) % MOD);
                dp_sum[i][j] %= MOD;
                dp_cnt[i][j] = dp_cnt[i][j] + MOD - 1;
                dp_cnt[i][j] %= MOD;
            }
        }
    }
    cout << dp_sum[1][k] % MOD << endl;
    return 0;
}

