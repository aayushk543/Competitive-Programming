#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> vec(n, vector<int>(2));

        for(int i = 1; i <= n; i++) {
            cin >> vec[i-1][0] >> vec[i-1][1];
        }

        double x = 0.0, y = 0.0;

        for(int i = 0; i < n; i++) {
            x += vec[i][0];
            y += vec[i][1];
        }

        int val1_floor = floor(x / (1.00 * n));
        int val1_ceil = ceil(x / (1.00 * n));

        int val1_floor = floor(x / (1.00 * n));
        int val1_ceil = ceil(x / (1.00 * n));
    }
    return 0;
}