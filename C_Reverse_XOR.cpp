#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long m;
        cin >> m;

        bool ran = false; 
        long long n = 2;

        for (int i = 1; i <= 32; i++) {
            n *= 2;
            if (n == m && i % 2 == 1) {
                cout << "NO\n";
                ran = true; 
                break;
            }
        }

        
if(!ran){
        if ((n & (n + 1)) == 0)
            cout << "NO\n";
        else 
        cout << "YES" << '\n'; }   
    }

    return 0;
}
