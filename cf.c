// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int t;
//     scanf("%d", &t);
//     while (t--) {
//         long long a, b;
//         scanf("%lld %lld", &a, &b);

//         __int128 P = (__int128)a * b;

//         long long ans = -1;

//         if ((a % 2 == 1) && (b % 2 == 1)) {
//             ans = (long long)(P + 1);
//         } else {
//             long long tmp = b;
//             int v2 = 0;
//             while (tmp % 2 == 0) {
//                 v2++;
//                 tmp /= 2;
//             }

//             int can = 0;
//             if ((a % 2 == 0) && (b % 2 == 0)) can = 1;
//             if ((a % 2 == 1) && v2 >= 2) can = 1;

//             if (can) {
//                 ans = (long long)(P / 2 + 2);
//             }
//         }

//         printf("%lld\n", ans);
//     }
//     return 0;
// }


// #include<stdio.h>
// #include<stdlib.h>

// int main () {
//     int t;
//     scanf("%d",&t);

//     while (t--){
//         int n;
//         scanf("%d",&n);
//         long long int arr[n];

//         for(int i = 0; i < n; i++){
//             scanf("%lld",&arr[i]);
//         }
        
//     }
// }

#include<stdio.h>

int main () {
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        
        if(a == b ){
            
            printf("%d\n",0);
        }
        else if ((a % b == 0) || (b % a == 0)){
            
            printf("%d\n",1);
        }
        else{
            printf("%d\n",2);
        }
    }
}