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
const int maxn = 1e5 + 10;
const ll MOD =  1234567LL;
int n;
vector<int> graph[maxn], rev_graph[maxn];
bool visited[maxn];
stack<int> st;
void topological_sort(int node){
    visited[node] = true;
    int sosed;
    for(int i = 0; i < (int)graph[node].size(); i ++){
        sosed = graph[node][i];
        if(visited[sosed])continue;
        topological_sort(sosed);
    }
    st.push(node);
}
vector<int> cycle;
void dfs(int node){
    visited[node] = true;
    cycle.push_back(node);
    int sosed;
    for(int i = 0; i < (int)rev_graph[node].size(); i ++){
        sosed = rev_graph[node][i];
        if(visited[sosed])continue;
        dfs(sosed);
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t --){
        cin >> n;
        map<pair<int, int>, bool> edges;
        for(int i = 0; i < maxn; i ++){
            graph[i].clear();
            rev_graph[i].clear();
        }
        for(int i = 0; i < n; i ++){
            int a;
            cin >> a;
            a --;
            graph[i].push_back(a);
            edges[make_pair(i, a)] = true;
            rev_graph[a].push_back(i);
        }
        while(!st.empty()){
            st.pop();
        }
        memset(visited, false, sizeof visited);
        for(int i = 0; i < n; i ++){
            if(!visited[i]){
                topological_sort(i);
            }
        }
        memset(visited, false, sizeof visited);
        map<int, int> mapa;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                cycle.clear();
                dfs(node);
                mapa[(int)cycle.size()] ++;
                 
            }
        }
        string ret = "";
        for(int i = 3; i <= n; i ++){
            if(mapa[i] > 0){
                ret = "B";
                break;
            }
        }
        if(ret != ""){
            cout << ret << endl;
            continue;
        }
        if(mapa[2] > 1){
            cout << "A\n";
            continue;
        }
        int A = cycle[0];
        int B = cycle[1];
        bool ok = true;
        for(map<pair<int, int>, bool>::iterator it = edges.begin(); it != edges.end(); it ++){
            if(it -> first.second == A || it -> first.second == B){
                ok = true;
            }
            else{
                ok = false;
                break;
            }
             
        }
        if(ok){
            cout << "BOTH\n";
        }
        else{
            cout << "A\n";
        }
         
    }
    return 0;
}
