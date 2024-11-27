/*
题目描述
输入一行字符串（包含字母和数字字符，没有空格），如果我们把这行字符串中的‘5’和字母都看成空格，那么就得到一行用空格分割的若干非负整数（可能有些整数以‘0’开头，这些头部的‘0’应该被忽略掉，除非这个整数就是由若干个‘0’组成的，这时这个整数就是0）. 你的任务是对这些分割得到的整数从小到大排序，并去重后输出。
输入
第一行一个整数N，代表有N组测试数据，接下来的N行每行为一个由字母和数字组成的字符串，长度不大于1000。输入的字符串不可能全由‘5’或字母组成。
输出
对每个字符串进行分割并从小到大排序，输出排序并去重后的结果，相邻的两个整数之间用一个空格分开，行尾无空格。
样例输入
2
50a10a51
005123abc3213456
样例输出
0 1 10
0 6 123 32134
*/
#include <iostream>
#include <string>

using namespace std;
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void adjustup(int *arr, int child)
{
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if (arr[child] > arr[parent])
        {
            swap(arr[child], arr[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break;
        }
    }
}
void adjustdown(int *arr, int parent, int n)
{
    int child = parent * 2 + 1;
    while (child < n)
    {
        if (child + 1 < n && arr[child] < arr[child + 1])
        {
            child++;
        }
        if (arr[child] > arr[parent])
        {
            swap(arr[child], arr[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}
void heapsortup(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        adjustup(arr, i);
    }
    int end = n - 1;
    while (end > 0)
    {
        swap(arr[0], arr[end]);
        adjustdown(arr, 0, end);
        end--;
    }
}
int main()
{
    int n;
    cin >> n;
    string *s = new string[n];
    for (int k = 0; k < n; k++)
    {
        cin >> s[k];
    }
    for (int k = 0; k < n; k++)
    {
        int *size = new int[1000]{0};
        int len = 0;
        const char *str = s[k].c_str();
        int i = 0;
        while (i < s[k].size())
        {
            if (str[i] == '5' || (str[i] >= 'A' && str[i] <= 'z'))
            {
                while (str[i] == '5' || (str[i] >= 'A' && str[i] <= 'z'))
                {
                    i++;
                }
            }
            else
            {
                while (str[i] != '5' && str[i] >= '0' && str[i] <= '9')
                {
                    size[len]++;
                    i++;
                }
                len++;
            }
        }
        int *ans = new int[len]{0};
        int lenl = 0;
        i = 0;
        while (i < s[k].size())
        {
            if (str[i] == '5' || (str[i] >= 'A' && str[i] <= 'z'))
            {
                while (str[i] == '5' || (str[i] >= 'A' && str[i] <= 'z'))
                {
                    i++;
                }
            }
            else
            {
                while (str[i] != '5' && str[i] >= '0' && str[i] <= '9')
                {
                    int tmp = str[i] - '0';
                    for (int j = 0; j < size[lenl] - 1; j++)
                    {
                        tmp *= 10;
                    }
                    ans[lenl] += tmp;
                    size[lenl]--;
                    i++;
                }
                lenl++;
            }
        }
        heapsortup(ans, lenl);
        for (int j = 0; j < lenl; j++)
        {
            cout << ans[j] << " ";
        }
        cout << endl;
    }
}