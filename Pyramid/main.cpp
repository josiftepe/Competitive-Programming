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
int n;
struct node{
    ll x, y, h;
};
node arr[105];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> arr[i].x >> arr[i].y >> arr[i].h;
    }
    for(ll i = 0; i <= 100; i ++){
        for(ll j = 0; j <= 100; j ++){
            ll H = 0;
            bool ok = true;
            ll tmp = (-llabs(arr[0].x - i) -llabs(arr[0].y - j));
            H = tmp - arr[0].h;
            H *= (-1LL);
            for(int it = 0; it < n; it ++){
               
                    if(max(H - llabs(arr[it].x - i) - llabs(arr[it].y - j), 0LL) == arr[it].h  ){
                        
                    }
                    else{
                        ok = false;
                        break;
                    }
                }
            if(ok){
                if(H <= 1)continue;
                cout << i << " " << j << " " << H << endl;
                return 0;
            }
        }
    }
    for(ll i = 0; i <= 100; i ++){
        for(ll j = 0; j <= 100; j ++){
            for(ll H = 1; H <= 1000; H ++){
                bool ok = true;
                for(int it = 0; it < n; it ++){
    
                    if(max(H - llabs(arr[it].x - i) - llabs(arr[it].y - j), 0LL) == arr[it].h  ){
                        
                    }
                    else{
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    cout << i << " " << j << " " << H << endl;
                    return 0;
                }
            }
        }
    }
    
    return 0;
}
