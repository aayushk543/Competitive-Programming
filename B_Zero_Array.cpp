#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    if(1) {
        int n;
        cin >> n;

        vector<long long> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        long long maxi = 0;
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i];
            maxi = max(maxi, arr[i]);
        }

        //sum -= maxi;

        if(sum % 2 == 0 && maxi <= sum - maxi) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}