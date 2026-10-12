#include <stdio.h>
#include <stdlib.h>
int gw(int n, int w[]){
    int a[50], i, j, k, s, cost = 0;
    for(i=0; i<n; i++) a[i] = w[i];
    while(n > 1){
        i = 0;
        while(i+2 < n && a[i] > a[i+2]) i++;       // smallest i with a[i] <= a[i+2]
        s = a[i] + a[i+1]; cost += s;
        for(k=i+2; k<n; k++) a[k-2] = a[k];        // remove the pair
        n -= 2;
        j = i - 1;
        while(j >= 0 && a[j] < s) j--;             // nearest on the left with a[j] >= s
        for(k=n; k>j+1; k--) a[k] = a[k-1];        // make room
        a[j+1] = s; n++;
    }
    return cost;
}
int dp(int n, int w[]){                            // exact optimum, to validate
    int c[50][50], p[51], i, j, k, l, t;
    p[0] = 0;
    for(i=0; i<n; i++){ p[i+1] = p[i] + w[i]; c[i][i] = 0; }
    for(l=2; l<=n; l++)
        for(i=0; i+l-1<n; i++){
            j = i + l - 1; c[i][j] = 1000000000;
            for(k=i; k<j; k++){
                t = c[i][k] + c[k+1][j];
                if(t < c[i][j]) c[i][j] = t;
            }
            c[i][j] += p[j+1] - p[i];
        }
    return c[0][n-1];
}
int main(){
    int n, i, g, o, w[20], demo[4] = {1, 2, 3, 4};
    printf("demo 1 2 3 4: gw = %d, dp = %d\n\n", gw(4, demo), dp(4, demo));
    printf("n\tgw\tdp\tsame\n");
    for(n=2; n<=12; n++){
        for(i=0; i<n; i++) w[i] = rand()%20 + 1;
        g = gw(n, w); o = dp(n, w);
        printf("%d\t%d\t%d\t%d\n", n, g, o, g == o);
    }
    return 0;
}
