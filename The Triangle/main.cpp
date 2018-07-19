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
const ll MOD = 1234567LL;
int n;
int mat[105][105];
int dp[105][105];
int rek(int i, int j){
    if(i == n - 1){
        return mat[i][j];
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ret = 0;
    if(i + 1 < n){
        if(mat[i + 1][j] != -1)
            ret = max(ret, rek(i + 1, j) + mat[i][j]);
        if(j + 1 < n and mat[i + 1][j + 1] != -1)
            ret = max(ret, rek(i + 1, j + 1) + mat[i][j]);
    }
    return dp[i][j] = ret;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    memset(mat, -1, sizeof mat);
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j <= i; j ++){
            cin >> mat[i][j];
        }
    }
    cout << rek(0, 0) << endl;
    return 0;
}

