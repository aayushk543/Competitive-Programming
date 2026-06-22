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

       vector<vector<long long>> arr(n, vector<long long>(2, 0));
       long long l = 100;
       long long r = 0;
       

       for(int i = 0; i < n; i++){

        cin >> arr[i][1];
        long long maxi = LLONG_MIN;

        for(int j = 0; j < arr[i][1]; j++) {
            long long m;
            
            cin >> m;
            maxi = max(maxi, m);
        }
        arr[i][0] = maxi;
        l = min(maxi, l);
        r = max(maxi, r);
       }

       sort(arr.begin(), arr.end());

       r += 1;
       long long ans = r;

       while(l <= r){
        long long mid = (l+r)/2;

        if(check(arr,mid)) {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else l = mid+1;
       }

       cout << ans << '\n';


    }
    return 0;
}