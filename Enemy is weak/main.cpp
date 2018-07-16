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
const int maxn = 1e6 + 5;
int n;
ll arr[maxn];
class node{
public:
    int val;
    int lb, rb;
    node *left, *right;
    node(int levo, int desno){
        lb = levo;
        rb = desno;
        if(lb == rb){
            val = 0;
        }
        else{
            int mid = (lb+rb)>>1;
            left = new node(levo, mid);
            right = new node(mid + 1, desno);
            val = left -> val + right -> val;
        }
    }
    void update(int _node, int newVal){
        if(lb == rb){
            val += newVal;
            return;
        }
        if(_node >= right -> lb){
            right -> update(_node, newVal);
        }
        else{
            left -> update(_node, newVal);
        }
        val = left -> val + right -> val;
    }
    int query(int i, int j){
        if(i <= lb and rb <= j){
            return val;
        }
        /// l r i j l r
        if(rb < i || j < lb)return 0;
        return left -> query(i, j) + right -> query(i, j);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<pair<int, int > > v;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        v.push_back(make_pair(arr[i], i));
    }
    sort(v.begin(), v.end());
    vector<int> vv;
    for(int i =0 ; i < n; i ++){
        vv.push_back(v[i].second);
    }
    reverse(vv.begin(), vv.end());
    node *smaller = new node(0, n);
    node *bigger = new node(0, n);
    vector<ll> small, big;
    for(int i = 0; i < n; i ++){
        smaller -> update(vv[i], 1);
        small.push_back(smaller -> query(0, vv[i] - 1));
    }
    for(int i = n - 1; i >= 0; i --){
        bigger -> update(vv[i], 1);
        big.push_back(bigger -> query(vv[i] + 1, n - 1));
    }
    reverse(big.begin(), big.end());
    ll ret =0 ;
    for(int i =0; i < n; i ++){
        ret += (big[i] * small[i]);
    }
    cout << ret << endl;
    
    return 0;
}
