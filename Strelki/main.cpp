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
const int  maxn = 3e5 + 10;
int n;
int graph[maxn];
bool deleted[maxn];
vector<pair<int, int> > v;
int furthest[maxn];
int parent[maxn];
int root(int A){
    while(A != parent[A]){
        parent[A] = parent[parent[A]];
        A = parent[A];
    }
    return A;
}
void unite(int A){
    int B = root(graph[A]);
    if(B == A){
        furthest[A] = -1;
    }
    parent[A] = B;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> graph[i];
        parent[i] = i;
        deleted[i] = false;
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i){
        int a, b;
        cin >> a >> b;
        if(a == 2){
            deleted[b] = true;
        }
        v.push_back(make_pair(a, b));
    }
    
    for(int i = 1; i <= n; ++i){
        if(!deleted[i] and graph[i] != 0){
            unite(i);
        }
    }
    vector<int> ret;
    for(int i = q - 1; i >= 0; --i){
        if(v[i].first == 1){
            int tmp = root(v[i].second);
            if(furthest[tmp] == -1){
                ret.push_back(-1);
            }
            else{
                ret.push_back(tmp);
            }
        }
        else{
            unite(v[i].second);
        }
    }
    for(int i = (int)ret.size() - 1; i >= 0; i--){
        if(ret[i] == -1){
            cout << "CIKLUS\n";
        }
        else{
            cout << ret[i] << "\n";
        }
    }
    return 0;
}
