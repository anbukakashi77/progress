#include <bits/stdc++.h> 
using namespace std; 

struct node { 
	int sum, prefixsum, suffixsum, maxsum; 
};

const int N=10001;
int a[N];
node tree[4 * N]; 

void build(int arr[], int ss, int se, int si) 
{ 
	if (ss == se) { 
		tree[si].sum = arr[ss]; 
		tree[si].prefixsum = arr[ss]; 
		tree[si].suffixsum = arr[ss]; 
		tree[si].maxsum = arr[ss]; 
	} 
	else { 
		int mid = (ss + se) / 2; 
		
		build(arr, ss, mid, 2 * si + 1); 
		
		build(arr, mid + 1, se, 2 * si + 2); 

		tree[si].sum = tree[2 * si + 1].sum + 
						tree[2 * si + 2].sum; 

		tree[si].prefixsum = 
					max(tree[2 * si + 1].prefixsum, 
					tree[2 * si + 1].sum + 
					tree[2 * si + 2].prefixsum); 

		tree[si].suffixsum = 
					max(tree[2 * si + 2].suffixsum, 
					tree[2 * si + 2].sum + 
					tree[2 * si + 1].suffixsum); 

		tree[si].maxsum = 
					max(tree[si].prefixsum, 
					max(tree[si].suffixsum, 
					max(tree[2 * si + 1].maxsum, 
					max(tree[2 * si + 2].maxsum, 
					tree[2 * si + 1].suffixsum + 
					tree[2 * si + 2].prefixsum)
                    )
                )
            ); 
	} 
} 

void update(int arr[], int si, int ss, int se, 
			int idx, int value) 
{   
    arr[si] = value;

	if (ss == se) { 
		tree[si].sum = value; 
		tree[si].prefixsum = value; 
		tree[si].suffixsum = value; 
		tree[si].maxsum = value; 
	} 
	else { 
		int mid = (ss + se) / 2; 

		if (idx <= mid) 
			update(arr, 2 * si + 1, ss, mid, idx, value); 
		
		else
			update(arr, 2 * si + 2, mid + 1, se, idx, value); 

		tree[si].sum = tree[2 * si + 1].sum + 
						tree[2 * si + 2].sum; 

		tree[si].prefixsum = 
					max(tree[2 * si + 1].prefixsum, 
					tree[2 * si + 1].sum + 
					tree[2 * si + 2].prefixsum); 

		tree[si].suffixsum = 
					max(tree[2 * si + 2].suffixsum, 
					tree[2 * si + 2].sum + 
					tree[2 * si + 1].suffixsum); 

		tree[si].maxsum = 
					max(tree[si].prefixsum, 
					max(tree[si].suffixsum, 
					max(tree[2 * si + 1].maxsum, 
					max(tree[2 * si + 2].maxsum, 
					tree[2 * si + 1].suffixsum + 
					tree[2 * si + 2].prefixsum)))); 
	} 
} 

node query(int arr[], int si, int ss, 
		int se, int qs, int qe) 
{ 
	node result; 
	result.sum = result.prefixsum = 
				result.suffixsum = 
				result.maxsum = INT_MIN; 

	if (qe < ss || se < qs) 
		return result; 

	if (qs <= ss && se <= qe) 
		return tree[si]; 

	int mid = (ss + se) / 2; 

	if (qs > mid) 
		return query(arr, 2 * si + 2, 
					mid + 1, se, qs, qe); 
		
	if (qe <= mid) 
		return query(arr, 2 * si + 1, 
					ss, mid, qs, qe); 

	node left = query(arr, 2 * si + 1, 
					ss, mid, qs, qe); 
	node right = query(arr, 2 * si + 2, 
						mid + 1, se, qs, qe); 

	result.sum = left.sum + right.sum; 
	result.prefixsum = max(left.prefixsum, left.sum + 
						right.prefixsum); 
							
	result.suffixsum = max(right.suffixsum, 
					right.sum + left.suffixsum); 
	result.maxsum = max(result.prefixsum, 
					max(result.suffixsum, 
					max(left.maxsum, 
					max(right.maxsum, 
					left.suffixsum + right.prefixsum)))); 
					
	return result; 
} 

int main() 
{   int n; cin >> n;
    for(int i=0 ; i<n ; i++) cin >> a[i];
	build(a, 0, n - 1, 0);
	int q; cin >> q;
	while(q--){
		int p,x,y;
		cin >> p >> x >> y;
		if(p==0)
			update(a,0,0,n-1,x-1,y);
		else cout << query(a,0,0,n-1,x-1,y-1).maxsum << endl;
	}
	return 0; 
} 
