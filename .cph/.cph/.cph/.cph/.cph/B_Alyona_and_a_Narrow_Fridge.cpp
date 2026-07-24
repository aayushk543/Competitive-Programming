#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long>& arr, int mid, long long h) {

    vector<long long> arr2;

    for(int i = 1; i <= mid; i++) arr2.push_back(arr[i]);

    sort(arr2.begin(), arr2.end());

    long long ans = 0;

    for(int i = arr2.size() - 1; i >= 0; i -= 2) {
        ans += arr2[i];

        if(ans > h) return false;
    }

    return ans <= h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long h;
    cin >> h;

    vector<long long> arr(n + 1); 

    for(int i = 1; i <= n; i++) cin >> arr[i];

    int l = 0, r = n;
    int ans = -1;

    while(l <= r) {
        int mid = (l + r) >> 1;

        if(check(arr, mid, h)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans << '\n';

    return 0;
}