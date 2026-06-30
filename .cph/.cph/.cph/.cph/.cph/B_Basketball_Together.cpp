#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long d;

    cin >> n >> d;

    vector<long long> team(n);

    for(int i = 0; i < n; i++) cin >> team[i];

    sort(team.begin(), team.end());

    int j = 0;
    int ans = 0;

    for(int i = n-1; i >= 0 && j <= i; i--){
        long long value = team[i];
        int req = (d / value);

        if(j + req <= i) {
            j += req;
            ans++;
        }
        else break;
    }

    cout << ans << '\n';
    
    return 0;
}