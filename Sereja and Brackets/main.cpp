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
string s;
int nxt[maxn];
class node{
public:
    vector<int> val;
    int lb, rb;
    node *left, *right;
    node(int levo, int desno){
        lb = levo;
        rb = desno;
        if(levo == desno){
            val.push_back(nxt[levo]);
        }
        else{
            int mid = (lb + rb) >> 1;
            left = new node(levo, mid);
            right = new node(mid + 1, desno);
            merge(left->val.begin(), left->val.end(), right->val.begin(), right->val.end(), back_inserter(val));
        }
    }
    int query(int &i, int &j, int &k){
        if(i <= lb and rb <= j){
            return (int)(lower_bound(val.begin(), val.end(), k) - val.begin());
        }
        // i j l r i j
        if(j < lb || rb < i){
            return 0;
        }
        return left -> query(i, j, k) + right -> query(i, j, k);
    }
};
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> s;
    stack<int> st;
    memset(nxt, 63, sizeof nxt);
    for(int i = 0; i < (int)s.size(); i ++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            if(!st.empty()){
                nxt[st.top()] = i;
                st.pop();
            }
        }
    }
    int q;
    cin >> q;
    int a, b;
    vector<int> ret;
    node *root = new node(0, (int)s.size());
    while(q --){
        cin >> a >> b;
        a --;
        b --;
        int t = b + 1;
        ret.push_back(root -> query(a, b, t));
    }
    for(int i = 0; i < ret.size(); i ++){
        printf("%d\n", ret[i] * 2);
    }
    return 0;
}

