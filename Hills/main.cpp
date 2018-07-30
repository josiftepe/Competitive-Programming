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
int n;
int arr[5555];
int dp[5555][2555][3];
int rek(int at, int built, int up){
    if(built == 0){
        return 0;
    }
     if(at >= n){
        if(dp[at][built][up] == -1){
            return INF;
        }
        return dp[at][built][up];
    }
    if(dp[at][built][up] != -1){
        return dp[at][built][up];
    }
    int ret = INF;
    ret = rek(at + 1, built, 0);
    ret = min(ret, rek(at + 1, built, 1) + max(arr[at] - arr[at + 1] + 1, 0));
    if(up == 1){
        int nxt = min(arr[at + 1], arr[at] - 1);
        int cost = arr[at + 1] - nxt;
        ret = min(ret, rek(at + 2, built - 1, 0) + cost);
        int cc = cost + max(nxt - arr[at + 2] + 1, 0);
        ret = min(ret, rek(at + 2, built - 1, 1) + cc);
    }
    return dp[at][built][up] = ret;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= ((n + 1) >> 1); i ++){
        cout << min(rek(0, i, 1), rek(0, i, 0)) << " ";
    }
    return 0;
}
