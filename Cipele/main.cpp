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
int n, m;
vector<ll> L, R;
bool check(ll x){
    int cnt = 0;
    for(int i = 0; i < m; i ++){
        if(cnt >= n){
            return true;
        }
        if(llabs(R[i] - L[cnt]) > x){
            continue;
        }
        cnt ++;
    }
    return (cnt >= n);
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    ll num;
    for(int i = 0; i < n; i ++){
        cin >> num;
        L.push_back(num);
    }
    for(int i = 0; i < m; i ++){
        cin >> num;
        R.push_back(num);
    }
    if(n > m){
        swap(L, R);
    }
    n = (int)L.size();
    m = (int)R.size();
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    ll levo = 0, desno = (1LL << 40LL);
    ll ret = -1;
    while(levo <= desno){
        ll mid = levo + ((desno - levo) / 2LL);
        if(check(mid)){
            desno = mid  -1;
            ret = mid;
        }
        else{
            levo = mid +1;
        }
    }
    cout << ret << endl;
    return 0;
}
