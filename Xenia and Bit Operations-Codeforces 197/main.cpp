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
int n, m;
ll arr[maxn];
ll mymerge(ll &a, ll &b, int &level){
    if(level & 1){
        return a | b;
    }
    return a ^ b;
}
ll mymerge2(ll a, ll b, int &level){
    if(level & 1){
        return a | b;
    }
    return a ^ b;
}
class node{
public:
    ll val;
    int level;
    int lb, rb;
    node *left, *right;
    node(int levo, int desno){
        lb = levo;
        rb = desno;
        if(levo == desno){
            val = arr[levo];
            level = 1;
        }
        else{
            int mid = (lb + rb) >> 1;
            left = new node(levo, mid);
            right = new node(mid + 1, desno);
            val = mymerge(left -> val ,right -> val, left -> level);
            level = left->level + 1;
        }
    }
    void update(int _node, ll new_val){
        if(lb == rb){
            val = new_val;
            return;
        }
        if(_node >= right -> lb){
            right -> update(_node, new_val);
        }
        else{
            left -> update(_node, new_val);
        }
        val = mymerge(left -> val, right -> val, left -> level);
    }
    ll query(int i, int j){
        if(i <= lb and rb <= j){
            return val;
        }
        // i j l r i j
        if(j < lb || rb < i){
            return 0;
        }
        return mymerge2(left -> query(i, j),  right -> query(i, j), left->level);
    }
};
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    n = (1 << n);
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    node *root = new node(0, n - 1);
    while(m --){
        int p, b;
        cin >> p >> b;
        p --;
        root->update(p, b);
        cout << root ->query(0, n - 1) << endl;
    }
    
    return 0;
}

