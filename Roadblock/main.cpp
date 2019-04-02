#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1005;
const ll inf = (1LL << 56LL);
int n, m;
ll F;
vector<pair<int, int> > graph[maxn];
struct node{
    int idx;
    ll cost;
    node (){}
    node(int i, ll c){
        idx = i;
        cost = c;
    }
    bool operator < (const node& tmp) const {
        return cost > tmp.cost;
    }
};
bool visited[maxn];
ll dist[maxn];
int parent[maxn];
void dijkstra(){
    for(int i = 0; i < n; i ++){
        visited[i] = false;
        dist[i] = inf;
        parent[i] = -1;
    }
    dist[0] = 0;
    priority_queue<node> q;
    q.push(node(0, 0));
    while(!q.empty()){
        node tmp = q.top();
        q.pop();
        if(visited[tmp.idx]) continue;
        visited[tmp.idx] = true;
        for(int i = 0; i < (int)graph[tmp.idx].size(); i ++){
            int nxt = graph[tmp.idx][i].first;
            ll weight = graph[tmp.idx][i].second;
            if(!visited[nxt] and tmp.cost + weight < dist[nxt]){
                dist[nxt] = tmp.cost + weight;
                q.push(node(nxt, dist[nxt]));
                parent[nxt] = tmp.idx;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ifstream cin("rblock.in");
    ofstream cout("rblock.out");
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        a --;
        b --;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    dijkstra();
    ll S = dist[n - 1];
    ll ret = 0;
    int A = 0;
    int B = n - 1;
    vector<int> v;
    while(B != A){
        v.push_back(B);
        B = parent[B];
    }
    v.push_back(B);
    for(int i = 0; i + 1 < (int)v.size(); i ++){
        int idx_A = -1;
        for(int j = 0;  j < graph[v[i]].size(); j ++){
            if(graph[v[i]][j].first == v[i + 1]){
                graph[v[i]][j].second *= 2;
                idx_A = j;
                break;
            }
        }
        int idx_B = -1;
        for(int j = 0; j < graph[v[i + 1]].size(); j ++){
            if(graph[v[i + 1]][j].first == v[i]){
                graph[v[i + 1]][j].second *= 2;
                idx_B = j;
                break;
            }
        }
        dijkstra();
    ret = max(ret, dist[n - 1]);
        graph[v[i]][idx_A].second /= 2;
        graph[v[i + 1]][idx_B].second /= 2;
    }
    cout << ret - S << endl;
    return 0;
}
