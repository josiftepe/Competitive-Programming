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
int n, m;
int R[101];
int W[2001];
int cars[5001];
int taken[101];
map<int, int> mapa;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i ++){
        cin >> R[i];
    }
    for(int i = 0; i < m; i ++){
        cin >> W[i];
    }
    for(int i = 0; i < 2 * m; i ++){
        cin >> cars[i];
    }
    memset(taken, 0, sizeof taken);
//    sort(R, R + n);
    ll ret = 0;
    queue<int> q;
    bool da = false;
    for(int i = 0; i < 2 * m; i ++){
//        cout << i << endl;
        if(cars[i] > 0){
            
//            cout << cars[i] << "CAR"
                      da = false;
            for(int j = 0; j < n; j ++){
               
                if(taken[j] == 0){
                    
                    taken[j] = cars[i];
                    mapa[cars[i]] = j;
//                    cout << cars[i] << " " << R[j] << " " << W[cars[i] - 1] << endl;
                    ret += (R[j] * W[cars[i] - 1]);
                    da = true;
                    break;
                }
            }
            if(!da){
                if(cars[i] == 4){
//                    cout << "DABE";
                }
                q.push(cars[i]);
            }
        }
         if(cars[i] < 0){
            taken[mapa[-cars[i]]] = 0;
             if(!q.empty()){
                 //            cout << "DA BE " << endl;
                 for(int j = 0; j < n; j ++){
                     if(taken[j] == 0){
                         taken[j] = q.front();
                         mapa[q.front()] = j;

                         ret += (R[j] * W[q.front() - 1]);
//                                                cout<< "F" << cars[i] << " " << R[j] << " " << W[q.front() - 1] << endl;
                         
                         break;
                     }
                 }
                 q.pop();
             }
        }
      }
//    cout << q.size() << endl;
    cout << ret << endl;
    return 0;
}

