#include"bits/stdc++.h"
using namespace std;
int fa[1000006];
int finds(int u);
void unin(int u,int v)//���鼯�ϲ�����
{
    fa[finds(v)]=finds(u);
}
int finds(int u)//���Ҽ��ϱ�Ų���
{
    if(fa[u]!=u)fa[u]=finds(fa[u]);
    return fa[u];
}
void init(int n)//���鼯��ʼ��
{
    for(int i=0;i<=n;i++)fa[i]=i;
}
int a[500005],b[500005];
long long c[500005];
int x[500005],y[500005],ans[500005];
int main()
{
    int n,m,q;
    long long v;
    cin>>n>>m>>q>>v;
    for(int i=0;i<m;i++)scanf("%d%d%lld",&a[i],&b[i],&c[i]);
    for(int i=0;i<q;i++)scanf("%d%d",&x[i],&y[i]);
    int t=62;
    while(t--)
    {
        init(n);
        for(int i=0;i<m;i++)if((c[i]&v)==v)unin(a[i],b[i]);
        //������������1��λ�ö���1 
        for(int i=0;i<q;i++)if(finds(x[i])==finds(y[i]))ans[i]=1;
        v=v+(v&-v);
        //ÿ����v������1���0 
        if(v==0)break;
    }
    for(int i=0;i<q;i++)if(ans[i])printf("Yes\n");
    else printf("No\n");
    return 0;
}
