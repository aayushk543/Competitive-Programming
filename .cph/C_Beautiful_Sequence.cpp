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

        vector<int> arr(n);
        long long ans = 0;

        long long count_1 = 0, count_2 = 0, count_3 = 0;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];

            if(arr[i] == 1) count_1++;
            else if(arr[i] == 2) count_2++;
            else if(arr[i] == 3) count_3++;
        }

        //int i = 0;

        long long prev_1 = 0;
        long long prev_2 = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] == 3) count_3--;
            else if(arr[i] == 1) {
                prev_1++;
            }
            else if(arr[i] == 2) {
                if(prev_1 > 0) {
                    ans += prev_1*count_3;

                    if(prev_2 > 0) ans += (pow(2LL, prev_2) - 1)*(count_3);

                    prev_2++;

                    cout << ans << '\n';
                }
                //count_2--;
                //prev_1--;
            }

            if(count_3 == 0) break;
        }

        cout << ans << '\n';
    
    }
    return 0;
}