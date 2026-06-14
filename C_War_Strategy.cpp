#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

long long f(int n){
    
    long long m = 1;
    for(int i = 0; i < n; i++){
        m = m*2;
    }
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        long long m = f(n);

        vector<int> arr(m,0);

        for(int i = 0; i < n; i++){
            arr[i] = f(n-i) - 1;
        }
        int j = 0;

        for(int i = n; i < m; i++){
            if(i - n == f(n-i) - 1){
                j++;
                continue;
            }
            arr[i] = i - n + j;
        }
        
        for(int i = 0; i < arr.size(); i++){
            cout << arr[i]  << " ";
        }
        cout << '\n'; 

    }
    return 0;
}
