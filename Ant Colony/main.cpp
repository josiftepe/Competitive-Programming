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
const int maxn = 1e5 + 10;
int n;
int arr[maxn];
int gcd(int a, int b){
    if(a < b)swap(a, b);
    int tmp;
    while(b){
        // b, a % b
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
pair<int, int> mymerge(pair<int, int> a, pair<int, int> b){
    pair<int, int> tmp = make_pair(0, 0);
    tmp.first = gcd(a.first, b.first);
    if(tmp.first == a.first){
        tmp.second += a.second;
    }
     if(tmp.first == b.first){
        tmp.second += b.second;
    }
    return tmp;
}
class node{
public:
    pair<int, int> val;
    int lb, rb;
    node *left, *right;
    node(int levo, int desno){
        lb = levo;
        rb = desno;
        if(lb == rb){
            val = make_pair(arr[levo], 1);
        }
        else{
            int mid = (lb + rb) >> 1;
            left = new node(lb, mid);
            right = new node(mid + 1, rb);
            val = mymerge(left -> val, right -> val);
            
        }
    }
    pair<int, int> query(int &i, int &j){
        if(i <= lb and rb <= j){
            return val;
        }
        /// i j l r i j
        if(j < lb || rb < i){
            return make_pair(0, 0);
        }
        return mymerge(left -> query(i, j), right -> query(i, j));
    }
};
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    int q;
    cin >> q;
    int a, b;
    vector<int> ret;
    node *root = new node(0, n - 1);
    while(q --){
        cin >> a >> b;
        a --;
        b --;
        ret.push_back((b - a + 1) - root -> query(a, b).second);
    }
    for(int i = 0; i < ret.size(); i ++){
        cout << ret[i] << "\n";
    }
    return 0;
}
