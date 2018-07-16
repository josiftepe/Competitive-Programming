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
const int maxn = 3e5 + 5;
int n;
ll arr[maxn];
ll prefSum[maxn];
ll maxx[maxn];
ll query(int i, int j){
    return prefSum[j] - prefSum[i - 1];
}
vector<ll> v[maxn];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        sum += arr[i];
        prefSum[i] = sum;
        maxx[i] = 0;
    }
    ll mxx = 0;
    map<ll, vector<int> > mapa;
    for(int i = 0; i < n; i ++){
        mapa[query(0, i)].push_back(i);
        maxx[i] = max(maxx[i], query(0, i));
    }
    for(int i = n - 1; i >= 0; i --){
        if(mapa.find(query(i, n - 1)) != mapa.end()){
            ll tmp = query(i, n - 1);
            if(mapa[tmp][0] < i){
                mxx = max(mxx, tmp);
            }
        }
    }
    cout << mxx << endl;
    return 0;
}

