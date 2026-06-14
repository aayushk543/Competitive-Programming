#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long n,k;
        cin >> n >> k;

        long long x;
        cin >> x;

        long long maxi = k*(2*n - k + 1)/2;
        long long mini = k*(k+1)/2;
        

        if(x >= mini && x <= maxi){
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}