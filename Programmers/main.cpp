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
const int maxn = 3e5 + 10;
int n, m;
int color[maxn];
int arr[maxn];
bool visited[maxn];
vector<int> graph[maxn];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    memset(color, 0, sizeof color);
    int a, b;
    int S = 0;
    queue<int> q;
    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
    }
    cin >> m;
    for(int i = 0; i < m; i ++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i ++){
        if(arr[i] == 1){
            color[i] = 1;
            q.push(i);
            ++S;
        }
        if((int)graph[i].size() == 0){
            color[i] = 0;
        }
    }
    int node;
    while(!q.empty()){
        node = q.front();
        q.pop();
        if(color[node] == 1){
            for(int i = 0; i < (int)graph[node].size(); i ++){
                int curr = graph[node][i];
                if(color[curr] == 0){
                    color[curr] = 2;
                    q.push(curr);
                }
               else if(color[curr] == 1){
                    color[curr] = 3;
                    q.push(curr);
                }
            }
        }
       else if(color[node] == 2){
            for(int i = 0; i < (int)graph[node].size(); i ++){
                int curr = graph[node][i];
                if(color[curr] == 0){
                    color[curr] = 1;
                    q.push(curr);
                }
               else  if(color[curr] == 2){
                    color[curr] = 3;
                    q.push(curr);
                }
            }
        }
        else if(color[node] == 3){
            for(int i = 0; i < (int)graph[node].size(); i ++){
                int curr = graph[node][i];
                if(color[curr] != 3){
                    color[curr] = 3;
                    q.push(curr);
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        if(color[i] == 3){
            q.push(i);
        }
    }
    memset(visited, false, sizeof visited);
    while(!q.empty()){
        node = q.front();
        q.pop();
        visited[node] = true;
        for(int i = 0; i < (int)graph[node].size(); i ++){
            int curr = graph[node][i];
            if(visited[curr])continue;
            q.push(curr);
            color[curr] = 3;
            visited[curr] = true;
        }
    }
    int ones = 0, twos = 0, threes = 0;
    for(int i = 1; i <= n; i ++){
        if(color[i] == 1) ones ++;
        if(color[i] == 2) twos ++;
        if(color[i] == 3) threes ++;
    }
    int ret = threes + max(ones, twos);
    cout << max(ret, S) << endl;
    return 0;
}
