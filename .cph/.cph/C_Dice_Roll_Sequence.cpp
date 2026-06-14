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
        
        vector<int> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        int ans = 0;

        for(int i = 0; i < n - 1; i++){
            
                if(i <= n - 3 && arr[i] == arr[i+2] && (arr[i+1] == arr[i] || arr[i+1] == 7 - arr[i])){
                    ans++;
                    i += 2;
                }
            
            else if(arr[i] == arr[i+1] || arr[i+1] == 7 - arr[i]){
                ans++;
            }

        }

        cout << ans << '\n';
    }
}
