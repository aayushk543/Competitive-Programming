#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int x,y,z;
        vector<int> vec(3, 0);

        cin >> x >> y >> z;

        vec[0] = x;
        vec[1] = y;
        vec[2] = z;

        sort(vec.begin(), vec.end());

        // x = vec[0];
        // y = vec[1];
        // z = vec[2];

        string ans = "";
        int n = x + y + z;

        if(x == vec[2]) {
            for(int i = 0; i < n; i++) ans += 'P';
        }
        else if(y == vec[2]) {
            for(int i = 0; i < n; i++) ans += 'R';
        }
        else for(int i = 0; i < n; i++) ans += 'S';

        cout << ans << '\n';
        
    }
    return 0;
}