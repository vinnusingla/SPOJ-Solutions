#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,c;
int array[100000];

bool func(int m,int siz){
	int lpos=array[0];
	int cows=1;
	int i=1;
	while(i<siz){
		if(array[i]-lpos>=m){
			lpos=array[i];
			cows++;
			if(cows==c)return 1;
		}
		i++;
	}
	return 0;
}

int bs(int siz){
	int f=0;
	int l=array[siz-1];
	int m=(f+l)/2;
	while(m!=f){
		if(func(m,siz)==1){
			f=m;
		}
		else{
			l=m;
		}
		m=(l+f)/2;
	}
	return m;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>c;
		for(int i=0;i<n;i++)cin>>array[i];
		sort(array,array+n);
		cout<<bs(n)<<endl;
	}
}
