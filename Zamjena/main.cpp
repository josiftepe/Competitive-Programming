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
const int maxn = 50005;
int n;
string A[maxn], B[maxn];
map<string, string> mapa;
map<string, vector<string> > graph;
map<string, string> color;
bool number(string &s){
    if(s[0] >= '0' and s[0] <= '9') return true;
    return false;
}
map<string, bool> visited;
void bfs(string &s, string &color){
    queue<string> q;
    q.push(s);
    string node;
    while(!q.empty()){
        node = q.front();
        q.pop();
        if(mapa.find(node) != mapa.end()){
            if(mapa[node] != color){
                cout << "NE\n";
                exit(0);
            }
        }
        if(mapa.find(node) == mapa.end())
            mapa[node] = color;
        for(int i = 0; i < (int)graph[node].size(); i ++){
            string nxt = graph[node][i];
            if(!visited[nxt]){
                visited[nxt] = true;
                q.push(nxt);
                if(mapa.find(nxt) != mapa.end()){
                    if(mapa[nxt] != color){
                        cout << "NE\n";
                        exit(0);
                    }
                }
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    for(int i = 0; i < n; i ++){
        if(number(A[i]) and number(B[i]) and A[i] != B[i]){
            return 0 * printf("NE\n");
        }
        if(!number(A[i]) and !number(B[i])){
            graph[A[i]].push_back(B[i]);
            graph[B[i]].push_back(A[i]);
        }
        else if(!number(A[i]) and number(B[i])){
            if(mapa.find(A[i]) != mapa.end() and mapa[A[i]] != B[i])return 0 * printf("NE\n");
            mapa[A[i]] = B[i];
            color[A[i]] = B[i];
        }
        else if(number(A[i]) and number(A[i])){
            if(mapa.find(B[i]) != mapa.end() and mapa[B[i]] != A[i])return 0 * printf("NE\n");
            color[B[i]] = A[i];
            mapa[B[i]] = A[i];
        }
    }
    for(map<string, string>::iterator it = color.begin(); it != color.end(); it ++){
        string tmp = it -> first;
        if(!visited[tmp]){
            bfs(tmp, it -> second);
        }
    }
    cout << "DA" << endl;
    return 0;
}
