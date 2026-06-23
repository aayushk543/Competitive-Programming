#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<long long>>& arr, long long level){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        if(level > arr[i][0]) level += arr[i][1];
        else return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;

       vector<long long> arr1(n);
       vector<long long> arr2(n);

       for(int i = 0; i < n; i++) cin >> arr1[i];
       for(int i = 0; i < n; i++) cin >> arr2[i];

       sort(arr1.begin(), arr1.end());
       sort(arr2.begin(), arr2.end());

       int j = 0;

       long long ans = 1;
       vector<long long> arr(n);

       for(int i = 0; i < n; i++){
        long long b = arr2[i];

        while(j < n && arr1[j] <= b) j++;
        arr[i] = (n-j);
       }

       for(int i = n-1; i >= 0; i--){
        ans *= (arr[i] - (n-1-i));
        ans % 1000000007;
       }

       cout << ans % 1000000007 << '\n';
    }
    return 0;
}