#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int a[50001];

class node{
	public:
	long long int sum;
	long long int bsum;
	long long int lsum;
	long long int rsum;
	node(long long int s=0,long long int b=0,long long int l=0,long long int r=0){
		sum=s;
		bsum=b;
		lsum=l;
		rsum=r;
	}
};
node tree[200004];
node combine(node l,node r ){
	node t;
	t.sum=l.sum+r.sum;
	t.lsum=max(l.lsum,l.sum+r.lsum);
	t.rsum=max(r.rsum,r.sum+l.rsum);
	t.bsum=max(l.bsum,max(r.bsum,l.rsum+r.lsum));
	return t;
}
node make_tree(int start,int end,int index){
	if(start==end){
		tree[index]=node(a[start],a[start],a[start],a[start]);
	}
	else{
		node l,r;
		int mid=(start+end)/2;
		l=make_tree(start,mid,index<<1);
		r=make_tree(mid+1,end,(index<<1)+1);
		tree[index]=combine(l,r);
	}
	return tree[index];
}
node ans(int index,int start,int end,int a,int b){
	if(start>=a && end<=b)
		return tree[index];
	else if(end<a || start>b)
		return node(0,-1000000,-1000000,-1000000);
	else{	
		node l,r;
		int mid=(start+end)/2;
		l=ans(index<<1,start,mid,a,b);
		r=ans((index<<1)+1,mid+1,end,a,b);
		return combine(l,r);
	}
}
void modify(int index,int start,int end,long long int x,long long int y){
	while(start != end){
		int mid=(start+end)/2;
		if(x>mid){
			start=mid+1;
			index=(index<<1)+1;
		}
		else{
			end=mid;
			index=(index<<1);
		}
	}
	tree[index]=node(y,y,y,y);
	int parent=index;
	while(parent!=1){
		parent=(parent)>>1;
		tree[parent]=combine(tree[parent<<1],tree[(parent<<1)+1]);
	}
	return ;	
}
int main(){
	long long int n,x,y,m,o;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	make_tree(1,n,1);
	//for(int i=1;i<=7;i++)cout<<tree[i].sum<<"	";
	cin>>m;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&o,&x);
		cin>>y;
		if(o==1)printf("%lld\n",(ans(1,1,n,x,y).bsum));
		else modify(1,1,n,x,y);
	}
	return 0;
}
