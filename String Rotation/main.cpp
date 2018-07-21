#include <bits/stdc++.h>
 
using namespace std;
string rot(string s){
    string ret = s;
    for(int i = 1, j = 0; i < (int)s.size(); i ++, j ++){
        ret[i] = s[j];
    }
    ret[0] = s[(int)s.size() - 1];
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    map<string, bool> vis;
    while(true){
        if(a == b){
            return 0 * printf("Yes\n");
        }
        if(vis[a]){
            break;
        }
        vis[a] = true;
        a = rot(a);
    }
    printf("No\n");
    return 0;
}
