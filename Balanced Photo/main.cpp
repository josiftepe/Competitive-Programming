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
int arr[maxn];
class node{
public:
    vector<int> val;
    int lb, rb;
    node *left, *right;
    node(int levo, int desno){
        lb = levo;
        rb = desno;
        if(lb == rb){
            val.push_back(arr[levo]);
        }
        else{
            int mid = (levo + desno) >> 1;
            left = new node(levo, mid);
            right = new node(mid + 1, desno);
            merge(left->val.begin(), left->val.end(), right->val.begin(), right->val.end(), back_inserter(val));
        }
    }
    int query(int &i, int &j, int &k){
        if(i <= lb and rb <= j){
            return (int)(lower_bound(val.begin(), val.end(), k + 1) - val.begin());
        }
        /// i j l r i j
        if(j < lb || rb < i) return 0;
        return left->query(i, j, k) + right->query(i, j, k);
    }
};
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    ifstream cin("bphoto.in");
    ofstream cout("bphoto.out");
    cin >> n;
    vector<pair<int, int > > v;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        v.push_back(make_pair(arr[i], i));
    }
    node *tree = new node(0, n - 1);
    int ret =0 ;
    for(int i = 0; i < n; i ++){
        int L = 0;
        int R = i - 1;
        int bigger_left = (R - L ) - tree->query(L, R, arr[i]) + 1;
        L = i + 1;
        R = n - 1;
        int bigger_right = (R - L ) - tree->query(L, R, arr[i]) + 1;
        if(bigger_left * 2 < bigger_right || bigger_right * 2 < bigger_left){
            ++ret;
        }
    }
    cout << ret << endl;
    return 0;
}
