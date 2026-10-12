#include <stdio.h>
int main(){
    int n, i, sum = 0, r[1000], c[1000];
    scanf("%d", &n);
    for(i=0; i<n; i++){ scanf("%d", &r[i]); c[i] = 1; }
    for(i=1; i<n; i++)
        if(r[i] > r[i-1]) c[i] = c[i-1] + 1;
    for(i=n-2; i>=0; i--)
        if(r[i] > r[i+1] && c[i] <= c[i+1]) c[i] = c[i+1] + 1;
    for(i=0; i<n; i++) sum += c[i];
    printf("%d\n", sum);
    return 0;
}
