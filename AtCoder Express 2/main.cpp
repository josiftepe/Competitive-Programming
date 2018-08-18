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
const int maxn = 200006;
int n, m, q;
vector<int> graph[maxn];
pair<int, int> queries[maxn];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        graph[a].push_back(b);
    }
    for(int i = 0; i < n; i ++){
        sort(graph[i].begin(), graph[i].end());
    }
    for(int i = 0; i < q; i ++){
        cin >> queries[i].first >> queries[i].second;
        queries[i].first --;
        queries[i].second --;
    }
    int i, j, a, b;
    int ret = 0;
    for(i = 0; i < q; i ++){
        a = queries[i].first;
        b = queries[i].second;
        ret = 0;
        for(j = a; j <= b; j ++){
            ret += (int)(lower_bound(graph[j].begin(), graph[j].end(), b + 1) - graph[j].begin());
        }
        cout << ret  << "\n";
    }
    
    return 0;
}
