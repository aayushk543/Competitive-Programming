#include<bits/stdc++.h>
using namespace std;
#define ll as long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        long long ans = 0;
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++){
            if(s[i] == '0') {
                int curr = i + 1;
                int count = 2;
                int index = curr;

                while(index <= n && s[index-1] == '0') {
                    //s[index-1] = '1';
                    if(vis[index - 1] == false) {
                        ans += curr;
                        vis[index - 1] = true;
                    }
                    //ans += curr;
                    index = curr * count;
                    count++;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
