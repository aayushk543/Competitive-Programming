#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++) {
        
    }

    if(arr[n-1] > 0) cout << "NO" << '\n';
    else cout << "YES" << '\n';

}