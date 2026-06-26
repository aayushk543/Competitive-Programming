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

       int length = 0;

       for(int i = 0; i < n; i++){
        if(arr[i] > length + 1 || (arr[i] == length + 1)) length += 1;

        cout << max(length, 1) << " ";
       }

       cout << '\n';
    }
    return 0;
}