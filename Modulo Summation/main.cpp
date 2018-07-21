#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
int n;
int arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
   cin >> n;
    ll ret=0;
   for(int i=0;i<n;i++){
    cin>>arr[i];
    ret += arr[i];
   }
   int tmp=0;
cout<< ret-n<<endl;
    return 0;
}
