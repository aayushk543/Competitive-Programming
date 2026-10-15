#include<bits/stdc++.h>
using namespace std;

int f(vector<vector<int>>& dist, int sum, int index, int k) {
    int req = (sum % k);

    int l = 0, r = dist[req].size();

    //if(index == 2) cout << r << '\n';

    if(r == 0) return 0;

    while(l < r) {
        int mid = (l + r) / 2;

        if(index - dist[req][mid] <= k) r = mid;
        else l = mid + 1;
    }

    //if(index == 2) cout << l << " " << r << '\n';

    if(l == 0) return -1;
    return l;
}

// 1 2 0 1 2 0 1 2 0

// dist[0] = {2, 5, 8}
// dist[1] = {0, 3, 6}
// dist[2] = {1, 4, 7}


// 0, 1, 0, 1, 1

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n,k;
       cin >> n >> k;

       vector<int> arr(n);
       long long ans = 0;

       for(int i = 0; i < n; i++) cin >> arr[i];

       vector<vector<int>> dist(k + 1);
       dist[0].push_back(-1);
       long long sum = 0;

       for(int i = 0; i < n; i++) {

        sum += arr[i];
        sum %= k;
        int num = f(dist, sum, i, k);
        if(num > 0) ans += num;

        //cout << i << " " << num << '\n';
        dist[sum % k].push_back(i);
       }

       cout << ans << '\n';
    }
    return 0;
}