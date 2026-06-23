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

       for(int i = 0; i < n; i++) {
        cin >> arr[i];
       }

       int maxlen = 0;

       int left = arr[0], right = arr[n-1];

       int l = 0, r = n-1;

       while(l < r){
        if(left == right) {
            maxlen = max(maxlen, l+1+n-r);
            l++;
            r--;

            if(l < r) {
                left += arr[l];
                right += arr[r];
            }
        }
        else if(left > right) {
            r--;
            right += arr[r];
        }
        else {
            l++;
            left += arr[l];
        }
       }

       cout << maxlen << '\n';

    }
    return 0;
}