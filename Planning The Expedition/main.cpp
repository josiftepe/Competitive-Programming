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
int n, m;
int arr[maxn];
int cnt[maxn];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < m; i ++){
        cin >> arr[i];
        cnt[arr[i]] ++;
    }
    for(int i = 300; i > 0; i --){
        int tmp = 0;
        for(int j = 1; j <= 100; j ++){
            tmp += (cnt[j] / i);
        }
        if(tmp >= n){
            cout << i  << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    
    return 0;
}
