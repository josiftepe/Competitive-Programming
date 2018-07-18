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
const int INF = (1 << 30);
const ll inf = (1LL << 60LL);
const int maxn = 1e5 + 10;
ll mat[22][22];
int n, m;
ll K;
map<ll, int> dp[22][22];
int till;
ll ret;
void rek(int i, int j, ll curr, int steps){
    curr ^= mat[i][j];
    if(steps == till){
        dp[i][j][curr] ++;
        return;
    }
    if(i + 1 < n){
        rek(i + 1, j, curr, steps + 1);
    }
    if(j + 1 < m){
        rek(i, j + 1, curr, steps + 1);
    }
}
void rek2(int i, int j, ll curr, int steps){
    if(steps == n + m - 2 - till){
        ret += dp[i][j][K ^ curr];
        return;
    }
    curr ^= mat[i][j];
    if(i > 0){
        rek2(i - 1, j, curr, steps + 1);
    }
    if(j > 0){
        rek2(i, j - 1, curr, steps + 1);
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> m  >> K;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> mat[i][j];
        }
    }
    till = (n + m - 2) >> 1;
    rek(0, 0, 0, 0);
    rek2(n - 1, m - 1, 0, 0);
    cout << ret << endl;
    return 0;
}

