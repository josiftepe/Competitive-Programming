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
const int maxn = 200006;
int n, m;
vector<string> mat;
bool visited[111][111];
bool del(){
    for(int i = 0; i < (int)mat.size(); i ++){
        bool ok = false;
        for(int j = 0; j < (int)mat[0].size(); j ++){
            if(visited[i][j])continue;
            if(mat[i][j] != '.'){
                ok = false;
                break;
            }
            ok = true;
        }
        if(ok){
            for(int j = 0; j < (int)mat[0].size(); j ++){
                visited[i][j] = true;
            }
            return true;
        }
    }
    return false;
}
bool del2(){
    for(int j = 0; j < (int)mat[0].size(); j ++){
        bool ok = false;
        for(int i = 0; i < (int)mat.size(); i ++){
            if(visited[i][j])continue;
            if(mat[i][j] != '.'){
                ok = false;
                break;
            }
            ok = true;
        }
        if(ok){
            for(int i = 0; i < (int)mat.size(); i ++){
                visited[i][j] = true;
            }
            return true;
        }
    }
    return false;
    
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i ++){
        string s;
        cin >> s;
        mat.push_back(s);
    }
    memset(visited, false, sizeof visited);
    while(true){
        if(!del() and !del2()){
            break;
        }
      
    }
    vector<string> ret;
    for(int i = 0; i < n; i ++){
        string tmp = "";
        for(int j = 0; j < m; j ++){
            if(visited[i][j])continue;
            tmp += mat[i][j];
        }
        if(tmp != "")
            ret.push_back(tmp);
    }
    cout << endl;
    for(int i = 0; i < (int)ret.size(); i ++){
        for(int j = 0; j < (int)ret[0].size(); j ++){
            cout << ret[i][j];
        }
        cout << endl;
    }
    return 0;
}
