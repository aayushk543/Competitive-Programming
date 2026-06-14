#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;

        if (n % 2 == 0){
            cout << (n-2)/2 << '\n';
        }
        else {
            cout << (n-1)/2 << '\n';
        }
    }
    return 0;
}
