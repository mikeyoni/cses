#include <stdio.h>

int main()
{
    long long k;
    scanf("%lld", &k);

    long long digits = 1;
    long long count = 9;
    long long start = 1;

    while (k > digits * count)
    {
        k -= digits * count;
        digits++;
        count *= 10;
        start *= 10;
    }

    // Now in the block of 'digits'-digit numbers
    long long num = start + (k - 1) / digits;
    int pos = (k - 1) % digits;

    char str[20];
    sprintf(str, "%lld", num);
    printf("%c\n", str[pos]);

    return 0;
}