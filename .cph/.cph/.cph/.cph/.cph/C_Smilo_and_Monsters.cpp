#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n; 

        vector<long long> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        sort(arr.begin(), arr.end());

        int i = 0, j = n - 1;

        long long ans = 0;
        long long count = 0;

        while(i <= j) {
            
            while(i < j && arr[j] > count) {
                count += arr[i++];
            }


            if(i == j) {
                
                if(count > 0 && arr[j] > count) {
                    arr[j] -= count;
                    ans += count + 1;
                }
                else {
                    ans += count + 1;
                    arr[j] = 0;
                }

                if(arr[j] <= 3) ans += arr[j];
                else ans += ceil(arr[j] / 2.00);
                break;
            }

            if(arr[j] <= count) {
                ans += arr[j] + 1;
                count -= arr[j];
                j--;
            }

        }

        cout << ans << '\n';
    }
}
