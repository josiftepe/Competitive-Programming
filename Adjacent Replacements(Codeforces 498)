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
const int maxn = 3e5 + 5;
int n;
int arr[maxn];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i =0 ; i < n; i ++) {
        cin >> arr[i];
    }
    set<int> st;
    for(int i =0; i  <n; i ++){
        st.insert(arr[i]);
    }
    for(set<int>::iterator it = st.begin(); it != st.end(); it ++){
        int tmp = *it;
        if(tmp % 2 == 0){
            for(int j =0 ; j < n; j ++){
                if(arr[j] == tmp){
                    arr[j] = tmp - 1;
                    st.insert(tmp - 1);
                }
            }
        }
        else{
            for(int j=0; j < n;j ++){
                if(arr[j] == tmp){
                    arr[j] = tmp + 1;
                    st.insert(tmp + 1);
                }
            }
        }
    }
    for(int i=0; i < n; i ++){
        cout << arr[i] << " ";
    }
    return 0;
}
