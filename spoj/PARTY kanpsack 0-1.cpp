#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int array[501][101];
int bag_array[501][101];

pair<int,int> knapsack(vector< pair<int,int> >v,int b,int n){
	for(int i=0;i<b;i++){
		array[i][0]=0;
		bag_array[i][0]=0;
	}
	for(int i=0;i<n;i++){
		array[0][i]=0;
		bag_array[0][i]=0;
	}
	for(int i=1;i<=b;i++){
		for(int j=1;j<=n;j++){
			int c1,c2;
			c1=array[i][j-1];
			if(i-v[j].first>=0)c2=array[i-v[j].first][j-1]+v[j].second;
			else c2=0;
			if(c2>c1){
				array[i][j]=c2;
				bag_array[i][j]=bag_array[i-v[j].first][j-1]+v[j].first;
			}
			else if(c2==c1){
				array[i][j]=c1;
				bag_array[i][j]=min(bag_array[i-v[j].first][j-1]+v[j].first,bag_array[i][j-1]);
			}
			else{
				array[i][j]=c1;
				bag_array[i][j]=bag_array[i][j-1];
			}
		}
	}
	pair<int ,int>ans;
	ans.first=bag_array[b][n];
	ans.second=array[b][n];
	return ans;
}



int main(){
	int u,v,b,n;
	pair<int,int>p,ans;
	while(1){
		vector< pair<int,int> >q;
		q.push_back(p);
		cin>>b>>n;
		if(b==0 && n==0)break;
		for(int i=0;i<n;i++){
			cin>>p.first>>p.second;
			q.push_back(p);
		}
		ans=knapsack(q,b,n);
		cout<<ans.first<<" "<<ans.second<<endl;
	}
}
