#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
int dp[100001][2];
int go(int curr,int parent,int is_parent_covered){
	if (dp[curr][is_parent_covered]!=-1)return dp[curr][is_parent_covered];
	int& ret=dp[curr][is_parent_covered];
    int siz=graph[curr].size(),u,v;
    if(is_parent_covered){
        int u=0,v=1;
        for(int i=0;i<siz;i++)
			if(graph[curr][i]!=parent)
				u+=go(graph[curr][i],curr,0);
        for(int i=0;i<siz;i++)
			if(graph[curr][i]!=parent)
				v+=go(graph[curr][i],curr,1);
        ret=min(u,v);
    }
    else{
        int v=1;
        for(int i=0;i<siz;i++)
			if(graph[curr][i]!=parent)
				v+=go(graph[curr][i],curr,1);
        ret=v;
    }
    return ret;
}

int main(){
	int n,m,u,v,ans,siz;
	cin>>n;
	m=n-1;
	for(int i=0;i<m;i++){
	    cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	u=0,v=1;
	memset(dp,-1,sizeof(dp));
	siz=graph[1].size();
	for(int i=0;i<siz;i++)u+=go(graph[1][i],1,0);
    for(int i=0;i<siz;i++)v+=go(graph[1][i],1,1);
    cout<<min(u,v);
	return 0;
}

