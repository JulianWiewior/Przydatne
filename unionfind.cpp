#include<bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000ll;
#define N 1000

int n, parent[N], ranga[N];

void init() {
	rep(i, 1, n) parent[i] = i;
}

int find(int v) {
	if(v == parent[v]) 
		return v;
	return parent[v] = find(parent[v]);
}

void union(int v, int u) {
	int a = find(v), b = find(u);
	if(a != b) {
		if(ranga[a] > ranga[b])
			swap(a,b);
		parent[a] = b;
		if(ranga[a] == ranga[b])
			ranga[b]++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	init();
	return 0;
}
