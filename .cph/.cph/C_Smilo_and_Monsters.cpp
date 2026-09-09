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

                //cout << count << " " << arr[j] << '\n';
            }

            if(i == j) {
                
                if(count > arr[j]) {
                    //cout << ans << '\n';
                    ans += (arr[j]) + 1;
                    count -= arr[j];

                    int add = (int)(ceil((count * 1.00) / 2.00));
                    ans += add;

                    if(add > 1) ans += 1;
                }
                else {
                    
                    int add = (int)(ceil(((arr[j] + count) * 1.00) / 2.00));

                    ans += add;
                    if(add > 1) ans += 1;
                }

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