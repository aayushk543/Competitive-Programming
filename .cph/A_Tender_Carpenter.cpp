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

        vector<int> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        bool flag = false;

        for(int i = 1; i < n; i++) {

            if(2*min(arr[i], arr[i-1]) > max(arr[i-1], arr[i])) flag = true;
        }

        if(flag) cout << "YES" << '\n'; 
        else cout << "NO" << '\n';
    }
    return 0;
}