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

       vector<int> arr(10001, 0);
       int count_1 = 0;

       for(int i = 1; i <= n; i++) {
        int m;
        cin >> m;

        arr[m] = i;

        if(m == 1) count_1++;
       }

       int maxi = 0;

       for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {

            if(arr[i] > 0 && arr[j] > 0 && gcd(i, j) == 1) maxi = max(maxi, arr[i] + arr[j]);
        }
       }

       if(maxi > 0) cout << maxi << '\n';
       else cout << -1 << '\n';
    }
    return 0;
}