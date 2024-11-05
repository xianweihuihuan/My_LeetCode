char *intToRoman(int num)
{
    int b[5];
    char an[100];
    int i = 0;
    while (num)
    {
        b[i++] = num % 10;
        num /= 10;
    }
    int j = 0;
    int y = i - 1;
    int r = 0;
    while (y >= 0)
    {
        j = 0;
        for (j; j < y; j++)
        {
            b[y] *= 10;
        }
        if (b[y] == 3000)
        {
            an[r++] = 'M';
            an[r++] = 'M';
            an[r++] = 'M';
        }
        else if (b[y] == 2000)
        {
            an[r++] = 'M';
            an[r++] = 'M';
        }
        else if (b[y] == 1000)
        {
            an[r++] = 'M';
        }
        else if (b[y] == 900)
        {
            an[r++] = 'C';
            an[r++] = 'M';
        }
        else if (b[y] == 400)
        {
            an[r++] = 'C';
            an[r++] = 'D';
        }
        else if (b[y] > 400 && b[y] < 900)
        {
            an[r++] = 'D';
            b[y] -= 500;
            for (; b[y] > 0; b[y] -= 100)
            {
                an[r++] = 'C';
            }
        }
        else if (b[y] < 400 & b[y] >= 100)
        {
            for (; b[y] > 0; b[y] -= 100)
            {
                an[r++] = 'C';
            }
        }
        else if (b[y] == 90)
        {
            an[r++] = 'X';
            an[r++] = 'C';
        }
        else if (b[y] == 40)
        {
            an[r++] = 'X';
            an[r++] = 'L';
        }
        else if (b[y] > 40 && b[y] < 90)
        {
            an[r++] = 'L';
            b[y] -= 50;
            for (; b[y] > 0; b[y] -= 10)
            {
                an[r++] = 'X';
            }
        }
        else if (b[y] < 40 && b[y] >= 10)
        {
            for (; b[y] > 0; b[y] -= 10)
            {
                an[r++] = 'X';
            }
        }
        else if (b[y] == 9)
        {
            an[r++] = 'I';
            an[r++] = 'X';
        }
        else if (b[y] == 4)
        {
            an[r++] = 'I';
            an[r++] = 'V';
        }
        else if (b[y] > 4 && b[y] < 9)
        {
            an[r++] = 'V';
            b[y] -= 5;
            for (; b[y] > 0; b[y] -= 1)
            {
                an[r++] = 'I';
            }
        }
        else if (b[y] < 4 && b[y] > 0)
        {
            for (; b[y] > 0; b[y]--)
            {
                an[r++] = 'I';
            }
        }
        y--;
    }
    an[r] = '\0';
    return an;
}