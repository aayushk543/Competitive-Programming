#include<bits/stdc++.h>
using namespace std;

bool f(vector<int>& arr, int l, int r, int num) {

    if(l >= r) return true;

    if(arr[l] == arr[r]) return f(arr, l + 1, r - 1, num);
    else {

        if(num == -1) {
            return f(arr, l + 1, r, arr[l]) || f(arr, l, r - 1, arr[r]);
        }
        else if(arr[l] == num) return f(arr, l + 1, r, num);
        else if(arr[r] == num) return f(arr, l, r - 1, num);

        return false;
    }

    return false;
}

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

       if(f(arr, 0, n - 1, -1)) cout << "YES" << '\n';
       else cout << "NO" << '\n';
    }
    return 0;
}