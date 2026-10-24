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

       vector<long long> arr(n + 1);

       for(int i = 1; i <= n; i++) cin >> arr[i];

       vector<int> divisor;

       for(int i = 1; i <= n / 2; i++) {

        if(n % i == 0) {
            divisor.push_back(i);
            //divisor.push_back(n / i);
        }
       }

       //sort(arr.begin(), arr.end());

       //vector<long long> arr2 = arr;

       //reverse(arr2.begin(), arr2.end());

       //sort(arr2.begin(), arr2.end(), greater<long long>());

       for(int i = 1; i <= n; i++) arr[i] += arr[i-1];

       //for(int i = 1; i < n; i++) arr2[i] += arr2[i-1];

       long long ans = 0;

       for(int i = 0; i < divisor.size(); i++) {

        int curr = divisor[i];

        long long mini = LLONG_MAX;
        long long maxi = LLONG_MIN;

        for(int i = 1; i <= n / curr; i++) {

            mini = min(mini, arr[i * curr] - arr[(i - 1) * curr]);
            maxi = max(maxi, arr[i * curr] - arr[(i - 1) * curr]);
        }

        ans = max(ans, maxi - mini);

        //cout << divisor[i] << '\n';
       }

       cout << ans << '\n';
    }
    return 0;
}