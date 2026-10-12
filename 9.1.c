#include <stdio.h>
int n;
double W, v[8], w[8], l[8], best;
double value(int p[]){                 // p[t] = item used at time t
    double d[8], r = W, tot = 0, x;
    int i, b, c, u[8] = {0};
    for(i=0; i<n; i++) d[i] = v[p[i]]/w[p[i]] - l[p[i]]*i;
    for(c=0; c<n; c++){
        b = -1;
        for(i=0; i<n; i++) if(!u[i] && (b == -1 || d[i] > d[b])) b = i;
        if(d[b] <= 0 || r <= 0) break;
        x = w[p[b]] < r ? w[p[b]] : r;
        tot += x*d[b]; r -= x; u[b] = 1;
    }
    return tot;
}
void perm(int p[], int k){             // try every order
    int i, t;
    double x;
    if(k == n){ x = value(p); if(x > best) best = x; return; }
    for(i=k; i<n; i++){
        t = p[k]; p[k] = p[i]; p[i] = t;
        perm(p, k+1);
        t = p[k]; p[k] = p[i]; p[i] = t;
    }
}
int main(){
    int i, b, t = 0, u[8] = {0}, p[8];
    double r, d, bd, x, tot = 0;
    scanf("%d %lf", &n, &W);
    for(i=0; i<n; i++) scanf("%lf %lf %lf", &v[i], &w[i], &l[i]);
    r = W;
    while(r > 0){                      // greedy
        b = -1; bd = 0;
        for(i=0; i<n; i++) if(!u[i]){
            d = v[i]/w[i] - l[i]*t;
            if(b == -1 || d > bd){ b = i; bd = d; }
        }
        if(b == -1 || bd <= 0) break;
        x = w[b] < r ? w[b] : r;
        printf("t=%d: item %d, take %.2f, density %.2f\n", t, b+1, x, bd);
        tot += x*bd; r -= x; u[b] = 1; t++;
    }
    printf("greedy value = %.2f\n", tot);
    for(i=0; i<n; i++) p[i] = i;
    best = 0; perm(p, 0);
    printf("exact best   = %.2f\n", best);
    return 0;
}
