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
const int maxn = 1e6 + 5;
int n, k;
ll arr[maxn];
ll pref[maxn];
ll query(int i, int j){
    return pref[j] - pref[i - 1];
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    ll sum = 0;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        sum += arr[i];
        pref[i] = sum;
    }
    
     ll ret = 0;
    
    for(int i = 0; i < n; i ++){
        if(i + k - 1 >= n)break;
        ret = max(ret, query(i, i + k - 1));
    }
    cout << ret << endl;
    return 0;
}

