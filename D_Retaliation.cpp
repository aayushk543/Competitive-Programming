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
        for (int i = 0; i < n; i++){
            long long int m;
            cin >> m;
            arr.push_back(m);
        }
        bool t = false;
        for(int i = 0; i < n; i++){
            if(arr[i] % (i+1) != 0 || arr[i] % (n - i) != 0){
                cout << "NO" << '\n';
                t = true;
                break;
            }
        }
        if(!t){
            cout << "YES" << '\n';
        }
    }
    return 0;
}