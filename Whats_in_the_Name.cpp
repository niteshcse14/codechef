#include <bits/stdc++.h>
using namespace std;
string convert_valid(string temp)
{
    string res = "";
    for(int i = 0; i < temp.length(); i++)
    {
        int int_convert = (int)temp[i];
        //printf("%c  %d\n", temp[i], int_convert);
        if(i == 0 && int_convert > 90)
        {
            res += (char)(int_convert - 32);
        }
        else
        {
            if(int_convert <= 90 && i != 0)
            {
                res += (char)(int_convert + 32);
            }
            else
            {
                res += temp[i];
            }
        }
    }
    return res;
}
int main()
{
    int T, count = 0;
    scanf("%d", &T);
    T++;
    while(T--)
    {
        string str, temp;
        getline(cin, str);
        if(count == 0)
        {
            count++;
            continue;
        }
        string arr[100000];
        int j = 0;
        for(int i = 0; i < str.length(); i++)
        {
            temp = "";
            while(i < str.length() && str[i] != ' ')
            {
                temp += str[i++];
            }
            arr[j++] = temp;
        }
        if(j == 1)
        {
            cout << convert_valid(temp) << "\n";
        }
        else
        {
            for(int i = 0; i < (j - 1); i++)
            {
                temp = arr[i];
                int int_convert = (int)temp[0];
                if(int_convert > 90 )
                {
                    printf("%c. ", (char)(int_convert - 32));
                }
                else
                {
                    printf("%c. ", temp[0]);
                }
            }
            //printf("END\n");
            cout << convert_valid(arr[j - 1]) << "\n";
        }
    }
    return 0;
}