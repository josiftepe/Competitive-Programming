#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int n;
string v[maxn];
vector<pair<int, pair<string, vector<int> > > > g[1005];
int dp[maxn];
int backtrack[maxn];
int rek(int prev_at){
    if(dp[prev_at] != -1){
        return dp[prev_at];
    }
    int ret = 0;
    int sz = (int)v[prev_at].size();
    vector<int> cnt(26, 0);
    for(int i = 0; i < (int)v[prev_at].size(); i++){
        ++cnt[v[prev_at][i] - 'A'];
    }
    int mxx = 0;
    for(int i = 0; i < (int)g[sz + 1].size(); i++){
        vector<int> cnt2 = g[sz + 1][i].second.second;
        bool ok = false;
        bool can = true;
        for(int j = 0; j < 26; j++){
            if(abs(cnt2[j] - cnt[j]) == 0) continue;
            if(abs(cnt2[j] - cnt[j]) == 1 and ok == false){
                ok = true;
                continue;
            }
            if(abs(cnt2[j] - cnt[j]) >= 1 or ok){
                can = false;
                break;
            }
        }
        if(can){
            int tmp = rek(g[sz + 1][i].first) + 1;
            if(tmp > ret) ret = tmp;
            if(tmp > mxx){
                mxx = tmp;
                backtrack[prev_at] = g[sz + 1][i].first;
            }
        }
    }
    return dp[prev_at] = ret;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        vector<int> cnt(26, 0);
        for(int j = 0; j < (int)v[i].size(); j++){
            ++cnt[v[i][j] - 'A'];
        }
        g[(int)v[i].size()].push_back(make_pair(i, make_pair(v[i], cnt)));        
    }
    memset(backtrack, -1, sizeof backtrack);
    memset(dp, -1, sizeof dp);
    int ret = 0;
    int idx = -1;
    for(int i = 0; i < n; i++){
        if((int)v[i].size() <= 2 and rek(i) + 1 > ret){
            ret = rek(i);
            idx = i;
        }
    }
    if(ret <= 1){
        cout << 1 << endl;
        cout << v[0][0] << endl;
        return 0;
    }
    vector<string> ans;
    ans.push_back(string() + v[idx][0]);
    ans.push_back(v[idx]);
    int A = backtrack[idx];
    while(A != -1){
        ans.push_back(v[A]);
        A = backtrack[A];
    }
    if(ans[0].size() == ans[1].size()){
        ans.erase(ans.begin());
    }
    cout << (int)ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}


