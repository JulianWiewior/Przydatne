#include <bits/stdc++.h>
using namespace std;
#define NTREE 1048576
long long tree[NTREE*2], long long lazy[NTREE*2];

void update(int v, int start, int end, int l, int r, int val){
	if(lazy[v]!=0){
		tree[v] += (end-start+1) * lazy[v];
		if(start!=end){
			lazy[v*2]+=lazy[v];
			lazy[v*2+1]+=lazy[v];
		}
		lazy[v]=0;
	}
	
	if(start>r ||end<l || start>end)
		return;
		
	if(start>=l && end<=r){
		tree[v]+= (end - start +1)*val;
		if(start!=end){
			lazy[v * 2] += value; 
			lazy[2 * v + 1] += value; 
		}
		return
	}
	
	int mid = (start+end)/2;
	update(v*2, start, mid, l, r, val);
	update(v*2+1, mid+1, end, l, r, val);
	tree[v]=tree[v*2]+tree[v*2+1];
	
}




long long query(int v, int start, int end, int l, int r){
	if(start > r || end < l || start > end) 
		return 0;
	
	if(lazy[v] != 0) {
		tree[v] += (end - start + 1) * lazy[v];
		if(start != end) {
			lazy[2 * v] += lazy[v];
			lazy[2 * v + 1] += lazy[v];
		}
		lazy[v] = 0;
	}
	
	if(start >= l && end <= r)
		return tree[v];
	
	int mid = (start + end) / 2;
	long long q1 = query(2 * v, start, mid, l, r);
	long long q2 = query(2 * v + 1, mid + 1, end, l, r);
	return q1 + q2;
}

int main() {
	return 0;
}
