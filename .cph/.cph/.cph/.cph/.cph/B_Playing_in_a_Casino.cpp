#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;

        vector<vector<int>> arr(m , vector<int> (n, 0));

        for(int i = 0; i < n*m; i++){
            int p = i / m;
            int q = i % m;
            cin >> arr[q][p];
        }

        long long ans = 0;

        for(int i = 0; i < m; i++){
            sort(arr[i].begin(), arr[i].end());


            long long count1 = arr[i][0];

            for(int q = 1; q < n; q++){

                ans += (long long)q*arr[i][q] - count1;

                count1 += arr[i][q];
            }

        }

        cout << ans << '\n';


    }
    return 0;
}
