#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;

        vector<vector<int>> mat(n, vector<int>(n));

        bool flag = true;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) cin >> mat[i][j];
        }

        k *= 2;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(mat[i][j] != mat[n - i - 1][n - j - 1]) {

                    if(k > 0) {
                        k--;
                        continue;
                    }
                    flag = false;
                    break;
                }
            }
        }

        k /= 2;

        if(flag && (k % 2 == 0 || n % 2 == 1)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}