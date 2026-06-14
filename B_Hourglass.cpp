#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long s, k, m;
        cin >> s >> k >> m;
        
        // Find the last flip time at or before m
        long long last_flip = (m / k) * k;
        
        // Time elapsed since last flip
        long long time_since_flip = m - last_flip;
        
        // If time since flip >= s, sand has finished falling
        if(time_since_flip >= s) {
            cout << 0 << '\n';
        } else {
            // Sand remaining = s - time_since_flip
            cout << s - time_since_flip << '\n';
        }
    }
    return 0;
}