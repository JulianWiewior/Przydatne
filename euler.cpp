#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define N 105
int n,m;

list <pair<int , int>> graf[N];
struct kraw{	
	list<pair<int,int>>::iterator it1, it2;
	int a,b;
} krawedzie[N];

vector<int> cykl;

void wej(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		graf[a].push_front({b,i});
		graf[b].push_front({a,i});
		krawedzie[i].a=a;
		krawedzie[i].b=b;
		krawedzie[i].it1=graf[a].begin();
		krawedzie[i].it2=graf[b].begin();
	
	}
}

bool parzyste(){
	for(int i=1; i<=n; i++)
		if(graf[i].size()%2==1)
			return false;
		
	return true;
}


void odetnij(int nr){
	graf[krawedzie[nr].a].erase(krawedzie[nr].it1);
	graf[krawedzie[nr].b].erase(krawedzie[nr].it2);	
}



void dfs(int v){

	while(graf[v].size()){
		auto it = graf[v].begin();
		int u=(*it).first, nr=(*it).second;
		odetnij(nr);
		dfs(u);
	}
	cykl.pb(v);
	
}




int main() {
	wej();
	if(!parzyste()){
		cout<<"graf nie ma cyklu Eulera\n";
		return 0;
	}
	dfs(1);
	for(auto s:cykl){
		cout<<s<<' ';
	}
	return 0;
}
