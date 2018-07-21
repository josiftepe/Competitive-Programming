#include <bits/stdc++.h>
 
using namespace std;
int n;
int arr[3];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    int ret = (1<<30);
    do{
        int tmp = 0;
        for(int i = 1; i < 3; i ++){
            tmp += abs(arr[i] - arr[i - 1]);
        }
    ret = min(ret, tmp);
 
    }while(next_permutation(arr, arr + 3));
    printf("%d\n", ret);
    return 0;
}
