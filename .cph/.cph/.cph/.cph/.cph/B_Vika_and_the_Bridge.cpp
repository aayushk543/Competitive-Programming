#include<bits/stdc++.h>
using namespace std;

int check(vector<int>& vec, int m){
    int n = vec.size();
    
    vector<vector<int>> diff(m + 1, vector<int>(3, -1));

    int ans = INT_MAX;

    for(int i = 0; i < n; i++){
        if(diff[vec[i]][2] == -1){
            diff[vec[i]][0] = i;
        }
        else if(diff[vec[i]][0] <= i - diff[vec[i]][2] - 1){
            diff[vec[i]][1] = diff[vec[i]][0];
            diff[vec[i]][0] = i - diff[vec[i]][2] - 1; 
        }
        else if(diff[vec[i]][1] <= i - diff[vec[i]][2] - 1){
            diff[vec[i]][1] = i - diff[vec[i]][2] - 1; 
        }

        diff[vec[i]][2] = i;
    }

    for(int i = 1; i <= m; i++){
        if(diff[i][0] <= n - diff[i][2] - 1){
            diff[i][1] = diff[i][0];
            diff[i][0] = n - diff[i][2] - 1; 
        }
        else if(diff[i][1] <= n - diff[i][2] - 1){
            diff[i][1] = n - diff[i][2] - 1; 
        }

        ans = min(ans, max(diff[i][0]/2, diff[i][1]));
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> paint(n);

        int min_diff = INT_MAX;

        for(int i = 0; i < n; i++) cin >> paint[i];

        int ans = check(paint, k);

        cout << ans << '\n';
    }
    return 0;
}