#include<bits/stdc++.h>
using namespace std;

long long f(int med, vector<vector<int>>& vec, bool p) {
    int mini_x = 1e9, mini_y = 1e9;
    int maxi_x = 0, maxi_y = 0;


    for(int i = 0; i < vec.size(); i++) {
        if(p == 0 && vec[i][0] == med) continue;
        if(p == 1 && vec[i][1] == med) continue;

        mini_x = min(mini_x, vec[i][0]);
        maxi_x = max(maxi_x, vec[i][0]);

        mini_y = min(mini_y, vec[i][1]);
        maxi_y = max(maxi_y, vec[i][1]);
    }

    long long l = (maxi_x - mini_x) + 1;
    l = max(1LL, l);
    long long b = (maxi_y - mini_y) + 1;
    b = max(b, 1LL);

    long long ans = l * b;

    if(ans == vec.size() - 1) ans = min((l + 1)*b, l*(b + 1));

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> vec(n, vector<int>(2, 0));

        for(int i = 1; i <= n; i++) cin >> vec[i-1][0] >> vec[i-1][1];

        int mini_x = 1e9, mini_y = 1e9;
        int maxi_x = 0, maxi_y = 0;

        sort(vec.begin(), vec.end());

        for(int i = 0; i < n; i++) {
            mini_x = min(mini_x, vec[i][0]);
            maxi_x = max(maxi_x, vec[i][0]);

            mini_y = min(mini_y, vec[i][1]);
            maxi_y = max(maxi_y, vec[i][1]);
        }

        long long l = (maxi_x - mini_x) + 1;
        l = max(1LL, l);

        long long b = (maxi_y - mini_y) + 1;
        b = max(1LL, b);

        long long area = l * b;

        if(area == n) {
            cout << area << '\n';
        }
        else {
            int count_mini_x = 0;
            int count_maxi_x = 0;
            int count_mini_y = 0;
            int count_maxi_y = 0;

            int index_mini_x = -1, index_maxi_x = -1, index_mini_y = -1, index_maxi_y = -1;

            for(int i = 0; i < n; i++) {
                if(vec[i][0] == mini_x) count_mini_x++;
                if(vec[i][0] == maxi_x) count_maxi_x++;

                if(vec[i][1] == mini_y) count_mini_y++;
                if(vec[i][1] == maxi_y) count_maxi_y++;
            }

            long long ans = area;

            if(count_mini_x <= 1) ans = min(ans, f(mini_x, vec, 0));
            if(count_maxi_x <= 1) ans = min(ans, f(maxi_x, vec, 0));
            if(count_mini_y <= 1) ans = min(ans, f(mini_y, vec, 1));
            if(count_maxi_y <= 1) ans = min(ans, f(maxi_y, vec, 1));

            cout << ans << '\n';
        }

    }
    
    return 0;
}