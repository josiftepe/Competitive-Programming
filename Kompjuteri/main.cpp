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
const int  maxn = 1e4 + 10;
const ll MOD = 1e9 +  7;
int A, B, C;
int arr[maxn];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> A >> B >> C;
    vector<pair<int, int> > even, odd;
    for(int i = 1; i <= A; i ++){
        cin >> arr[i];
    }
    int n = A + B + C;
    arr[0] = 0;
    arr[A + 1] = n + 1;
    for(int i = 1; i <= A + 1; i ++){
        
        int from = arr[i - 1];
        from ++;
        int to = arr[i];
        to --;
        
        if(from > to) continue;
        if((to - from + 1) % 2 == 0){
            even.push_back(make_pair(from, to));
        }
        else{
            odd.push_back(make_pair(from, to));
        }
    }
    string ret = "";
    ret += "/";
    for(int i = 1; i <= n; i ++){
        ret += "_";
    }
    for(int i = 1; i <= A; i ++){
        ret[arr[i]] = 'A';
    }
    for(int i = 0; i < (int)even.size(); i ++){
        int sz = even[i].second - even[i].first + 1;
        sz /= 2;
        if(B >= sz and C >= sz){
            B -= sz;
            C -= sz;
            int F = 0;
            for(int j = even[i].first; j <= even[i].second; j ++){
                if(F == 0){
                    ret[j] = 'B';
                }
                else{
                    ret[j] = 'C';
                }
                F ^= 1;
            }
            
        }
        else{
            return 0 * printf("-1\n");
        }
    }
    int sum = 0, sum2 = 0;
    int idx =  -1;
    for(int i = 0; i < (int)odd.size(); i ++){
        int sz = odd[i].second - odd[i].first + 1;
        int mxx = sz / 2 + 1;
        int mnn = sz / 2;
        sum += mxx;
        sum2 += mnn;
        int tmp_B = B;
        int tmp_C = C;
        tmp_B -= sum;
        tmp_C -= sum2;
        if(tmp_B < 0 || tmp_C < 0) continue;
        bool ok = true;
        for(int j = i + 1; j < (int)odd.size(); j ++){
            sz = odd[j].second - odd[j].first + 1;
            mxx = sz / 2 + 1;
            mnn = sz / 2;
            if(tmp_C > tmp_B){
                tmp_C -= mxx;
                tmp_B -= mnn;
            }
            else if(tmp_B >= tmp_C){
                tmp_B -= mxx;
                tmp_C -= mnn;
            }
            if(tmp_B < 0 or tmp_C < 0){
                ok = false;
                break;
            }
        }
        if(ok){
            idx = i;
        }
    }
    for(int i  =0; i <= idx; i ++){
        int sz = odd[i].second - odd[i].first + 1;
        int mxx = sz / 2 + 1;
        int mnn = sz / 2;
        if(B >= mxx and C >= mnn){
            B -= mxx;
            C -= mnn;
            int F = 0;
            for(int j = odd[i].first; j <= odd[i].second; j ++){
                if(F == 0){
                    ret[j] = 'B';
                }
                else{
                    ret[j] = 'C';
                }
                F ^= 1;
            }
            
            
        }
    }
    //    cout << idx << endl;
    for(int i = idx + 1; i < (int)odd.size(); i ++){
        int sz = odd[i].second - odd[i].first + 1;
        int mxx = sz / 2 + 1;
        int mnn = sz / 2;
        if(B >= C){
            B -= mxx;
            C -= mnn;
            if(B < 0 or C < 0) return 0 * printf("-1\n");
            int F = 0;
            for(int j = odd[i].first; j <= odd[i].second; j ++){
                if(F == 0){
                    ret[j] = 'B';
                }
                else{
                    ret[j] = 'C';
                }
                F ^= 1;
            }
        }
        else if(C > B){
            B -= mnn;
            C -= mxx;
            if(B < 0 or C < 0) return 0 * printf("-1\n");
            int F = 1;
            for(int j = odd[i].first; j <= odd[i].second; j ++){
                if(F == 0){
                    ret[j] = 'B';
                }
                else{
                    ret[j] = 'C';
                }
                F ^= 1;
            }
        }
        else{
            return 0 * printf("-1\n");
        }
    }
    
    
    
    ret.erase(ret.begin());
    cout << ret << endl;
    return 0;
}
