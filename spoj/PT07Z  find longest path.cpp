#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int num;
class node{
	public:
	int val;
	vector< int >child;
	bool vis;
	int height;
	node(int v=0){
	    val=v;
	    vis=0;
	    height=0;
	}
};

class Graph{
	vector<node> graph;
	int vertices;
	int edges;
	public:
	Graph(int v){
		edges=0;
		vertices=v;
		for(int i=0;i<=v;i++)graph.push_back(node(i));
	}
	void reset_graph(){
		for(int i=1;i<=vertices;i++){
			graph[i].vis=0;
			//graph[i].height=0;
		}
	}
	void add_edge(int u,int v){
		int m=graph.size();
		graph[u].child.push_back(v);
	    edges++;
	    graph[v].child.push_back(u);
	    //cout<<"ok";
	}
	int bfs_last_node(int curr){
		int siz;
		queue<int> bfs;
		bfs.push(curr);
		graph[curr].height=0;
		while(!bfs.empty()){
		    curr=bfs.front();
		    graph[curr].vis=1;
		    bfs.pop();
		    siz=graph[curr].child.size();
			//cout<<"curr siz == "<<curr<<"	"<<siz<<endl;
			for(int i=0;i<siz;i++){
				if(!(graph[graph[curr].child[i]].vis)){
					bfs.push(graph[graph[curr].child[i]].val);
					graph[graph[curr].child[i]].height=graph[curr].height+1;
				}
				//cout<<graph[graph[curr].child[i]].val<<"	";
			}
			//cout<<endl;
		}
		return curr;
	}
	int get_height(int n){
		return graph[n].height;
	}
	
};

int main(){
	int n,m,u,v,curr,siz,ans;
	cin>>n;
	m=n-1;
	Graph graph(n);
	for(int i=0;i<m;i++){
	    cin>>u>>v;
		graph.add_edge(u,v);
	}
	int border_node1=graph.bfs_last_node(1);
	graph.reset_graph();
	int border_node2=graph.bfs_last_node(border_node1);
	//cout<<border_node1<<"	"<<border_node2<<endl;
	cout<<graph.get_height(border_node2);
	return 0;
}
