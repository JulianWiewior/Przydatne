#include <bits/stdc++.h>
using namespace std;

int vst[1000];
vector <int> graf[1000];

int main() {
	
	int n,m;
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	queue <int> Q;
	Q.push(1);
	while(!Q.empty()){
		int v=Q.front();
		Q.pop();
		for(auto s: graf[v]){
			if(vst[s]==0){
				vst[s]==1;
				Q.push(s);
			}
		}
	}
	return 0;
}
