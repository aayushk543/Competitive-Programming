
#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long int> arr;
        unsigned int m;

        for(int i = 0; i < n; i++){
            long long int p;
            cin >> p;
            arr.push_back(p);
            m = m^p;
        }

        if(n % 2 == 0){
            cout << m << '\n';
        }
        else{
            cout << ~m << '\n';
        }
    }
    return 0;
}