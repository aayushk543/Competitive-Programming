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
        cin >> n;

        vector<long long> arr1, arr2;  // odd / even separated
        vector<long long> arr, orig1, orig2; // merged + original order trackers
        
        for(int i = 0; i < n; i++){
            long long m;
            cin >> m;
            if(m % 2 == 1){
                arr1.push_back(m);
                orig1.push_back(m);
            }
            else {
                arr2.push_back(m);
                orig2.push_back(m);
            }
        }

        int n1 = arr1.size();
        int n2 = arr2.size();

        // Sort copies for alternating pattern
        vector<long long> sorted1 = arr1;
        vector<long long> sorted2 = arr2;
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());

        int i = 0, j = 0; // sorted indexes
        int p1 = 0, p2 = 0; // original indexes (for leftovers)

        for(int k = 0; k < n1 + n2; k++){
            if ((k + 1) % 2 == 1) {  // odd index → arr1
                if (i < n1)
                    arr.push_back(sorted1[i++]);
                else if (p2 < orig2.size())
                    arr.push_back(orig2[p2++]);
            } else { // even index → arr2
                if (j < n2)
                    arr.push_back(sorted2[j++]);
                else if (p1 < orig1.size())
                    arr.push_back(orig1[p1++]);
            }
        }

        for (auto x : arr) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
