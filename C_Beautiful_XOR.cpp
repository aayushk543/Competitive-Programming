#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        if(a < b){
            cout << -1 << '\n';
        }
        else 
        if (a == b) {
            cout << 0 << "\n";
        } else if ((a ^ b) <= a) {
            cout << 1 << "\n" << (a ^ b) << "\n";
        } else {
            cout << 2 << "\n";
            cout << a << " " << (a ^ b) << "\n";
        }
    }
    return 0;
}
