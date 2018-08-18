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
bool ok(int num){
    if(num % 2 == 0){
        return false;
    }
    int cnt = 0;
    for(int i = 1; i <= num; i ++){
        if(num % i == 0){
            ++cnt;
        }
    }
    return (cnt == 8);
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int ret = 0;
    for(int i = 1; i <= n; i ++){
        if(ok(i)){
            ret ++;
        }
    }
    cout << ret << endl;
    return 0;
}
