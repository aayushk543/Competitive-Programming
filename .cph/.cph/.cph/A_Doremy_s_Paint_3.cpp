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

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        if(n <= 2) cout << "Yes" << '\n';
        else if(n == 3){
            if(arr[0] == arr[1] || arr[1] == arr[2]) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
        else {
            for(int i = 0; i < n - 1; i++){
                if(arr[i] != arr[i+1]) {
                    cout << "No" << '\n';
                    break;
                }
                else if(i == n - 2) {
                    cout << "Yes" << '\n';
                }
            }
        }
    }

    return 0;
}
