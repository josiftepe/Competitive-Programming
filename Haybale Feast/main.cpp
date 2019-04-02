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
const int  maxn = 1e5 + 10;
const ll MOD = 1e9 +  7;
int n;
ll M;
ll arr[maxn][2];
ll pref_sum[maxn];
ll query(int i, int j){
//    if(i == 0) return pref_sum[j];
    return pref_sum[j] - pref_sum[i - 1];
}
class node{
public:
    ll val;
    int lb, rb;
    node *left, *right;
    node(int levo, int desno){
        lb = levo;
        rb = desno;
        if(levo == desno){
            val = arr[lb][1];
        }
        else{
            int mid = (lb + rb) >> 1;
            left = new node(lb, mid);
            right = new node(mid + 1, rb);
            val = max(left->val, right->val);
        }
    }
    ll query(int i, int j){
        if(i <= lb and rb <= j){
            return val;
        }
        // i j l r i
        if(j < lb || rb < i)return -inf;
        return max(left->query(i, j), right->query(i, j));
    }
};
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    ifstream cin("hayfeast.in");
    ofstream cout("hayfeast.out");
    cin >> n >> M;
    ll sum = 0;
    for(int i = 0; i < n; i ++){
        cin >> arr[i][0] >> arr[i][1];
        sum += arr[i][0];
        pref_sum[i] = sum;
        
    }
    node *tree = new node(0, n);
    ll ret = inf;
    for(int i = 0; i < n; i ++){
        int L = i, R = n - 1;
        int least_idx = INF;
        while(L <= R){
            int mid = (L + R) >> 1;
            if(query(i, mid) >= M){
//                cout << i + 1 << " " << mid + 1 << " " << query(i, mid) << endl;
                least_idx = min(least_idx, mid);
                R = mid - 1;
            }
            else{
                L = mid + 1;
            }
        }
        if(least_idx == INF) continue;
        ret = min(ret, tree->query(i, least_idx));
    }
    cout << ret << endl;
    return 0;
}
