#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(true) {
        int n,q;
        cin >> n >> q;

        vector<long long> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i = 0; i < q; i++) {
            int q1, q2;
            cin >> q1 >> q2;

            pq.push({q1, 1});
            pq.push({q2 + 1, -1});
        }

        map<int, int> mp;
        int curr = 0;

        int prev = 1;
        vector<int> vec(n + 1, 0);

        while(!pq.empty()) {
            auto [index, ver] = pq.top();
            pq.pop();

            while(prev < index) {
                vec[prev++] = curr;
            }

            curr += ver;

            if(pq.empty()) {
                while(prev <= index && prev <= n) {
                    vec[prev++] = curr;
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            mp[vec[i]] += 1;
            //cout << vec[i] << " ";
        }

        long long ans = 0;
        int i = n-1;

        priority_queue<pair<int,int>> vec2;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            int val = it->first;
            int count = it->second;

            //cout << val << " " << count << '\n';

            vec2.push({val, count});
        }

        while(!vec2.empty()) {
            auto [val, count] = vec2.top();
            vec2.pop();

            while(count--) ans += val * arr[i--];
        }

        cout << ans << '\n';

    }
    return 0;
}