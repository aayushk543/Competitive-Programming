#include<bits/stdc++.h>
using namespace std;

long long cost(vector<long long>& arr, long long mid) {
    int n = arr.size();

    long long count1 = 0;
    long long count2 = 0;

    long long diff1 = 0;
    long long diff2 = 0;
    int index = 0;

    // for(; index < n; index++) {
    //     if(arr[index] > mid) {
    //         index -= 1;
    //         break;
    //     }
    // }

    // for(int i = 0; i < n; i++) {
    //     diff1 = max(diff1, abs(mid - arr[i]));
    // }

    // for(int i = 0; i <= index; i++) {
    //     count1 += abs(diff1 - arr[i]);
    // }

    // for(int i = n - 1; i > index; i--) {
    //     diff2 = max(diff2, abs(mid - arr[i]));
    // }

    // for(int i = n - 1; i > index; i--) {
    //     count2 += abs(diff1 - arr[i]);
    // }

    for(int i = 0; i < n; i++) count1 += abs(mid - arr[i]);

    return count1;
}


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

        sort(arr.begin(), arr.end());

        map<long long, int> mp;

        long long mini = LLONG_MAX, maxi = LLONG_MIN;

        for(int i = 0; i < n; i++) {
            mp[arr[i]] += 1;
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }

        if(mini == maxi) cout << 0 << " " << 0 << '\n';
        else {
            long long l = 0, r = n - 1;

            while(l < r) {
                long long mid = (l + r) >> 1;

                if(cost(arr, arr[mid]) > cost(arr, arr[mid + 1])) l = mid + 1;
                else r = mid; 
            }

            cout << cost(arr, arr[l]) << " " << arr[n-1] - arr[0] << '\n';
        }


    }
    return 0;
}