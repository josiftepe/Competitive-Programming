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
int n, k;
string s;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    n = (int)s.size();
    int tmp = 0;
    string ret = "";
    int opening = k / 2, closing = k / 2;
    for(int i = 0; i < (int)s.size(); i ++){
        if(s[i] == '('){
            if(opening == 0){
                continue;
            }
            opening --;
            tmp ++;
            ret += "(";
        }
        else{
            if(closing == 0){
                continue;
            }
            if(tmp > 0){
                tmp --;
                closing --;
                ret += ")";
            }
        }
    }
    cout << ret << endl;
    return 0;
}
