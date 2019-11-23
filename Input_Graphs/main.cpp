#include <iostream>

using namespace std;

int main()
{
    int n; /// number of nodes
    int m; /// number of edges
    cin >> n >> m;
    int matrix[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix[i][j] = -1;
        }
    }
    for(int i = 0; i < m; i++) {
        int ai, bi;
        cin >> ai >> bi;
        matrix[ai][bi] = 1;
        matrix[bi][ai] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 1){
                cout << i << " is connected to: " << j << endl;
            }
        }
    }
    return 0;
}
