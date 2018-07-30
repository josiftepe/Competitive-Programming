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
const int maxn = 100006;
int n;
int x[55], y[55];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int sum_x = 0, sum_y = 0;
    for(int i = 0; i < n; i ++){
        cin >> x[i];
        sum_x += x[i];
    }
    for(int i = 0; i < n; i ++){
        cin >> y[i];
        sum_y += y[i];
    }
    sum_x -= sum_y;
    if(sum_x >= 0){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
}
