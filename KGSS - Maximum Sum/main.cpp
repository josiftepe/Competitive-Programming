#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll inf = (1LL << 59LL);
const int INF = (1 << 30);
const ll MOD = (1e9 + 7);
const int maxn = 1000006;
int n;
int arr[maxn];
pair<int, int> mymerge(pair<int,int> a, pair<int, int> b){
    vector<int> aa;
    aa.push_back(a.first);
    aa.push_back(a.second);
    aa.push_back(b.first);
    aa.push_back(b.second);
    sort(aa.begin(), aa.end());
    return make_pair(aa[2], aa[3]);
}
class node{
    public:
    pair<int, int> val;
    int lb, rb;
    node *left, *right;
    node(int levo, int desno){
        lb = levo;
        rb = desno;
        if(levo == desno){
            val.first = arr[levo];
            val.second = -INF;
        }
        else{
            int mid = (levo + desno) >> 1;
            left = new node(levo, mid);
            right= new node(mid + 1, desno);
            val = mymerge(left->val, right -> val);
        }
    }
    void update(int _node, int new_val){
        if(lb == rb){
            val.first = new_val;
            return;
        }
        if(_node >= right -> lb){
            right -> update(_node, new_val);
        }
        else{
            left -> update(_node, new_val);
        }
        val = mymerge(left->val, right -> val);
    }
    pair<int, int> query(int i, int j){
        if(i <= lb and rb <= j){
            return val;
        }
        /// i j l r i j
        if(j < lb || rb < i)return make_pair(-INF, -INF);
        return mymerge(left->query(i,j), right -> query(i, j));
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i =0; i < n; i ++){
        cin >> arr[i];
    }
    node *root = new node(0, n - 1);
    int q;
    cin >> q;
    char c;
    while(q --){
        cin >> c;
        if(c == 'Q'){
            int i, j;
            cin >> i >> j;
            i --;
            j --;
            pair<int,int> tmp =root->query(i, j);
            cout<<tmp.first + tmp.second << "\n";
        }
        else{
            int i, j;
            cin >> i >> j;
            i --;
            root->update(i, j);
        }
    }
    return 0;
}
