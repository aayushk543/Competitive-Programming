#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <string>
#include <numeric>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long int x;
        cin >> n >> x;

        vector<long long int> a;

        long long int sum = 0;

        for(int i = 0; i < n; i++){
            long long int m;
            cin >> m;
            sum += m;
            a.push_back(m);
        }

        cout << sum/n << '\n';

        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
