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
const int maxn = 3e5 + 5;
int n;
string s;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    
    ll ret = 0;
    map<string, int> cnt;
    
    for (int mask = 0; mask < (1 << n); mask ++){
        string red = "", blue = "";
        for (int i = 0; i < n; i ++){
            if (mask & (1 << i)) {
                red += s[i];
            }
            else {
                blue += s[i];
            }
        }
        string curr = red + "." +  string(blue.rbegin(), blue.rend());
        cnt[curr] ++;
    }
    
    for (int mask = 0; mask < (1 << n); mask ++) {
        string red = "", blue = "";
        for (int i = 0; i < n; i ++){
            if(mask & (1 << i)){
                red += s[i + n];
            }
            else{
                blue += s[i + n];
            }
        }
        string curr = string(red.rbegin(), red.rend()) + "." +  blue;
        ret += cnt[curr];
    }
    cout << ret << endl;
    return 0;
}
