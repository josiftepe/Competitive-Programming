#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const ll inf = (1LL << 55LL);
struct node{
    ll a, b, c;
    node(){}
    node(ll _a, ll _b, ll _c){
        a = _a;
        b = _b;
        c = _c;
    }
    bool operator < (const node &tmp) const{
        return a - b < tmp.a - tmp.b;
    }
};
int W, B, R, n;
vector<node> v;
ll dp_W[maxn], dp_B[maxn];
void take_W(){
    priority_queue<ll> q;
    ll sum = 0;
    for(int i = 0; i < n; i ++){
        dp_W[i] = -inf;
    }
    for(int i = n - 1; i >= 0; i --){
        q.push(-v[i].a);
        sum += v[i].a;
        if(W < (int)q.size()){
            ll tmp = -q.top();
            q.pop();
            sum -= tmp;
        }
        if(W == (int)q.size()){
            dp_W[i] = sum;
        }
    }
}
void take_B(){
    priority_queue<ll> q;
    ll sum = 0;
    for(int i = 0; i < n; i ++){
        dp_B[i] = -inf;
    }
    for(int i = 0; i < n; i ++){
        q.push(-v[i].b);
        sum += v[i].b;
        if(B < (int)q.size()){
            ll tmp = -q.top();
            q.pop();
            sum -= tmp;
        }
        if(B == (int)q.size()){
            dp_B[i] = sum;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> W >> B >> R >> n;
    ll a, b, c;
    ll ret = 0;
    for(int i = 0; i < n; i ++){
        cin >> a >> b >> c;
        v.push_back(node(a - c, b - c, c));
        ret += c;
    }
    sort(v.begin(), v.end());
    take_W();
    take_B();
    ll mxx = -inf;
    for(int i = 0; i + 1 < n; i ++){
        mxx= max(mxx, dp_B[i] + dp_W[i + 1]);
    }
    cout << ret + mxx << endl;
    return 0;
}
