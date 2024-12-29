#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define int long long
#define llu unsigned long long
#define endl "\n"
#define inf 0x3f3f3f3f
#define debug cout << "****************" << endl
using namespace std;

typedef pair<int, int> PII;

const int N = 5e5 + 7;

int pos[N];

struct node
{
    int l, r, id, me;
};

bool cmp(array<int, 3> x, array<int, 3> y)
{
    return x[1] < y[1];
}

// �����޸ģ������ѯ
int c[N];
int n, m;

int lowbit(int x)
{
    return x & (-x);
}

void updata(int i, int k)
{ // ��iλ�ü���k
    while (i <= n)
    {
        c[i] += k;
        i += lowbit(i);
    }
}

int getsum(int i)
{ // ��A[1 - i]�ĺ�
    int res = 0;
    while (i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}

void solve()
{
    cin >> n >> m;
    vector<int> a(n + 7);
    vector<vector<int>> st(n + 7);
    int siz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] <= n)
            st[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        pos[a[i]] = n + 2;
    vector<array<int, 3>> que;
    for (int i = 1; i <= n + 1; i++)
        st[i].push_back(n + 1);
    //��¼ÿ��ֵ���ֹ���λ�� 
    for (int mex = 1; mex <= n + 1; mex++)
    {
        int lst = 1;
        for (auto i : st[mex])
        {
            int l = lst;
            int r = i - 1;
            if (r - l >= 0)
                que.push_back({l, r, mex});
            lst = i + 1;
        }
    }
    int res = 0;
    sort(que.begin(), que.end(), cmp);
    //������ѯ�ʰ����Ҷ˵����� 
    int ans = -1e18;
    int j = 1;
    for (int i = 0; i < que.size(); i++)
    {
        while (j <= que[i][1])
        {
            updata(j, 1);
            updata(pos[a[j]], -1);
            pos[a[j]] = j;
            j++;
            //���Ҷ˵����һ����ɫ����λ��Ϊ�����ɫ�����ֵ�λ�ø�Ϊ1�������ڶ���λ�ø�Ϊ0 
        }
        ans = max(getsum(j - 1) - getsum(que[i][0] - 1) - que[i][2], ans);
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        pos[a[i]] = 0, c[i] = 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
