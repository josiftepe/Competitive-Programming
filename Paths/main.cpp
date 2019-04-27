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
int n, m, k;
vector<int> graph[maxn];
int color[maxn];
ll dp[maxn][1 << 6];
ll rek(int at, int bitmask, int sz) {
    ll &ret = dp[at][bitmask];
    if(ret != -1) {
        return ret;
    }
    ret = 0;
    if(sz > 1) {
        ++ret;
    }
    for(int i = 0; i < (int)graph[at].size(); ++i) {
        if(bitmask & (1 << color[graph[at][i]])) {
            continue;
        }
        int neigh = graph[at][i];
        ret += rek(graph[at][i], bitmask | (1 << color[neigh]), sz + 1);
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) {
        cin >> color[i];
        --color[i];
    }
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll ret = 0;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; ++i) {
        ret += rek(i, (1 << color[i]), 1);
    }
    cout << ret << endl;
    return 0;
}
