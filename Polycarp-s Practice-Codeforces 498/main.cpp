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
int n, k;
int arr[maxn];
int dp[2005][2005];
bool can(int x){
    int cnt = 1;
    int sum = 0;
    for(int i =0; i < n;  i ++){
        if(sum + arr[i] <= x){
            sum += arr[i];
        }
        else{
            if(cnt == k  || arr[i] > x){
                return false;
            }
            cnt ++;
            sum = arr[i];
        }
    }
    return true;
}
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first < b.first){
        return true;
    }
    if(a.first == b.first){
        return a.second > b.second;
    }
    return false;
}
bool c[maxn];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int sum = 0;
    vector<pair<int, int > > v;
    for(int i =0 ;i < n; i ++){
        cin >> arr[i];
        v.push_back(make_pair(arr[i], i));
        
        
    }
    sort(v.rbegin(), v.rend(), cmp);
    vector<int> idx;
    int ret =0 ;
    memset(c, false, sizeof c);
    for(int i =0; i < k; i ++){
        idx.push_back(v[i].second);
        c[v[i].second] = true;
        ret += v[i].first;
    }
    cout << ret << endl;
    int cnt = 0;
    for(int i = n - 1; i >= 0; i --){
        if(c[i]){
            c[i] = false;
            break;
        }
    }
    for(int i = 0; i < n; i ++){
        cnt ++;
        if(c[i]){
            cout << cnt << " " ;
//            cout << i + 1 << endl;
            cnt = 0;
        }
    }
//    if(!c[n - 1])
    cout << cnt << endl;
    return 0;
}
