#include<bits/stdc++.h>
using namespace std;

long long check(vector<long long>& arr, long long mid) {
    long long ans = -1;

    for(int i = 0; i < arr.size() - 1; i++) {
        long long curr1 = arr[i];
        long long curr2 = arr[i+1];

        if(curr1 > curr2) continue;

        long long diff = curr2 - curr1;
        
    }
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        long long k;

        cin >> n >> k;

        vector<long long> arr(n);

        long long maxi = 0;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
        }

        long long l = maxi, r = maxi + k;

        while(l < r) {
            long long mid = (l + r) >> 1;

            long long curr = check(arr, mid);
        }
    }
    return 0;
}