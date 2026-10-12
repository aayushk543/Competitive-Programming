#include<bits/stdc++.h>
using namespace std;



long long f(vector<long long>& arr, int index, long long sum, map<pair<int, long long>, long long>& mp) {
    int n = arr.size();

    if(index == n) {
        long long maxi = arr[0];

        for(int i = 1; i < n; i++) maxi = max(maxi, arr[i]);
        return maxi;
    }

    if(mp.find({index, sum}) != mp.end()) return mp[{index, sum}];

    long long org = arr[index];

    arr[index] = arr[index] + sum;
    long long m1 = f(arr, index + 1, sum + arr[index], mp);

    arr[index] = org - sum;
    long long m2 = f(arr, index + 1, sum + arr[index], mp);

    arr[index] = org;
    long long m3 = f(arr, index + 1, sum + arr[index], mp);

    return mp[{index, sum}] = max(m1, max(m2, m3));
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
       //map<pair<int, long long>, long long> mp;
       

       for(int i = 0; i < n; i++) {
        cin >> arr[i];
       }

       long long sum = arr[0];

       vector<long long> arr2 = arr;

       long long ans = arr[0];

       for(int i = 1; i < n; i++) {

        
        ans = max(ans, max(arr[i] - sum, arr[i] + sum));

        // cout << arr[i] << " " << sum << '\n';
        // cout << arr[i] - sum << '\n';

        if(sum < 0) {
            arr[i] = arr[i] + sum;
        }
        else arr[i] = arr[i] - sum;

        // cout << 1 << " " << arr[i] << '\n';

        sum += arr[i];

        // cout << 2 << " " << sum << '\n';
       }

       sum = arr[0];

       for(int i = 1; i < n; i++) {

        ans = max(ans, max(arr2[i] - sum, arr2[i] + sum));

        if(sum >= 0) {
            arr2[i] = arr2[i] + sum;
        }
        else arr2[i] = arr2[i] - sum;

        sum += arr2[i];
       }


       cout << ans << '\n';
    }
    return 0;
}