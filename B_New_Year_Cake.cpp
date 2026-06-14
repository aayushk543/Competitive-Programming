#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int a,b;

        cin >> a >> b;

        bool t1;
        bool t2;
        int c = 1;
        int ans = 0;
        int e = a;
        int f = b;

        if(a >= b){
            t1 = false;
            t2 = true;
        }
        else {
            t1 = true;
            t2 = false;
        }

        bool t3 = !t1;
        bool t4 = !t2;

        while(a >= 0 && b >= 0){
            
            if(t1){
                a = a - c;
            }
            if(t2){
                b = b - c;
            }

            c = c << 1;

            t1 = !t1;
            t2 = !t2;

            if(a >= 0 && b >= 0)
            ans = ans + 1;
        }

        int ans2 = 0;
        a = e;
        b = f;
        t1 = t3;
        t2 = t4;
        c = 1;

        while(a >= 0 && b >= 0){
            
            if(t1){
                a = a - c;
            }
            if(t2){
                b = b - c;
            }

            c = c << 1;

            t1 = !t1;
            t2 = !t2;

            if(a >= 0 && b >= 0)
            ans2 = ans2 + 1;
        }




        cout << max(ans,ans2) << '\n';
    }
    return 0;
}