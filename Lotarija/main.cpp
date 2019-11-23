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
//#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
const ll INF = (1 << 30);
const ll inf = (1LL << 60LL);
const ll MAXN = 3e5 + 5;
int arr[10];
int mat[105][105];
map<int, int> cnt;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 7; i ++){
        cin >> arr[i];
    }
    for(int i = 0; i < 5; i ++){
        for(int j = 0; j < 6; j ++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < 5; i ++){
        for(int j = 0; j < 6; j ++){
            cnt[mat[i][j]] ++;
        }
    }
    for(int i = 0; i < 7; i ++){
        if(cnt[arr[i]] > 0){
            cnt[arr[i]] --;
        }
        else{
            return 0 * printf("NE\n");
        }
    }
    printf("DA\n");
    return 0;
}
//10 11 12 14 15 16 27]
