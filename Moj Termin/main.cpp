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
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (1 << 30);
const ll inf = (1LL << 60LL);
const ll maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
int n;
string s[105];
int arr[105];
ll dp[105];
int toInt(string &S){
    int ret = 0;
    for(int i = 0; i < (int)S.size(); i ++){
        ret = (ret * 10) + (S[i] - '0');
    }
    return ret;
}
ll rek(int at){
    if(at >= n)return 1;
    if(at == n - 1 && s[at] == "N")return 1;
    if(dp[at] != -1)return dp[at];
    ll ret = 0;
    int F = -1;
    if(s[at] == "N"){
//        ret += rek(at + 1);
        int tmp = 0;
        for(int i = at; i < n; i ++){
         
            if(s[i] != "N"){
                if(F == -1){
                    F = arr[i];
                }
            }
            if(s[i] == "N" && F == -1){
                ret += rek(i + 1);
            }
            if(s[i] != "N" && F != arr[i])break;
 
            ++tmp;
            if(tmp == F){
                ret += rek(i + 1);
            }
        }
    }
    else{
        int tmp = 0;
        for(int i = at; i < n; i ++){
            if(s[i] != "N" && F == -1){
                F = arr[i];
            }
            if(s[i] != "N" && F != arr[i])break;
            ++tmp;
            if(tmp == F){
                ret += rek(i + 1);
            }
        }
    }
    return dp[at] = ret;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    int nCnt = 0;
    for(int i = 0; i < n; i ++){
        cin >> s[i];
        if(s[i] != "N"){
            arr[i] = toInt(s[i]);
        }
        else{
            ++nCnt;
        }
    }
    memset(dp, -1, sizeof dp);
  //  cout << rek(0) << endl;
    if(nCnt ==n )return 0 * printf("NE");
    if(rek(0) <= 1){
        cout << "DA";
    }
    else{
        cout << "NE";
    }
    return 0;
}
