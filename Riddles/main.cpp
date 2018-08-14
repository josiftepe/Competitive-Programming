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
const int maxn = 100005;
int n, k;
int arr[maxn];
bool can(int &sz){
    vector<int> v;
    for(int i = 0; i < sz; i ++){
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    int tmp = 0;
    for(int i = 0; i < (int)v.size(); i ++){
        if(v[i] <= k){
            if(v[i] > tmp + 1){
                return false;
            }
            tmp += v[i];
            if(tmp >= k){
                return true;
            }
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    int levo, desno, mid, ret;
    while(t --){
        cin >> n >> k;
        for(int i = 0; i < n; i ++){
            cin >> arr[i];
        }
        levo = 0;
        desno = n;
        ret = INF;
        while(levo <= desno){
            mid = (levo + desno) >> 1;
            if(can(mid)){
                desno = mid - 1;
                ret = min(ret, mid);
            }
            else{
                levo = mid + 1;
            }
        }
        if(ret == INF)ret = -1;
        printf("%d\n", ret);
    }
    return 0;
}
