#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long>& arr, long long k) {

    int len = -1;
    int i = 0;
    int n = arr.size();

    while(i < n && arr[i] < k) i++;

    len = i;

    for(; i < n; ) {

        int curr_len = 0;

        while(i < n && arr[i] < k) {
            curr_len++;
            i++;
        } 

        if(curr_len != len && i != n) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(1) {
        int n;
        cin >> n;

        vector<long long> arr(n);
        long long l = 0, r = 0;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            r = max(r, arr[i]);
        }

        r = 1000;

        while(l <= r) {
            long long mid = (l + r) / 2;

            if(check(arr, mid) == false) l = mid + 1;
            else r = mid - 1; 
        }

        cout << l << '\n';
    }
    return 0;
}