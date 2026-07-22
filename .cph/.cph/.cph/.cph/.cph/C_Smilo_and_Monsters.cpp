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

        while(i < j) {
            
            if(arr[i] + count > arr[j]) {
    
                ans += arr[j] + 1;
                count = count + arr[i] - arr[j];
                j--;
                i++;

            }
            else count += arr[i++];
        }

        if(i == j) ans += max(count, arr[i]) + 1;




        cout << ans << '\n';
    }
}
