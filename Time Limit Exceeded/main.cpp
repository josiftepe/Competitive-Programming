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
int n, t;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    int a, b;
    int ret = INF;
    for(int i = 0; i < n; i ++){
        cin >> a >> b;
        if(b <= t){
            ret = min(ret, a);
        }
    }
    if(ret == INF){
        cout << "TLE\n";
    }
    else{
        cout << ret << endl;
    }
    return 0;
}
 
