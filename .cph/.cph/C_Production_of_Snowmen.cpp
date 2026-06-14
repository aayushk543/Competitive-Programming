#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;

bool check(int i, int j, int k, vector<int>& a, vector<int>& b, vector<int>& c){
    int n = a.size();

    int p = 0;

    while(p < n){
        int i1 = (i + p) % n;
        int i2 = (j + p) % n;
        int i3 = (k + p) % n;
        if(!(a[i1] < b[i2] && b[i2] < c[i3])){
            return false;
        }
        p = p + 1;
    }
    return true;
}

bool f(vector<int>&a, vector<int>&b, int i, int j){
    int n = a.size();

    int p = 0;

    while(p <= n){
        if(!(a[(p+i) % n] < b[(p+j) % n])) return false;
        p++;
    }
    return true;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n;

        cin >> n;

        vector<int> a;
        vector<int> b;
        vector<int> c;

        for(int i = 0; i < n; i++){
            int d;
            cin >> d;
            a.push_back(d);
        }

        for(int i = 0; i < n; i++){
            int d;
            cin >> d;
            b.push_back(d);
        }

        for(int i = 0; i < n; i++){
            int d;
            cin >> d;
            c.push_back(d);
        }
        int ans = 0;

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         for(int k = 0; k < n; k++){
        //             if(a[i] < b[j] && b[j] < c[k]){
        //                 if(check(i,j,k,a,b,c)){
        //                     ans = ans + 1;
        //                 }
        //             }
        //         }
        //     }
        // }

        long long c1 = 0;
        
        for(int j = 0; j < n; j++){
                c1 += f(a,b,0,j);
        }
        
        long long c2 = 0;
        
        for(int j = 0; j < n; j++){
                c2 += f(b,c,0,j);
        }
        

        cout << c1*c2*n  << '\n';
    }
    return 0;
}