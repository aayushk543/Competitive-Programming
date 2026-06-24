#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long>& arr, long long level){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        if(arr[i] < level) level++;
        else return false;
    }

    return true;
}

bool check2(vector<pair<long long, int>>& arr, long long level){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        if(arr[i].first <= level) level += arr[i].second;
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

       vector<pair<long long,int>> vp;

       for(int i = 0; i < n; i++){
        int k;
        cin >> k;

        // vector<long long> arr(k);
        // long long mini = LLONG_MAX;
        // long long maxi = LLONG_MIN;
        long long ans = INT_MIN;

        for(int j = 0; j < k; j++) {
            long long m;
            cin >> m;
            ans = max(ans, m - j);
        }

        // while(mini < maxi) {
        //     long long mid = (maxi+mini)/2;

        //     if(check(arr,mid) == false) mini = mid+1;
        //     else maxi = mid-1;
        // }

        vp.push_back({ans, k});

       }

       sort(vp.begin(), vp.end());

    //    long long l = vp[0].first;
    //    long long r = vp[vp.size()-1].first;

    //    while(l <= r){
    //     long long mid = (l+r)/2;

    //     if(check2(vp, mid) == false) l = mid+1;
    //     else r = mid-1;
    //    }

    long long ans = vp[0].first;
    long long sum = vp[0].second;

    for(int i = 1; i < n; i++){
        ans = max(ans, vp[i].first - sum);
        sum += vp[i].second;
    }

       cout << ans + 1 << '\n';


    }
    return 0;
}