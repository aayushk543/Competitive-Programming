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

bool f(vector<vector<char>>& a, int& i, int& j, int& y, int& count1, int& count2){
    if(y )
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<char>> a(n, vector<char>(n,'.'));

        int p,q;
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char c;
                cin >> c;
                a[i][j] = c; 
                if(a[i][j] == '#'){
                    p = i;
                    q = j;
                }
            }
        }
    }
}
