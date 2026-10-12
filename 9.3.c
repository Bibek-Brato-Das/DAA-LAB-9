#include <stdio.h>
int main(){
    int n, D, r, i, b, s = 0, d[100], f[100], u[100] = {0};
    scanf("%d %d %d", &D, &r, &n);
    for(i=0; i<n; i++) scanf("%d %d", &d[i], &f[i]);
    while(r < D){
        b = -1;
        for(i=0; i<n; i++)
            if(!u[i] && d[i] <= r && (b == -1 || f[i] > f[b])) b = i;
        if(b == -1){ printf("-1\n"); return 0; }
        u[b] = 1; r += f[b]; s++;
    }
    printf("%d\n", s);
    return 0;
}
