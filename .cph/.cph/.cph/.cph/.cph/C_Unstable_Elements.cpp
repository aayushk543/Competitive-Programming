#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        
        vector<int> lens;
        int pos = 0;

        while(pos < n) {
            int val = a[pos], count = 0;
            while(pos < n && a[pos] == val) {
                pos++;
                count++;
            }
            lens.push_back(count);
        }

        sort(lens.begin(), lens.end());
        int m = lens.size();

        vector<int> new_element;
        for(int i = m - 1; i >= 0;) {
            new_element.push_back(lens[i]);
            int v = lens[i];
            while(i >= 0 && lens[i] == v) i--;
        }

        long long alive = 0;
        long long total = 0;
        int ans = 0;
        int index = m - 1;

        for(int i = 0; i < new_element.size(); i++) {
            int cur = new_element[i];

            while(index >= 0 && lens[index] == cur) {
                alive++;
                total += cur;
                index--;
            }

            long long gap = k - total;
            if(gap % alive != 0) continue;
            long long shift = gap / alive;

            if(cur + shift < 1) continue;
            if(index >= 0 && lens[index] >= cur) continue;

            ans++;
        }

        cout << ans << '\n';
    }
    return 0;
}