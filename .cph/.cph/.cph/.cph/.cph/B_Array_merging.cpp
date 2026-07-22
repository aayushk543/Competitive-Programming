#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr1(n + 1, 0);
        vector<int> arr2(n + 1, 0);

        for(int i = 0; i < n; i++) cin >> arr1[i];
        for(int i = 0; i < n; i++) cin >> arr2[i];

        vector<int> arr3(2*n + 1, 0);

        for(int i = 0; i < n; i++) {
            int j = i;
            while(arr1[i] == arr1[i+1]) i++;

            arr3[arr1[i]] = max(arr3[arr1[i]], i - j + 1);

        }

        vector<int> arr4(2*n + 1, 0);

        int ans = -1;

        for(int i = 0; i < n; i++) {
            int j = i;
            while(arr2[i] == arr2[i+1]) i++;

            arr4[arr2[i]] = max(arr4[arr2[i]], i - j + 1);

            ans = max(ans, arr4[arr2[j]] + arr3[arr2[j]]);
        }

        for(int i = 1; i <= 2*n; i++) {
            ans = max(ans, arr3[i] + arr4[i]);
        }


        cout << ans << '\n';
    }

    return 0;
}
