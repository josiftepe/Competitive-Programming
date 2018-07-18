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
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (1 << 30);
const ll inf = (1LL << 60LL);
const int MAXN = 1e6 + 5;
int n, w;
vector<pair<int, ll> > graph[7001];
struct node{
    int idx;
    ll cost;
    node (){}
    node(int _i, ll _c){
        idx = _i;
        cost = _c;
    }
    bool operator < (const node &a)const{
        return cost > a.cost;
    }
};
bool visited[7001];
ll dist[7001];
ll prim(){
    for(int i = 0; i < n; i ++){
        dist[i] = inf;
        visited[i] = false;
    }
    int cnt = 0;
    priority_queue<node> q;
    q.push(node(0, 0));
    node tmp;
    ll ret = 0;
    while(!q.empty()){
        tmp = q.top();
        q.pop();
        if(visited[tmp.idx])continue;
        visited[tmp.idx] = true;
        ret += tmp.cost;
        ++cnt;
        for(int i = 0; i < graph[tmp.idx].size(); i ++){
            int nxt = graph[tmp.idx][i].first;
            ll cc = graph[tmp.idx][i].second;
            if(!visited[nxt] && dist[nxt] > cc){
                dist[nxt] = cc;
                q.push(node(nxt, cc));
            }
        }
    }
    if(cnt != n)return -1;
    return ret;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> w;
    int a, b;
    ll c;
    vector<ll> v;
    for(int i = 0; i < w; i ++){
        cin >> a >> b >> c;
        --a;
        --b;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
        cout << prim() << endl;
    }
    return 0;
}
