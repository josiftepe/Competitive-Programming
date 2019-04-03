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
const int  maxn = 21;
const ll MOD = 1e9 +  7;
int n, B;
int mat[maxn][maxn];
vector<pair<int, int > > bonus[maxn];
int dp[1 << maxn] {-INF};

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    ifstream cin("dec.in");
    ofstream cout("dec.out");
    cin >> n >> B;
    for(int i = 0; i < B; i ++){
        int k, p, a;
        cin >> k >> p >> a;
        k --;
        bonus[k].push_back(make_pair(p, a));
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < n; i ++){
        sort(bonus[i].begin(), bonus[i].end());
    }
    dp[0] = 0;
    for(int mask = 1; mask < (1 << n); mask ++){
        int at = __builtin_popcount(mask);
        for(int i = 0; i < n; i ++){
            if(mask & (1 << i)){
                int new_mask = mask ^ (1 << i);
                dp[mask] = max(dp[mask], dp[new_mask] + mat[i][at - 1]);
            }
        }
        for(int i = 0; i < (int) bonus[at - 1].size(); i ++){
            if(dp[mask] < bonus[at - 1][i].first) break;
            dp[mask] += bonus[at - 1][i].second;
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}
