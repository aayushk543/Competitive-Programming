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

       vector<long long> arr(n);

       for(int i = 0; i < n; i++) cin >> arr[i];

       for(int i = 1; i < n; i++){
        if(arr[i-1] > arr[i]) {
            swap(arr[i-1], arr[i]);
            arr[i] += arr[i-1];
        }
       }

       cout << arr[n-1] << '\n';
    }
    return 0;
}