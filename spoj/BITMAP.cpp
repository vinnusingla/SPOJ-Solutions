#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char a[182][182];
int ans[182][182];


int main(){
	int t,n,siz,m,num,u,v;
	pair<int,int>p;
	cin>>t;
	while(t--){
		queue < pair<int,int> >q;
		num=0;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			memset(ans[i],-1,sizeof(int)*m);
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]=='1'){
					q.push(pair<int,int>(i,j));
				}
			}
		}
		while(!q.empty()){
			siz=q.size();
			while(siz--){
				p=q.front();
				u=p.first;
				v=p.second;
				q.pop();
				ans[u][v]=num;
				if(u>0 && ans[u-1][v]==-1)q.push(pair<int,int>(u-1,v));
				if(u<n-1 && ans[u+1][v]==-1)q.push(pair<int,int>(u+1,v));
				if(v>0 && ans[u][v-1]==-1)q.push(pair<int,int>(u,v-1));
				if(v<m-1 && ans[u][v+1]==-1)q.push(pair<int,int>(u,v+1));
			}
			num++;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
