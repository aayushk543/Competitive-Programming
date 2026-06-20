#include<bits/stdc++.h>
using namespace std;

long long check(vector<long long>& arr, long long h){
    int n = arr.size();

    int i = 0;
    long long sum = 0;
    long long f_sum = 0;

    while(i < n){
        if(arr[i] < h) sum += h - arr[i];
        else {
            f_sum += sum;
            sum = 0;
        }
        i++;
    }

    return f_sum + sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        long long x; 
       cin >> n >> x;

       vector<long long> arr(n);

       long long maxi = 0;
       long long mini = LLONG_MAX;
       long long ans;

       for(int i = 0; i < n; i++) {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
       }

       maxi += x;

       while(mini <= maxi) {
        long long mid = (mini + maxi) / 2;

        if(check(arr, mid) <= x) {
            ans = mid;
            mini = mid + 1;
        }
        else maxi = mid - 1;
       }

       cout << ans << '\n';
    }
    return 0;
}