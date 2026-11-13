#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        vector<int> arr(3);

        cin >> arr[0];
        cin >> arr[1];
        cin >> arr[2];

        sort(arr.begin(), arr.end());

        if(arr[0] + 1 == arr[1] && arr[2] - 1 == arr[1]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}