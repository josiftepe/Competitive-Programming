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
const ll MOD = 1e9 +  7;
int n, k;
vector<int> graph[maxn];
int arr[maxn];
ll dp[maxn][4];
void dfs(int at, int prev){
    for(int neighbour : graph[at]){
        if(neighbour == prev) continue;
        dfs(neighbour, at);
    }
    for(int i = 0; i < 3; i ++){
        if(arr[at] != -1 and arr[at] != i) continue;
        dp[at][i] = 1;
        for(int neighbour : graph[at]){
            if(neighbour == prev) continue;
            ll sum = 0;
            for(int color = 0; color < 3; color ++){
                if(color == i) continue;
                sum += dp[neighbour][color];
            }
            dp[at][i] *= sum;
            dp[at][i] %= MOD;
        }
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
//    ifstream cin("in.txt");
    ifstream cin("barnpainting.in");
    ofstream cout("barnpainting.out");
    cin >> n >> k;
    for(int i = 0; i < n - 1; i ++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(arr, -1, sizeof arr);
    for(int i = 0; i < k; i ++){
        int b, c;
        cin >> b >> c;
        c --;
        arr[b] = c;
    }
    dfs(1, -1);
    ll ret = dp[1][0];
    ret += dp[1][1];
    ret %= MOD;
    ret += dp[1][2];
    ret %= MOD;
    cout << ret << endl;
    return 0;
}
