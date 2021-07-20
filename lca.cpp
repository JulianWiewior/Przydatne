#include <bits/stdc++.h>
#define N 1001
#define log 18
using namespace std;

vector<int> graf[N];
int preorder[N], postorder[N], ldx, lca[log][N], n;

void dfs(int v, int p){
	lca[0][v]=p;
	preorder[v]= ++ldx;
	for(auto u: graf[v]){
		if(u != p)
			dfs(u, p);
	}
	postorder[v]= ++ldx;
}

bool czy_przodek( int v, int u){
	if(v==u)
		return true;
	if(preorder[v] < preorder[u] && postorder[v]>postorder[u])
		return true;
	return false;
}

int get_lca(int v, int u){
	if(czy_przodek(v,u)) return v;
	if(czy_przodek(u,v)) return u;
	for(int i = log -1; i>=0; i--){
		if(!czy_przodek(lca[i][v], u))
			v= lca[i][v];
	}
	return lca[0][v];
	
}

int main() {
	
	cin>>n;
	for(int i=1; i<n; i++){
		int v,u;
		cin>>v>>u;
		graf[v].push_back(u);
		graf[u].push_back(v);
	}
	dfs(1,1);
	for(int i=1; i<log; i++){
		for(int v=1; v <=n; v++){
			lca[i][v] = lca[i-1][lca[i-1][v]];
		}
	}
	return 0;
}
