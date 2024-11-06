int romanToInt(char *s)
{
    int he = 0;
    int sz = strlen(s);
    for (int i = 0; i < sz; i++)
    {
        if (s[i] == 'M')
        {
            he += 1000;
            if (i - 1 >= 0 && s[i - 1] == 'C')
            {
                he -= 200;
            }
        }
        else if (s[i] == 'D')
        {
            he += 500;
            if (i - 1 >= 0 && s[i - 1] == 'C')
            {
                he -= 200;
            }
        }
        else if (s[i] == 'C')
        {
            he += 100;
            if (i - 1 >= 0 && s[i - 1] == 'X')
            {
                he -= 20;
            }
        }
        else if (s[i] == 'L')
        {
            he += 50;
            if (i - 1 >= 0 && s[i - 1] == 'X')
            {
                he -= 20;
            }
        }
        else if (s[i] == 'X')
        {
            he += 10;
            if (i - 1 >= 0 && s[i - 1] == 'I')
            {
                he -= 2;
            }
        }
        else if (s[i] == 'V')
        {
            he += 5;
            if (i - 1 >= 0 && s[i - 1] == 'I')
            {
                he -= 2;
            }
        }
        else if (s[i] == 'I')
        {
            he += 1;
        }
    }
    return he;
}