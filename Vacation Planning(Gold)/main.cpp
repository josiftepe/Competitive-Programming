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
const int INF = 2e9 + 10;
const int  maxn = 2e4 + 1;

vector<pair<int, int> > graph[maxn], rev_graph[maxn];
int hubs[maxn];
int dist[201][maxn], rev_dist[201][maxn];
struct node{
    int idx;
    int cost;
    node (){}
    node (int i, int c){
        idx = i;
        cost = c;
    }
    bool operator < (const node &tmp) const {
        return cost > tmp.cost;
    }
};
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
        ifstream cin("vacationgold.in");
    ofstream cout("vacationgold.out");
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    int a, b, c;
    for(int i = 0; i < m; i ++){
        cin >> a >> b >> c;
        a --; b --;
        graph[a].push_back(make_pair(b, c));
        rev_graph[b].push_back(make_pair(a, c));
    }
    memset(dist, 127, sizeof dist);
    memset(rev_dist, 127, sizeof rev_dist);
    for(int i = 0; i < k; i ++){
        cin >> hubs[i];
        hubs[i] --;
        priority_queue<node> q;
        q.push(node(hubs[i], 0));
        dist[hubs[i]][hubs[i]] = 0;
        while(!q.empty()){
            node tmp = q.top();
            q.pop();
            if(dist[hubs[i]][tmp.idx] < tmp.cost) continue;
            for(int it = 0; it < (int)graph[tmp.idx].size(); it ++){
                int nxt_node = graph[tmp.idx][it].first;
                int weight = graph[tmp.idx][it].second;
                
                if(tmp.cost + weight < dist[hubs[i]][nxt_node]){
                    dist[hubs[i]][nxt_node] = tmp.cost + weight;
                    q.push(node(nxt_node, tmp.cost + weight));
                }
            }
        }
        q.push(node(hubs[i], 0));
        rev_dist[hubs[i]][hubs[i]] = 0;
        while(!q.empty()){
            node tmp = q.top();
            q.pop();
          
            if(rev_dist[hubs[i]][tmp.idx] < tmp.cost) continue;
            for(int it = 0; it < (int)rev_graph[tmp.idx].size(); it ++){
                int nxt_node = rev_graph[tmp.idx][it].first;
                int weight = rev_graph[tmp.idx][it].second;
                if(tmp.cost + weight < rev_dist[hubs[i]][nxt_node]){
                    rev_dist[hubs[i]][nxt_node] = tmp.cost + weight;
                    q.push(node(nxt_node, tmp.cost + weight));
                }
            }
        }
        
    }
    ll ret = 0;
    int cnt = 0;
    for(int i = 0; i < q; i ++){
        cin >> a >> b;
        a --; b --;
        int mnn = INF;
        for(int j = 0; j < k; j ++){
            if(rev_dist[hubs[j]][a] < INF and dist[hubs[j]][b] < INF){

                mnn = min(dist[hubs[j]][b] + rev_dist[hubs[j]][a], mnn);
            }
            
        }
        if(mnn == INF) continue;
        cnt ++;
        ret += mnn;
    }
    cout << cnt << endl << ret << endl;
    return 0;
    
}
