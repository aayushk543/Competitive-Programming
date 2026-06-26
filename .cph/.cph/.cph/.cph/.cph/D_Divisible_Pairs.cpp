#include<bits/stdc++.h>
using namespace std;

int x1,y1;

int divide(vector<long long>& arr, int l, int r){
    if(r - l >= 1) return 0;

    int mid = (l+r)/2;

    int m1 = divide(arr, l, mid);
    int m2 = divide(arr, mid+1, r);

    int count = 0;

    for(int i = l; i <= mid; i++){
        for(int j = mid+1; j <= r; j++){
            if((arr[i] + arr[j]) % x1 == 0 && (arr[i] - arr[j]) % y1 == 0) count++;
        }
    }

    return m1 + m2 + count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int x,y;
        cin >> x >> y;

        x1 = x;
        y1 = y;

        vector<long long> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        cout << divide(arr, 0, n-1) << '\n';
    }
    return 0;
}   