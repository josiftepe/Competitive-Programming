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
const int INF = 2e9 + 10;
const int  maxn = 40001;
int n, q;
int arr[maxn];
struct elem{
    ll val, val_without_left, val_without_right, val_without_both;
    elem (){
        val = 0;
        val_without_left = 0;
        val_without_right = 0;
        val_without_both = 0;
    }
};
elem merge(elem a, elem b){
    elem c;
    c.val = max(a.val_without_left + b.val, a.val + b.val_without_right);
    c.val_without_left = max(a.val + b.val_without_both, a.val_without_left + b.val_without_left);
    c.val_without_right = max(a.val_without_both + b.val, a.val_without_right + b.val_without_right);
    c.val_without_both = max(a.val_without_right + b.val_without_both, a.val_without_both + b.val_without_left);
    return c;
}
class node{
public:
    elem val;
    int lb, rb;
    node *left, *right;
    node(int levo, int desno){
        lb = levo;
        rb = desno;
        if(lb == rb){
            val.val = arr[lb];
            val.val_without_left = val.val_without_right = val.val_without_both = 0;
        }
        else{
            int mid = (levo + desno) >> 1;
            left = new node(levo, mid);
            right = new node(mid + 1, desno);
            val = merge(left -> val, right -> val);
        }
    }
    void update(int &_node, int &new_val){
        if(lb == rb){
            val.val = new_val;
            val.val_without_left = val.val_without_right = val.val_without_both = 0;
            return;
        }
        if(_node >= right -> lb){
            right -> update(_node, new_val);
        }
        else{
            left -> update(_node, new_val);
        }
        val = merge(left -> val, right -> val);
    }
    elem query(int &i, int &j){
        if(i <= lb and rb <= j){
            return val;
        }
        // i j l r i j
        if(j < lb or rb < i){
            return elem();
        }
        return merge(left -> query(i, j), right -> query(i, j));
    }
};
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    ifstream cin("optmilk.in");
    ofstream cout("optmilk.out");
    cin >> n >> q;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    int S = 0, E = n - 1;
    node *root = new node(S, E);
    ll ret =0 ;
    for(int i = 0; i < q; i ++){
        int idx, new_val;
        cin >> idx >> new_val;
        --idx;
        root -> update(idx, new_val);
        elem query = root -> query(S, E);
        ret += max(max(query.val, query.val_without_left), max(query.val_without_both, query.val_without_right));
    }
    cout << ret << endl;
    return 0;
    
}
