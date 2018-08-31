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
int n, x;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for(int i = 1; i <= 1000; i ++){
        if(abs(n - x) == abs(i - 1)){
            return 0 * printf("%d\n", i);
        }
    }
    return 0;
}
