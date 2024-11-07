char *multiply(char *num1, char *num2)
{
    int sza = strlen(num1);
    int szb = strlen(num2);
    int aa[1000] = {0};
    int bb[1000] = {0};
    for (int i = 0; i < sza; i++)
    {
        aa[sza - i] = num1[i] - '0';
    }
    for (int i = 0; i < szb; i++)
    {
        bb[szb - i] = num2[i] - '0';
    }
    int cc[1100] = {0};
    int szc = sza + szb;
    for (int i = 1; i <= sza; i++)
    {
        for (int j = 1; j <= szb; j++)
        {
            cc[i + j - 1] += aa[i] * bb[j];
            cc[i + j] += cc[i + j - 1] / 10;
            cc[i + j - 1] %= 10;
        }
    }
    while (cc[szc] == 0 && szc - 1 > 0)
    {
        szc--;
    }
    char *ccc = (char *)malloc(1000);
    for (int i = 0; i < szc; i++)
    {
        ccc[i] = cc[szc - i] + '0';
    }
    ccc[szc] = '\0';
    return ccc;
}