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
int arr[maxn];
int x;
map<int, int> mapa;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        mapa[arr[i]] ++;
    }
    int ret = INF;
    for(int i = 0; i < n; i ++){
        if(mapa[arr[i]] >= 2){
            ret = min(ret, 0);
        }
        int tmp = (arr[i] & x);
        if(tmp != arr[i]){
            if(mapa[tmp] + 1 >= 2){
                ret = min(ret, 1);
            }
        }
    }
    mapa.clear();
    for(int i = 0; i < n; i ++){
        mapa[(arr[i] & x)] ++;
    }
    for(map<int, int>::iterator it = mapa.begin(); it != mapa.end(); it ++){
        if(it -> second >= 2){
            ret = min(ret, 2);
        }
    }
    if(ret == INF)ret = -1;
    cout << ret << endl;
    return 0;
}
