#include<bits/stdc++.h>
using namespace std;

int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> mat(n + 1, vector<int>(n + 1));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) cin >> mat[i][j];
        }

        
    }
    return 0;
}