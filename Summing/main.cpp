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
int n, q;
vector<pair<ll, ll> > v;
int queries[maxn];
map<ll, vector<ll> > graph;
map<ll, bool> visited;
ll arr[maxn];
vector<ll> ret;
void dfs(ll node){
    visited[node] = true;
    for(int i = 0; i < (int)graph[node].size(); i ++){
        ll nxt = graph[node][i];
        if(visited[nxt])continue;
        arr[nxt] += arr[node];
        dfs(nxt);
    }
}
void bs(ll num){
    int levo = 0, desno = maxn - 1;
    int mid, rr = -1;
    while(levo <= desno){
        mid = (levo + ((desno - levo) >> 1));
        if(arr[mid] <= num){
            levo = mid + 1;
            rr = mid;
        }
        else{
            desno = mid - 1;
        }
    }
    if(rr == -1){
        printf("none\n");
    }
    else{
        printf("%d\n", arr[rr]);
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    ll num, predecessor;
    for(int i = 0; i < n; i ++){
        cin >> num >> predecessor;
        v.push_back(make_pair(num, predecessor));
        arr[i] = 0;
    }
    for(int i = 0; i < q; i ++){
        cin >> queries[i];
    }
    vector<ll> tmp;
    for(int i = 0; i < n; i ++){
        num = v[i].first;
        predecessor = v[i].second;
        if(predecessor == -1){
            tmp.push_back(i);
        }
        graph[predecessor].push_back(i);
        arr[i] += num;
    }
    for(int i = 0; i < (int)tmp.size(); i ++){
        if(!visited[tmp[i]]){
            dfs(tmp[i]);
        }
    }
    for(int i = 0; i < maxn; i ++){
        if(!visited[i]){
            arr[i] = inf;
        }
    }

    sort(arr, arr + maxn);
    for(int i = 0; i < q; i ++){
        bs(queries[i]);
    }
    return 0;
}
