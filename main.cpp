#include <bits/stdc++.h>
using namespace std;
vector <int> graf[1000];
int vst[1000];

void dfs(int v){
	vst[v]=1;
	for(auto s:graf[v]){
		if(vst[s]==0){
			dfs(s);
		}
	}
}

int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	return 0;
}
