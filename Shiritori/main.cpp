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
int n;
string arr[105];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    string last = arr[0];
    string curr;
    map<string, bool> visited;
    visited[last] = true;
    for(int i = 1; i < n; i ++){
        curr = arr[i];
        if(visited[curr]){
            return 0 * printf("No\n");
        }
        visited[curr] = true;
        if(curr[0] != last[(int)last.size() - 1]){
            return 0 * printf("No\n");
        }
        last = curr;
    }
    cout << "Yes\n";
    return 0;
}
