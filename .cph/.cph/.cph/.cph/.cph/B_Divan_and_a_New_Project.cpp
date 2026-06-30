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

        vector<pair<int,int>> arr;

        for(int i = 0; i < n; i++) {
            int m;
            cin >> m;
            arr.push_back({m, i+1});
        }

        sort(arr.begin(), arr.end());

        deque<int> dq(n+1);
        dq[0] = 0;
        int count = 1;
        long long ans = 0;

        for(int i = n-1; i >= 0; i-=2){
            dq[arr[i].second] = count;
            ans += (long long)count * 2 * arr[i].first;
            if(i - 1 >= 0) {
                dq[arr[i-1].second] = -1*(count);
                ans += (long long)count * 2 * arr[i-1].first;
            }
            count++;
        }

        cout << ans << '\n';
        for(int i = 0; i < n+1; i++) cout << dq[i] << " ";
        cout << '\n'; 

    }
    return 0;
}