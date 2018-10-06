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
const int maxn = 3e5 + 10;
ll n, m;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if(n == m){
        return 0 * printf("1\n");
    }
    ll ret = 0;
    for(ll i = 1; i * i <= m; i ++){
        if(m % i == 0){
            if(m / i >= n){
                ret = max(ret, i);
            }
            if(i != m / i){
                if(m / (m / i) >= n){
                    ret = max(ret, m / i);
                }
            }
        }
    }
    cout << ret << endl;
    return 0;
}
