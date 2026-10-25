#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n,m,k;
       cin >> n >> m >> k;

       vector<vector<int>> mat1(n + 1, vector<int>(m));
       vector<vector<int>> mat2(n, vector<int>(m + 1));

       for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m - 1; j++) cin >> mat1[i][j];
       }

       for(int i = 1; i <= n - 1; i++) {
        for(int j = 1; j <= m; j++) cin >> mat2[i][j];
       }

       vector<vector<int>> mat(n + 1, vector<int>(m + 1));

       


    }
    return 0;
}