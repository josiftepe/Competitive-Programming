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
const int maxn = 1e5 + 10;
int n;
string arr[20002];
map<string, int> mapa;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    ifstream cin("in.txt");
    cin >> n;
    for(int i =0 ; i < n; i ++){
        cin >> arr[i];
    }
    for(int i =0 ; i < n; i ++){
        string s = arr[i];
        set<string> st;
        for(int j = 0; j < (int)s.size(); j ++){
            for(int k = 1; k <= (int)s.size(); k ++){
                if(j + k <= (int)s.size())
                    st.insert(s.substr(j, k));
            }
        }
        for(set<string>::iterator it = st.begin(); it != st.end(); it ++){
            mapa[*it] ++;
        }
    }
    ll ret = 0;
    for(int i =0 ; i < n; i ++){
        ret += max(0, mapa[arr[i]] - 1);
    }
    cout << ret << endl;
    return 0;
}
