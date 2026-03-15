#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long p[20];
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &p[i]);
        total += p[i];
    }
    long long min_diff = total;
    for (int mask = 0; mask < (1 << n); mask++)
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                sum += p[i];
        }
        long long diff = llabs(total - 2 * sum);
        if (diff < min_diff)
            min_diff = diff;
    }
    printf("%lld\n", min_diff);
    return 0;
}