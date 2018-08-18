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
string s, k;
string add(string a, string b){
    int digA, digB;
    if((int)a.size() < (int)b.size()){
        swap(a, b);
    }
    int szA = (int)a.size() - 1;
    int szB = (int)b.size() - 1;
    string ret = "";
    int ost = 0;
    while(szA >= 0 and szB >= 0){
        digA = a[szA] - '0';
        digB = b[szB] - '0';
        int sum = digA + digB + ost;
        if(sum > 9){
            sum -= 10;
            ost = 1;
        }
        else{
            ost = 0;
        }
        ret += (sum + '0');
        szA --;
        szB --;
    }
    while(szA >= 0){
        digA = a[szA] - '0';
        int sum = digA + ost;
        if(sum > 9){
            sum -= 10;
            ost = 1;
        }
        else{
            ost = 0;
        }
        ret += (sum + '0');
        szA --;
    }
    if(ost == 1){
        ret += "1";
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string multiply(string a, string b){
    int szA = (int)a.size();
    int szB = (int)b.size();
    int ret[szA + szB + 1];
    memset(ret, 0, sizeof ret);
    for(int i = szA - 1; i >= 0; i --){
        for(int j = szB - 1; j >= 0; j --){
            ret[i + j + 1] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for(int i = szA + szB - 1; i >= 0; i --){
        if(ret[i] > 9){
            ret[i - 1] += (ret[i] / 10);
            ret[i] %= 10;
        }
    }
    int i = 0;
    while(ret[i] == 0){
        i ++;
    }
    string rr = "";
    while(i < szA + szB){
        rr += (ret[i] + '0');
        i ++;
    }
    return rr;
}
bool cmp(string a, string b){
    int szA = (int)a.size();
    int szB = (int)b.size();
    if(szA > szB){
        return true;
    }
    if(szA < szB){
        return false;
    }
    if(a == b)return true;
    if(a > b)return true;
    return false;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> s >> k;
    string tmp = "";
    string curr;
    string need = "5000000000000000";
    for(int i = 0; i < (int)s.size(); i ++){
        string d = "";
        d += s[i];
        
        curr = multiply(d, need);
        if(s[i] == '1'){
            curr = "1";
            tmp = add(tmp, curr);
            if(cmp(tmp, k)){
                cout << s[i] << endl;
                return 0;
            }
            continue;
        }
        string mult = "1";
        while(!cmp(add(tmp, mult), k)){
            tmp = add(tmp, mult);
            mult = multiply(mult, d);
        }
        cout << s[i] << endl;
        return 0;
    }
    cout << s[(int)s.size() - 1] << endl;
    return 0;
}
