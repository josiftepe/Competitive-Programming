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
const ll INF = (1 << 30);
const ll inf = (1LL << 60LL);
const int  maxn = 2e5 + 5;
const int MOD = 1e9 + 7;
int n, k, r;
int arr[maxn];
int freq[maxn];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
//    ifstream cin("in.txt");
    cin >> n >> k >> r;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for(int i = 0; i < r; ++i) {
        int x;
        cin >> x;
        cin >> freq[x];
    }
    int j = 0, ret = INF;
    for(int i = 0; i < n; ++i) {
        while(r > 0 and j < n){
            --freq[arr[j]];
            if(freq[arr[j]] == 0){
                --r;
            }
            ++j;
        }
        if(r == 0){
            ret = min(ret, j - i);
        }
        ++freq[arr[i]];
        if(freq[arr[i]] > 0){
            ++r;
        }
    }
    if(ret == INF) return 0 * printf("impossible\n");
    printf("%d\n", ret);
    return 0;
}
