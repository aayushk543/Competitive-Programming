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
        int n;
        cin >> n;
        vector<long long int> a;

        for(int i = 0; i < n; i++){
            long long m;
            cin >> m;
            a.push_back(m);
        }

        long long maxi = 0;
        int count = 0;

        for(int i = 0; i < n-2; i++){
            maxi = max(maxi,a[i]);
            if (i == 0 || i % 3 == 2){
            if (a[i] >= a[i+1]){
                if (maxi >= a[i]){
                    a[i+1] = maxi;
                    if(maxi == a[i]){
                        count++;
                    }
                }
                else {
                    count += a[i] - (a[i+1]) + 1;
                }
            }
            if(a[i+2] >= a[i+1]){
                if (maxi >= a[i+2]){
                    if(maxi == a[i+2])
                    count++;
                    a[i+2]--;
                }
                else {
                    count += a[i+2] - (a[i+1]) + 1;
                }
            }
            }
        }
        maxi = max(maxi,a[n-3]);
        if (n % 3 == 1){
            maxi = max(maxi,a[n-2]);
            if (a[n-2] >= a[n-1]){
                if (maxi >= a[n-2]){
                    a[n-2] = maxi;
                    if(maxi == a[n-2]){
                        count++;
                    }
                }
                else {
                    count += a[n-2] - (a[n-1] + 1);
                }
            }
        }
        
        
        cout << count << '\n';
    }
    return 0;
}
