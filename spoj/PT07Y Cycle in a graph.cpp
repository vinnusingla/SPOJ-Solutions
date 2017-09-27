#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
	public:
	int val;
	vector< int >child;
	int parent;
	bool rec;
	bool vis;
	node(int v=0){
	    val=v;
	    parent=0;
	    rec=0;
	    vis=0;
	}
};

class Graph{
	public:
	vector<node> graph;
	int vertices;
	int edges;
	Graph(int v){
		edges=0;
		vertices=v;
		for(int i=0;i<=v;i++)graph.push_back(node(i));
	}
	void add_edge(int u,int v){
		int m=graph.size();
		graph[u].child.push_back(v);
	    edges++;
	    graph[v].child.push_back(u);
	    //cout<<"ok";
	}
	bool is_cyclic(){
		//cout<<"hi";
		int curr,siz,m;
		stack<int> dfs;
		dfs.push(1);
		graph[1].parent=-1;
		graph[1].rec=1;
		while(!dfs.empty()){
		    curr=dfs.top();
			if(graph[curr].vis){
		    	dfs.pop();
		    	graph[curr].rec=0;
			}
		    else{
			    siz=graph[curr].child.size();
				graph[curr].vis=1;
				for(int i=0;i<siz;i++){
					m=graph[graph[curr].child[i]].val;
			        if(graph[graph[curr].child[i]].parent==0){
			        	graph[graph[curr].child[i]].parent=curr;
			            dfs.push(graph[graph[curr].child[i]].val);
			        	graph[graph[curr].child[i]].rec=1;
			        }
					else if(graph[graph[curr].child[i]].val!=graph[curr].parent ){
			        	return 1;
					}
			    }
			}
		}
		return 0;
	}
	
	
};

int main(){
	int n,m,u,v,curr,siz,ans;
	cin>>n>>m;
	Graph graph(n);
	for(int i=0;i<m;i++){
	    cin>>u>>v;
		graph.add_edge(u,v);
	}
	if(graph.is_cyclic())cout<<"YES";
	else cout<<"NO";
	return 0;
}
