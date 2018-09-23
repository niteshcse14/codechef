#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N_MAX = (1<<17) + 1;
const int MAX = (1e9) + 3;
const int mask = (1<<17)-1;
const int BIT = 18;
const int Q_MAX = (1<<18) + 1;
// To store how much died at that query.
int answer[Q_MAX];
// Height 
int h[N_MAX];
// Query : x,y
int query[Q_MAX][2];
// For SOS DP
int bitmask[Q_MAX];
int main(){
	int n;
	cin>>n;
	// Taking height as input
	for(int i=0;i<n;i++) cin>>h[i];
	int q;
	cin>>q;
	//Queries
	for(int i=0;i<q;i++){
		cin>>query[i][0]>>query[i][1];
		// If the value is greater than
		// 1<<17 trim it. As index can 
		// be at max 1<<17
		query[i][0] &= mask;
	}
	// Divide queires in blocks.
	int block_size = 1000, total_block = q/block_size + 1, index = 0;
	int duplicate ;
	// Traversing through each block
	// SQRT time
	for(int in_block = 0; in_block<total_block; in_block++){
		// For each block keep the bitmask 0 initially
		memset(bitmask, 0 , sizeof(bitmask));
		duplicate = index;
        // Traverse through the block
        // SQRT Time
		for(int i = 0;(i<block_size) && (index<q); i++,index++)
		{
			// Store the updates by the query.
			bitmask[query[index][0]] += query[index][1];
		}
		// SOS DP Procedure (Reverse)
		for(int bit = 0;bit<BIT;bit++){
			for(int i=mask;i>=0;i--){
				// If the ith bit is unset
				// Add the result from setting that bit
				// to current value.
				// For example i=10 (1010), this shall also
				// be updated by 11 (1011).
				// i.e. 1010^1 = 1011
				if(!((i>>bit)&1)){
					bitmask[i]+=bitmask[i^(1<<bit)];
					// As Height cannot be greater than 1e9
					bitmask[i]=min(bitmask[i],MAX);
				}
			}
		}// Time : 18 * (2^17)
		// After the above loop all the index of the bitmsk store
		// the total update due to the current block.
        int pos = duplicate;
        // Travering through each height
        // TO check which which index will decrease due to this block.
		for(int i=0;i<n;i++)
		{
			if(h[i]<=0)
				continue;
			// Decrease it
			// By the total height contributed by
			// this block
			h[i]-=bitmask[i];
			//printf("%d %d %d\n",i,h[i],bitmask[i]);
			// If this is greater than 0.
			// Continue
			if(h[i]>0)
				continue;
			// If less than or equal to zero
			// we need to check after which query we 
			// came to this less than zero value.
			// Current : To count (sequential) decrease by this block 
			int current = 0;
            duplicate = pos;
			// Traverse through each query in the current block
			for(int j=0;(j<block_size) && (duplicate<q); j++,duplicate++)
			{
				// If this query has an effect in
				// the decrease.
				if((i&query[duplicate][0])==i)
					current+=query[duplicate][1];
 				//printf("inside %d %d %d %d %d\n",i,duplicate,bitmask[i],h[i],current);
				// If after this query
				// the value of Height became non positive.
				if(((bitmask[i] + h[i]) - current)<=0){
					//printf("YES\n");
					// Add 1 to this query in the answer.
					// Denoting that this query resulted in decrease
					// answer[duplicate] heights.
					answer[duplicate]++;
					break;
				}
			}
			//printf("\n");
		}
	}
	int left = n;
	for(int i=0;i<q;i++){
		left = left - answer[i];
		cout<<left<<"\n";
	}
	return 0;
}