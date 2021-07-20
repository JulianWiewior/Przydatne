#include <bits/stdc++.h>
#define N 1001
using namespace std;

const long long INF = 1000000000000000000ll;
vector <pair<int,int>> graf[N];
vector <long long> odl(N, INF)
priority_queue <pair<long long, int>> Q;
int n,m;

int main() {
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		int a,b,c;
		cin>>a>>b>>c;
		
		graf[a].push_back({b,c});
		graf[b].push_back({a,c});
	}
	odl[1]=0;
	Q.push({0,1});
	while(!Q.empty){
		
		long long distance = Q.top().first * (-1);
		int v = Q.top().second ;
		Q.pop();
		if(distance > odl[v]) continue;
		for(int i=0; i<graf[v].size(); i++){
			int u=graf[v][i].first;
			long long krawedz = graf[v][i].second;
			if(odl[u] > odl[v] + krawedz){
				odl[u] = distance + krawedz;
				Q.push(make_pair(-odl[u], u))
			}
		}
		
		
		
		
		
		
		
	}










	return 0;
}
