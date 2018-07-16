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
int n, q;
vector<int> graph[maxn];
queue<int> st;
int sz[maxn];
void dfs(int node, int parent){
    int sosed;
    st.push(node);
    sz[node] = 1;
    for(int i = 0; i < graph[node].size(); i ++){
        sosed = graph[node][i];
        if(sosed == parent){
            continue;
        }
        dfs(sosed, node);
        sz[node] += sz[sosed];
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 2; i <= n; i ++){
        int b;
        cin >> b;
//        b --;
        graph[i].push_back(b);
        graph[b].push_back(i);
    }
    dfs(1, 0);
    vector<int> v;
    map<int, int> mapa;
    int ii = 0;
    while(!st.empty()){
        v.push_back(st.front());
        mapa[st.front()] = ii;
        ii ++;
//        cout << st.front() <<  " ";
        st.pop();
        
    }
    cout << endl;
    for(int i = 1; i <= n; i ++){
        sz[i] --;
//        cout << i << " " << sz[i] << endl;
    }
    int a, b;
    vector<int> ret;
    for(int i = 0; i < q; i ++){
        cin >> a >> b;
        b --;
        if(mapa[a] + b < n and sz[a] >= b){
            cout << v[mapa[a] + b] << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}
