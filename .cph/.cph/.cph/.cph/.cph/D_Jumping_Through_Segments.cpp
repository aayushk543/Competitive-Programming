#include<bits/stdc++.h>
using namespace std;

bool check(vector<pair<long long, long long>>& vp, long long limit) {
    int l = vp.size();

    long long curr = 0;

    for(int i = 0; i < l; i++) {
        if(limit > vp[i].first - curr) return false;
        else curr = min(curr + limit, vp[i].second);

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

        vector<pair<long long, long long>> vp;

        long long last = 0;
        long long mini = LLONG_MAX, maxi = LLONG_MIN;

        for(int i = 0; i < n; i++) {
            long long first, second;
            cin >> first >> second;

            mini = min(mini, first - last);
            maxi = max(maxi, first - last);
            last = second;

            vp.push_back({first, second});
        }

        while(maxi > mini) {
            long long mid = (maxi + mini) / 2;

            if(check(vp, mid)) maxi = mid;
            else mini = mid + 1;
        }

        cout << maxi << '\n';
    }
    return 0;
}   