#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[26];
int p[100005];
int main() {
	string s;
	int n,t,siz;
	cin>>t;
    while(t--){
    	memset(a,-1,sizeof(int)*26);
        cin>>s;
        siz=s.size();
        p[0]=1;
        for(int i=1;i<=siz;i++){
        	n=s[i-1]-65;
        	if(a[n]==-1){
        		a[n]=i;
        		p[i]=(2*p[i-1])%(1000000007);
			}
			else{
				p[i]=(2*p[i-1]-p[a[n]-1])%(1000000007);
				a[n]=i;
			}
			if(p[i]<0)p[i]+=+1000000007;
		}
		cout<<p[siz]<<endl;
    }
	return 0;
}
