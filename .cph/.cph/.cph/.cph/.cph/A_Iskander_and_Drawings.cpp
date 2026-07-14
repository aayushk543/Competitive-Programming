#include<bits/stdc++.h>
using namespace std;

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

        int maxi = 0;
        int curr = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '*'){
                curr = 0;
            }
            else {
                curr++;
                maxi = max(curr, maxi);
            }
        }

        cout << ceil((double)maxi / 2.0) << '\n';
    }
    return 0;
}