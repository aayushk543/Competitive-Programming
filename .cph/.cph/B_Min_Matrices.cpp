#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;

        vector<vector<int>> arr(n, vector<int>(n));

        int j = n * n;

        if(!(k < 2*n && k >= n)) cout << -1 << '\n';
        else {
            int times = 2*n - k;

            for(int i = 0; i < times; i++) {
                arr[i][i] = i + 1;
            }

            times += 1;

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {

                    if(arr[i][j] == 0) cout << times++ << " ";
                    else cout << arr[i][j] << " ";
                }

                cout << '\n';
            }
        }
    }
}