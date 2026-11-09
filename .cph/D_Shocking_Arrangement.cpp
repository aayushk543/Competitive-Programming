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

        vector<long long> arr(n);
        long long mini = LLONG_MAX, maxi = LLONG_MIN;

        int pos = 0;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);

            if(arr[i] > 0) pos++;
        }

        if(mini == maxi && mini == 0) {
            cout << "No" << '\n';
            continue;
        }

        sort(arr.begin(), arr.end(), greater<long long>());

        long long target = maxi - mini;

        vector<long long> ans;

        int i = 0, j = n - 1;

        long long cu = 0;

        while(i < j) {

            if(cu < 0) cu = 0;

            while(i < j && cu + arr[i] < target) {
                cu += arr[i];
                ans.push_back(arr[i]);
                //cout << arr[i] << " ";
                i++;
            }

            //cout << arr[j] << " ";
            cu += arr[j];
            ans.push_back(arr[j--]);

            //cout << i << " " << j << '\n';

        }

        long long curr = 0;
        bool flag = true;

        for(int i = 0; i < ans.size(); i++) {
            curr += ans[i];

            if(curr < 0) curr = 0;

            if(curr >= target) flag = false;
        }

        if(ans.size() != n || flag == false) cout << "No" << '\n';
        else {
            cout << "Yes" << '\n';
            for(int i = 0; i < n; i++) cout << ans[i] << " ";
            cout << '\n';
        }

    }
    return 0;
}