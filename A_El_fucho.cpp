
#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int f(int n) {
    if (n == 2){
        return n;
    }

    return f(n-1) + 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 2 ){
            cout << "2" << '\n';
        }
        else {
            cout << f(n) << '\n';
        }
    }
    return 0;
}