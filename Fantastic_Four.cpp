#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T, N;
    //cin >> T;
    int arr_i[1000], arr_j[1000], arr_k[1000], arr_l[1000], kk = 0;
    for(int ii = 1; ii <= 1000; ii++)
    {
        //cout << ii << "\n";
        int flag = 0;
        for(int i = 0; i <= 32; i++)
        {
            for(int j = 0; j <= 32; j++)
            {
                for(int k = 0; k <= 32; k++)
                {
                    for(int l = 0; l <= 32; l++)
                    {
                        //cout << i << "  " << j << "  " << k << "  " << l << "\n";
                        if(ii == (i * i + j * j + k * k + l * l))
                        {
                            arr_i[kk] = i;
                            arr_j[kk] = j;
                            arr_k[kk] = k;
                            arr_l[kk] = l;
                            flag = 1;
                            kk++;
                            break;
                        }
                    }
                    if(flag == 1)
                    {
                        break;
                    }
                }
                if(flag == 1)
                {
                    break;
                }
            }
            if(flag == 1)
            {
                break;
            }
        }
        //cout << (ii + 1) << "   " << arr_i[ii] << "  " << arr_j[ii] << "  " << arr_k[ii] << "  " << arr_l[ii] << "\n";
    }
    int P, Q, type, x, y;
    cin >> T;
    while(T--)
    {
        cin >> N >> Q >> P;
        int arr[N];
        for(int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        while(Q--)
        {
            cin >> type >> x >> y;
            if(type == 2)
            {
                int mul = 1;
                for(int i = x - 1; i < y; i++)
                {
                    mul *= arr[i];
                }
                mul %= P;
                //cout << mul << "   ";
                cout << arr_i[mul - 1] << " " << arr_j[mul - 1] << " " << arr_k[mul - 1] << " " << arr_l[mul - 1] << "\n";
            }
            else if(type == 1)
            {
                arr[x - 1] = y;
            }
        }
    }
    return 0;
}//Fantastic_Four.cpp