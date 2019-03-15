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
const int  maxn = 5e4 + 100;
struct candle{
    int h, c;
};

candle arr[maxn];
const ll MOD = 1e9 + 7;
int n, k;

void add_self(ll &a, ll b){
    a += b;
    if(a >= MOD){
        a -= MOD;
    }
}
class fenwick{
public:
    ll tree[maxn + 10];
    fenwick(){
        for(int i = 0; i <= maxn; i ++){
            tree[i] = 0;
        }
    }
    void update(int idx, ll new_val){
        while(idx <= maxn){
            add_self(tree[idx], new_val);
            idx += (idx & -idx);
        }
    }
    ll query(int idx){
        ll sum = 0;
        while(idx > 0){
            add_self(sum, tree[idx]);
            idx -= (idx & -idx);
        }
        return sum;
    }
};
fenwick F[1 << 7];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i ++){
        cin >> arr[i].h >> arr[i].c;
        --arr[i].c;
    }
    F[0].update(1, 1);
    for(int i = 0; i < n; i ++){
        ++arr[i].h;
        for(int j = 0; j < (1 << k); j ++){
            ll tmp = F[j].query(arr[i].h - 1);
            F[j | (1 << arr[i].c)].update(arr[i].h, tmp);
        }
    }
    cout << F[(1 << k) - 1].query(maxn) << endl;
    return 0;
}
