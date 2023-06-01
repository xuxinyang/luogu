#include <bits/stdc++.h>

const int N = 50851836 + 7, block = 2 * 3 * 5 * 7 * 11 * 13 * 17, M = 7, K = 1959, P = 1e9, Q = 500;
int prime[N], mark[block + 7];
bool p[block + 7], pre_block[block + 7], cur_block[block + 7];

inline int max(int a, int b)
{
    return a > b ? a : b;
}

inline int init()
{
    int cnt = 0, block_cnt = 0, ans;
    p[0] = p[1] = true;
    for (register int i = 1; i < block; i++)
    {
        pre_block[i] = 1;
    }
    for (register int i = 2; i <= block; i++)
    {
        if (!p[i])
        {
            prime[++cnt] = i;
            if (cnt <= M)
            {
                prime[cnt] = i;
                pre_block[i] = 0;
            }
        }
        for (register int j = 1; j <= cnt && i * prime[j] <= block; j++)
        {
            register int t = i * prime[j];
            p[t] = true;
            if (j <= M)
                pre_block[t] = 0;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (register int i = 1; i < block; i++)
    {
        if (pre_block[i])
            mark[++block_cnt] = i;
    }
    ans = cnt;
    for (register int i = 1; i < K; i++)
    {
        register int end = (i + 1) * block - 1, start = i * block;
        memcpy(cur_block, pre_block, sizeof(bool) * block);
        for (register int j = M + 1; prime[j] * prime[j] <= end; j++)
        {
            register int t1 = max((start - 1) / prime[j] + 1, prime[j]) * prime[j], t2 = prime[j] << 1;
            if (!(t1 & 1))
                t1 += prime[j];
            for (register int k = t1 - start; k < block; k += t2)
            {
                cur_block[k] = 0;
            }
        }
        for (register int j = 1; j <= block_cnt; j++)
        {
            if (cur_block[mark[j]])
                prime[++ans] = start + mark[j];
        }
    }
    return ans;
}

inline void write(int n)
{
    if (n >= 10)
        write(n / 10);
    putchar(n % 10 + '0');
}

int main()
{
    int cnt = init();
    for (register int i = 1, j = 0; i <= cnt && prime[i] <= P; i++)
    {
        if (++j % Q == 1)
        {
            write(prime[i]);
            putchar('\n');
        }
    }
    return 0;
}