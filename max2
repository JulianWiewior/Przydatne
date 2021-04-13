#include <bits/stdc++.h>
using namespace std;
#define N 1003
#define ntree 1048567
int tree[ntree*2];

void update2(int pos, int val){
	pos+=ntree;
	while(pos){
		tree[pos] = max(tree[pos], val);
		pos/=2;
	}
}

int query2(int l, int r){
	l+=ntree;
	r+=ntree;
	if(l==r)
		return tree[l];
		
	int ans=max(tree[l], tree[r]);
	
	while(r-l>1){
		if(l%2==0)
			ans=max(ans, tree[l+1]);
		if(r%2==1)
			ans=max(ans, tree[r-1]);
		l/=2;
		r/=2;
	}
	return ans;
}


int main() {
	return 0;
}
