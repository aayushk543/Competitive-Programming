
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
        int n,k;
        cin >> n >> k;

        vector<int> arr;

        vector<int> hash(200000,0);

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            hash[m]++;
            arr.push_back(m);
        }
        vector<int> arr2;
        for(int i = 0; i < 19999 && k > 0; i++){
            if (hash[i] == 0){
                k--;
                arr2.push_back(i);
            }
        }

        for(int i = 0; i < n + k; i++){
            if (i < n){
                cout << arr[i] << " ";
            }
        }

        for(int i = 0; i < k; i++){
            
        }

    }
    return 0;
}