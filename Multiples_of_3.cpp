#include <bits/stdc++.h>
using namespace std;
int Divisible_Of_Three(int *BITree, int index)
{
    int sum = 0;
    index += 1;
    while(index > 0)
    {
        if(BITree[index] % 3 == 0)
        {
            sum += 1;
        }
        //sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
int sum(int x, int *BITree1, int *BITree2)
{
    return (Divisible_Of_Three(BITree1, x) * x) - Divisible_Of_Three(BITree2, x);
}
int Divisible_Range(int *BITree1, int *BITree2, int l, int r)
{
    return (sum(r, BITree1, BITree2) - sum(l - 1, BITree1, BITree2));
}
void UpdateBIT(int *BITree, int N, int index, int val)
{
    index += 1;
    while(index <= N)
    {
        BITree[index] = BITree[index]  + val;
        index += (index & (-index));
    }
}
void updateRange(int *BITree1, int *BITree2, int N, int l, int r, int val)
{
    UpdateBIT(BITree1, N, l, val);
    UpdateBIT(BITree1, N, r + 1, -val);
    UpdateBIT(BITree2, N, l, val * (l - 1));
    UpdateBIT(BITree2, N, r + 1, -val*r);
}
int *constructST(int N)
{
    int *BITree = new int[N + 1];
    for(int i = 1; i <= N; i++)
    {
        BITree[i] = 0;
    }
    return BITree;
}
int main()
{
    int N, l, r, val, Q, type;
    scanf("%d %d", &N, &Q);
    int *BITree1 = constructST(N);
    int *BITree2 = constructST(N);
    while(Q--)
    {
    	scanf("%d %d %d", &type, &l, &r);
    	if(type == 0)
    	{
    		updateRange(BITree1, BITree2, N, l, r, 1);
    	}
    	else if(type == 1)
    	{
    		printf("%d\n", Divisible_Range(BITree1, BITree2, l, r));
    	}
    }
    return 0;
}