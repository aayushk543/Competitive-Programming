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

        vector<int> arr(n);

        int prev = INT_MAX;

        bool flag = false;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];

            if(arr[i] == i + 1) continue;
            else {
                if(prev > arr[i]) prev = arr[i];
                else flag = true;
            }
        }

        if(flag == false) cout << "YES" << '\n';
        else cout << "NO" << '\n';


    }
}