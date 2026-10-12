#include <stdio.h>
#include <string.h>
int main(){
    char s[1001], r[1001];
    int K, n, i, c, b, cnt[26] = {0}, last[26];
    scanf("%s %d", s, &K);
    n = strlen(s);
    for(i=0; i<n; i++) cnt[s[i]-'a']++;
    for(c=0; c<26; c++) last[c] = -1000000;
    for(i=0; i<n; i++){
        b = -1;
        for(c=0; c<26; c++)
            if(cnt[c] > 0 && last[c] + K <= i && (b == -1 || cnt[c] > cnt[b])) b = c;
        if(b == -1){ printf("\"\"\n"); return 0; }
        r[i] = 'a' + b; cnt[b]--; last[b] = i;
    }
    r[n] = 0;
    printf("%s\n", r);
    return 0;
}
