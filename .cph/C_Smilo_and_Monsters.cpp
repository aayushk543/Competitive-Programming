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

        vector<long long> arr(n);
        long long total = 0;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            total += arr[i];
        }

        sort(arr.begin(), arr.end());

        int i = 0, j = n - 1;
        long long ans = 0, count = 0;

        while(i <= j) {

            if(i == j) {
                ans += (arr[j] + count);

                if(arr[j] % 2 == 0) ans += arr[j] / 2;
                else {
                    cout << floor(arr[j] / 2.0) << '\n';
                    ans += floor((arr[j] * 1.00) / 2.0);
                    cout << ans << '\n';
                    ans += 2;

                    cout << ans << " ";
                }

                break;
            }

            if(count + arr[i] < arr[j]) {
                ans += arr[i];
                count += arr[i++];

                cout << ans << " " << 2 << '\n';
            }
            else {
                ans += 1 + arr[i];
                j--;
                count = count + arr[i] - arr[j];
                i++;

                cout << ans << " " << 1 << '\n';
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}