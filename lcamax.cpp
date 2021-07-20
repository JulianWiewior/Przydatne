#include <bits/stdc++.h>
#define N 1001
#define log 18
using namespace std;

vector<pair<int, int>> graf[N];
int preorder[N], postorder[N], ldx, lca[log][N], lca2[log][N], n;

void dfs(int v, int p, int w){
	lca[0][v]=p;
	lca2[0][v]=w;
	preorder[v]= ++ldx;
	for(auto u: graf[v]){
		if(u.first != p)
			dfs(u.first, v, u.second);
	}
	postorder[v]= ++ldx;
}

bool przodek( int v, int u){
	if(v==u)
		return true;
	if(preorder[v] < preorder[u] && postorder[v]>postorder[u])
		return true;
	return false;
}

int lca_max(int v, int u){
	int ans=0;
	if(przodek(v,u)){
		for(int i=log - 1; i>=0; i--){
			if(!przodek(lca[i][u], v)){
				ans=max(ans, lca2[i][u]);
				u=lca[i][u];
			}
		}
		ans=max(ans, lca2[0][u]);
		return ans;
	}
	
	if(przodek(u,v)){
		for(int i=log-1; i>=0; i--){
			if(!przodek(lca[i][v], u)){
				ans=max(ans, lca2[i][v]);
				v=lca[i][v];
			}
		}
		ans=max(ans, lca2[0][v]);
		return ans;
	}
	
	for(int i=log - 1; i>=0; i--) 
		if (!przodek(lca[i][v], u)) {
			ans = max(ans, lca2[i][v]);
			v = lca[i][v];
	}
	for(int i= log - 1; i>= 0; i--)
		 if (!przodek(lca[i][u], v)) {
			ans = max(ans, lca2[i][u]);
			u = lca[i][u];
	}
	return ans;
}

int main() {
	
	cin>>n;
	for(int i=1; i<n; i++){
		int v,u, c;
		cin>>v>>u>>c;
		graf[v].push_back({u,c});
		graf[u].push_back({v,c});
	}
	dfs(1,1,0);
	for(int i=1; i<log; i++){
		for(int v=1; v <=n; v++){
			lca[i][v] = lca[i-1][lca[i-1][v]];
		}
	}
	for(int i=1; i<log; i++){
		for(int v=1; v <=n; v++){
			lca2[i][v]=max(lca2[i-1][v], lca2[i-1][lca[i-1][v]]);
		}
	}
	return 0;
}
