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
const int INF = (1 << 30);
const ll inf = (1LL << 60LL);
const int maxn = 1e6 + 5;
int n, m, p;
int mat[2222][2222];
map<int, int> mapa;
struct node{
    int points, solved, id;
    node(){}
    node(int _p, int _s, int _i){
        points = _p;
        solved = _s;
        id = _i;
    }
    bool operator < (const node &a)const    {
        if(points == a.points){
            if(solved == a.solved){
                return id < a.id;
            }
            return solved > a.solved;
        }
        return points > a.points;
    }
};
vector<node> v;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> mat[i][j];
            if(mat[i][j] == 0){
                mapa[j] ++;
            }
        }
        
    }
    for(int i = 0; i < n; i ++){
        int solved = 0, points = 0;
        for(int j = 0; j < m; j ++){
            if(mat[i][j] == 1){
                solved ++;
                points += mapa[j];
            }
        }
        v.push_back(node(points, solved, i));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i ++){
        if(v[i].id == p - 1){
            cout << v[i].points << " " << i + 1 << endl;
            break;
        }
    }
    return 0;
}
