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
const int maxn = 2005;
int n;
struct node{
    int A, B;
    int cost;
    node (){}
    node(int _a, int _b, int _c){
        A = _a;
        B = _b;
        cost = _c;
    }
    bool operator < (const node &other)const{
        return cost < other.cost;
    }
};
vector<node> v;
vector<pair<int, int> > graph[maxn];
int parent[100001];
int root(int i){
    while(parent[i] != i){
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}
void unite(int a, int b){
    parent[root(a)] = root(b);
}
bool fnd(int a, int b){
    return root(a) == root(b);
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i ++){
        parent[i] = i;
        int b;
        for(int j = i + 1; j < n; j ++){
            cin >> b;
            v.push_back(node(i, j, b));
        }
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i ++){
        int S = v[i].A;
        int E = v[i].B;
        if(!fnd(S, E)){
            graph[S].push_back(make_pair(E, v[i].cost));
            graph[E].push_back(make_pair(S, v[i].cost));
            unite(S, E);
        }
    }
    for(int i = 0; i < n; i ++){
        cout << (int)graph[i].size() << " ";
        sort(graph[i].begin(), graph[i].end());
        vector<int> vv;
        for(int j = 0; j < (int)graph[i].size(); j ++){
            cout << graph[i][j].first + 1 << " ";
        }
      
        cout << "\n";
    }
    return 0;
}
