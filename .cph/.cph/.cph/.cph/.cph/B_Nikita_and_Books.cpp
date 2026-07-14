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

        vector<long long> arr(n+1, 0);

        if(n == 1) {
            long long m;
            cin >> m;
            cout << "YES" << '\n';
            continue; 
        }

        for(int i = 1; i <= n; i++) cin >> arr[i];

        long long prev = 0;
        bool flag = true;

        for(int i = 1; i <= n; i++) {
            

            if(arr[i-1] >= arr[i]) {
                long long diff = arr[i-1] - arr[i] + 1;
                if(prev < diff) {
                    flag = false;
                    break;
                }
                else {
                    prev -= diff;
                    arr[i] = arr[i-1] + 1;
                }
                
            }
            else {
                prev += arr[i] - arr[i-1] - 1;
                arr[i] = arr[i-1] + 1; 
            }
        }

        if(flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}