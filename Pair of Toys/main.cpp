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
const int maxn = 200006;
ll n, k;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if(n + 1 == k){
        cout << (n / 2LL) << endl;
        return 0;
    }
    if(k > n){
        if(n * 2LL - 1LL < k)return 0 * printf("0");
    }
    if(n >= k){
        cout << (max(0LL, k - 1LL) / 2LL) << endl;
    }
    else{
        ll t = (n * 2LL);
        cout << (t - k + 1) / 2LL << endl;
    }
    return 0;
}
