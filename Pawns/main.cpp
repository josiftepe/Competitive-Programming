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
int n;
int arr[15];
bool check(string s){
    if(s[0] == '1'){
        int idx = -1;
        for(int i = 0; i < (int)s.size(); i ++){
            if(s[i] != '1'){
                idx = i;
                break;
            }
        }
        if(idx != -1){
            while(s[idx] == '0'){
                idx ++;
            }
            for(int i = idx; i < (int)s.size(); i ++){
                if(s[i] != '2'){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
map<string, bool> visited;
map<int, int> backtrack;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    string s = "";
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        s += (char)(arr[i] + '0');
    }
    string A = s;
    queue<string> q;
    q.push(s);
    queue<int> qCekor;
    qCekor.push(0);
    queue<vector<int> > qv;
    vector<int> a;
    qv.push(a);
    int cekor;
    int ret = INF;
    string tmp;
    while(!q.empty()){
        s = q.front();
        q.pop();
        cekor = qCekor.front();
        qCekor.pop();
        a = qv.front();
        qv.pop();
        if(check(s)){
            cout << cekor << "\n";
            for(int i = 0; i <(int)a.size(); i ++){
                cout << a[i] << " ";
            }
            return 0;
        }
        for(int i = 0; i < (int)s.size(); i ++){
            if(s[i] == '1'){
                if(i - 1 >= 0 and s[i - 1] == '0'){
                    tmp = s;
                    tmp[i] = '0';
                    tmp[i - 1] = '1';
                    if(visited[tmp])continue;
                    visited[tmp] = true;
                    q.push(tmp);
                    qCekor.push(cekor + 1);
                    vector<int> b = a;
                    b.push_back(i + 1);
                    qv.push(b);
                }
                if(i - 2 >= 0 and s[i - 1] != '0' and s[i - 2] == '0'){
                    tmp = s;
                    tmp[i] = '0';
                    tmp[i - 2] = '1';
                    if(visited[tmp])continue;
                    visited[tmp] = true;
                    q.push(tmp);
                    qCekor.push(cekor + 1);
                    vector<int> b = a;
                    b.push_back(i + 1);
                    qv.push(b);
                }
            }
            else if(s[i] == '2'){
                if(i + 1 < n and s[i + 1] == '0'){
                    tmp = s;
                    tmp[i] = '0';
                    tmp[i + 1] = '2';
                    if(visited[tmp])continue;
                    visited[tmp] = true;
                    q.push(tmp);
                    qCekor.push(cekor + 1);
                    vector<int> b = a;
                    b.push_back(i + 1);
                    qv.push(b);
                }
                if(i + 2 < n and s[i + 1] != '0' and s[i + 2] == '0'){
                    tmp = s;
                    tmp[i] = '0';
                    tmp[i + 2] = '2';
                    if(visited[tmp])continue;
                    visited[tmp] = true;
                    q.push(tmp);
                    qCekor.push(cekor + 1);
                    vector<int> b = a;
                    b.push_back(i + 1);
                    qv.push(b);
                }
            }
        }
    }
   
    return 0;
}
