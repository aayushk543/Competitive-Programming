#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long n,k;
        cin >> n >> k;

        if(k % 2 == 0) {
            if(n%2 == 0) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else if(n % 2 == 0 || n >= k) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}