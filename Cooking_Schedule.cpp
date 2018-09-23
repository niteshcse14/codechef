#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int> > PII;
int main()
{
    int T, N, K, i, j, k, count, last_index, pos, num, num_f, num_s;
    char ch;
    string str;
    cin>>T;
    while(T--)
    {
        str.clear();
        cin>>N>>K>>str;
        assert(N > 0 and N == str.size());
        priority_queue<PII, vector<PII>> pq;
        //list<int , pair<int, int> > adj;
        ch = str[0];
        count = 1;
        last_index = 0;
        for(i = 1; i < N; i++)
        {
            if(ch == str[i])
            {
                count++;
            }
            else
            {
                pq.push(make_pair(count, make_pair(last_index, i - 1)));
                ch = str[i];
                last_index = i;
                count = 1;
            }
        }
        pq.push(make_pair(count, make_pair(last_index, i - 1)));
        PII p;
        p = pq.top();
        num = p.first;
        num_f = p.second.first;
        num_s = p.second.second;
        
        if(num == N && K == 0)
        {
            cout<<num<<"\n";
        }
        else if(N == 1 || num == 1)
        {
            printf("1\n");
        }
        else
        {
            int cc = 0;
            while(K > 0)
            {
                p = pq.top();
                num = p.first;
                num_f = p.second.first;
                num_s = p.second.second;
                if(num == 1)
                {
                    break;
                }
                if(num == 2)
                {
                    if(num_f == 0)
                    {
                        if(str[num_f] == '0')
                        {
                            str[num_f] = '1';
                        }
                        else
                        {
                            str[num_f] = '0';
                        }
                        K--;
                        pq.pop();
                        continue;
                    }
                    else if(num_s == (N - 1))
                    {
                        if(str[num_s] == '0')
                        {
                            str[num_s] = '1';
                        }
                        else
                        {
                            str[num_s] = '0';
                        }
                        K--;
                        pq.pop();
                        continue;
                    }
                    else
                    {
                        cc = 2;
                    }
                }
                pos = (num) / 2;
                if(str[num_f + pos] == '0')
                {
                    if((num_f + pos - 1) > 0 && (num_f + pos + 1) < N)
                    {
                        if(str[num_f + pos - 1] == '0' && str[num_f + pos + 1] == '0')
                        {
                            str[num_f + pos] = '1';
                        }
                    }
                    else if((num_f + pos - 1) > 0 && (num_f + pos + 1) >= N)
                    {
                        str[num_f + pos + 1] = '1';
                    }
                    else if((num_f + pos - 1) <= 0 && (num_f + pos + 1) < N)
                    {
                        str[0] = '1';
                    }
                }
                else if(str[num_f + pos] == '1')
                {
                    if((num_f + pos - 1) > 0 && (num_f + pos + 1) < N)
                    {
                        if(str[num_f + pos - 1] == '1' && str[num_f + pos + 1] == '1')
                        {
                            str[num_f + pos] = '0';
                        }
                    }
                    else if((num_f + pos - 1) > 0 && (num_f + pos + 1) >= N)
                    {
                        str[num_f + pos + 1] = '0';
                    }
                    else if((num_f + pos - 1) <= 0 && (num_f + pos + 1) < N)
                    {
                        str[0] = '0';
                    }
                }
                K--;
                pq.pop();
                pq.push(make_pair(pos, make_pair(num_f, num_f + pos - 1)));
                pq.push(make_pair(1, make_pair(num_f + pos, num_f + pos)));
                pq.push(make_pair(num - pos - 1, make_pair(num_f + pos + 1, num_s)));
                    
                p = pq.top();
                num = p.first;
            }
            p = pq.top();
            num = p.first;
            if(num == 1 && cc == 2)
            {
                cout<<cc<<"\n";
            }
            else
            {
                cout<<num<<"\n";
            }
        }
    }
    return 0;
}
//Cooking_Schedule.cpp 