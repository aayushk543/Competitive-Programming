#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int maxi = 0;
    int max_p = 1;

    int i = 0;

    for(i = 0; i < n; i++){
        int curr = s[i] - 'a';
        if(curr < maxi) {
            cout << "YES" << '\n';
            cout << max_p << " " << i + 1 << '\n';
            break;
        } 
        else {
            maxi = curr;
            max_p = i + 1;
        }
    }

    if(i == n) cout << "NO" << '\n';

    
}