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
using namespace std;
typedef long long ll;
const int INF = (1 << 30);
const ll inf = (1LL << 60LL);
int n, L;
ll B;
int arr[100001];
ll prefSum[100005];
bool check(int sz){
    int levo, desno, mid;
    ll tmp;
    if(sz % 2 == 0){
        for(int i = 1; i <= n - sz + 1; i ++){
            levo = i;
            desno = i + sz - 1;
            mid = (levo + desno) >> 1;
            tmp = (prefSum[desno] - prefSum[mid]) - (prefSum[mid] - prefSum[levo - 1]);
            if(tmp <= B){
                return true;
            }

        }
    }
    else{
        for(int i = 1; i <= n - sz + 1; i ++){
            levo = i;
            desno = i + sz - 1;
            mid = (levo + desno) >> 1;
            tmp = (prefSum[desno] - prefSum[mid]) - (prefSum[mid - 1] - prefSum[levo - 1]);
            if(tmp <= B){
                return true;
            }
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> L >> B;
    ll sum = 0;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        sum += arr[i];
        prefSum[i + 1] = sum;
    }
    int levo = 0, desno = n + 1;
    int mid;
    while(levo < desno){
        mid = (levo + desno + 1) >> 1;
        if(check(mid)){
            levo = mid;
        }
        else{
            desno = mid - 1;
        }
    }
    cout << levo << endl;
    return 0;
}
