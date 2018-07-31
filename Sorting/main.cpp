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
const int maxn = 5e5 + 5;
int n;
int arr[maxn];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int mnn = INF;
    vector<int> t;
    for(int i = 1; i <= n; i ++){
        cin >> arr[i];
        if(abs(arr[i] - i) != 0){
            mnn = min(mnn, abs(arr[i] - i));
        }
    }
    vector<int> v;
    for(int i = 1; i <= mnn; i ++){
        if(mnn % i == 0){
            v.push_back(i);
        }
    }
    cout << (int)v.size() << endl;
    for(int i = 0; i < (int)v.size(); i ++){
        cout << v[i] << " ";
    }
    return 0;
}
