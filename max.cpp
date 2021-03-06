#include <bits/stdc++.h>
using namespace std;
#define N 1003
#define ntree 1048567
int tree[ntree*2];

void update(int l, int r, int val){
	l+=ntree;
	r+=ntree;
	if(l>r)
		return;
		
	tree[l]=max(tree[l],val);
	tree[r]=max(tree[r],val);
	
	while(r-l>1){
		if(l%2==0)
			tree[l+1] = max(tree[l+1], val);
		if(r%2==1)
			tree[r-1] = max(tree[r-1], val);
		l/=2;
		r/=2;
	}	
}

int query(int pos){
	
	pos+=ntree;
	int ans=0;
	while(pos){ 
		ans = max(ans, tree[pos]);
		pos /=2;
	}
	return ans;
	
	
}

int main() {
	return 0;
}
