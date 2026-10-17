#include<bits/stdc++.h>
using namespace std;

bool check(int mid, vector<vector<int>>& vec) {
    int n = vec.size();

    int l = 0, r = mid;

    for(int i = 0; i < n; i++) {

        if(r < vec[i][0] || l > vec[i][1]) return false;
        else {
            l = max(l, vec[i][0]) - mid;
            if(l < 0) l = 0;
            r = min(r, vec[i][1]) + mid;
        }
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

        vector<vector<int>> vec(n, vector<int>(2, 0));

        for(int i = 0; i < n; i++) cin >> vec[i][0] >> vec[i][1];

        int l = 0, r = 1e9;

        while(l < r) {
            int mid = (l + r) / 2;

            if(check(mid, vec) == false) l = mid + 1;
            else r = mid; 
        }

        cout << l << '\n';
    }
    return 0;
}