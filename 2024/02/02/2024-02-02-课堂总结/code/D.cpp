#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;
#define int long long
int Read() {
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch) && ch != '-')  ch = getchar();
    if(ch == '-')  f = -1, ch = getchar();
    while(isdigit(ch))  x = x * 10 + ch - '0', ch = getchar();
    return x * f;  
}
const int Mod = 1e9 + 7;
long long n, m;
int k, c[55][55];
unordered_map<long long, int> f[55][55];
int dfs(int nw, int lim, long long s) {
    if(nw == -1)
        return (s == 0);
    //�߽�������ö��������λ���ϵ��������ʱ��s��Ҫ=0
    if(f[nw][lim].count(s))
        return f[nw][lim][s];
    int ans = 0, ff = (k / 2) * (k - k / 2);
    if((m >> nw) & 1) {
        //m��һλ�ϵ���Ϊ1 
        for (int i = 0; i <= k; i++) {
            long long res = s - (1ll << nw) * i * (k - i);
            if(res < 0 || res > (1ll << nw) * ff)
                continue;
            //��֦ 
            for (int j = max(0ll, (i - k + lim)); j <= min(lim, i); j++)
                ans = (ans + 1ll * c[k - lim][i - j] * c[lim][j] % Mod * dfs(nw - 1, lim - j, res)) % Mod;
            //ö�ٶ��ٸ������ڱ����Ƶ���Щ����ѡ�� 
        }
        return f[nw][lim][s] = ans;
    }
    //m��һλ�ϵ���Ϊ0 
    for (int i = lim; i <= k; i++) {
        long long res = s - (1ll << nw) * i * (k - i);
        if(res < 0 || res > (1ll << nw) * ff)
            continue;
        ans = (ans + 1ll * c[k - lim][i - lim] * dfs(nw - 1, lim, res)) % Mod;
    }
    return f[nw][lim][s] = ans;
}
signed main() {
    c[0][0] = 1;
    for (int i = 1; i <= 20; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % Mod;
    }
    scanf("%lld%lld%lld", &n, &m, &k);
    printf("%lld\n", dfs(45, k, n));
    return 0;
}
