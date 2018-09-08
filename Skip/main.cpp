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
ll n, X;
ll arr[maxn];
ll gcd(ll a, ll b){
    if(a < b){
        swap(a, b);
    }
    
    /// gcd(b, a % b)
    ll tmp;
    while(b){
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> X;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    ll ret = llabs(arr[0] - X);
    for(int i = 1 ; i < n; i ++){
        ret = gcd(ret, llabs(arr[i] - X));
    }
    cout << ret << endl;
    return 0;
}
