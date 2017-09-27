#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int hist[100000];
long long int cal_area(long long int dig,long long int i,stack< int >& s){
    if(s.empty())return dig*(i);
    else{
        return dig*(i-s.top()-1);
    }
}
int main() {
	int n,top;
	long long int area,maxarea,dig;
	while(1){
	    cin>>n;
    	if(n==0)break;
    	maxarea=-1;
    	for(int i=0;i<n;i++)cin>>hist[i];
    	long long int i=0;
    	stack< int >s;
    	while(i<n){
    	    if(s.empty())s.push(i);
    	    else if(hist[s.top()]>hist[i]){
    	       while(!s.empty() && hist[s.top()]>hist[i]){
    	           dig=hist[s.top()];
    	           s.pop();
    	           area=cal_area(dig,i,s);
    	           maxarea=max(maxarea,area);
    	       } 
    	       s.push(i);
    	    }
    	    else s.push(i);
    	    i++;
    	}
    	while(!s.empty()){
           dig=hist[s.top()];
           s.pop();
           area=cal_area(dig,i,s);
           maxarea=max(maxarea,area);
        }
    	cout<<maxarea<<endl;
	}
	return 0;
}
