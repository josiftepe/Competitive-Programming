#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int n, m;
struct node{
    int S, E;
};
node arr[100005];
bool cmp(node &a, node &b){
    return a.E < b.E;
}
 
int main()
 
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<pair<int, int> > v;
    int a, b;
    for(int i = 0; i < m; i ++){
        cin >> arr[i].S >> arr[i].E;
    }
    sort(arr, arr + m, cmp);
    int prev = arr[0].E;
    int ret = 1;
    for(int i = 1; i < m; i ++){
        if(arr[i].S >= prev){
            prev = arr[i].E;
            ret ++;
        }
    }
    printf("%d\n", ret);
    return 0;
}
