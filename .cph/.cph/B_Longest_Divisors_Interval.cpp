#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       long long n;
       cin >> n;

       int count = 0;
       int curr = 0;

       for(int i = 1; i <= 50; i++) {
        if(n % i == 0) curr++;
        else curr = 0;

        count = max(count, curr);
       }

       cout << count << '\n'; 
    }
    return 0;
}