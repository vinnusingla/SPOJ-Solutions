#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[201][201];
string s;
int pos(int i,int j){
    int rec=0;
    for(int k=i;k<=j;k++){
        if(s[k]=='1')rec++;
        else rec--;
    }
    if(rec>0)return 1;
    else return 0;
}
 
int main() {
	int t,n,max,p,l,m;
	cin>>t;
	while(t--){
	    cin>>n;
	    cin>>s;
	    for(int j=0;j<n;j++){
	        if(s[j]=='1')a[j][j]=1;
	        else a[j][j]=0;
	    }
	    for(int i=1;i<n;i++){
	        for(int j=0;j+i<n;j++){
	        	l=j,m=j+i;
	        	p=pos(l,m);
	            if(p){
	                a[l][m]=m-l+1;
	            }
	            else{
	            	max=-1;
	                for(int k=j;k<j+i;k++){
	                //	cout<<a[i][k]<<" "<<a[k+1][j];
	                    if(a[l][k]+a[k+1][m]>max)max=a[l][k]+a[k+1][m];
	                }
	                a[l][m]=max;
	            }
	        }
	    }
	    cout<<a[0][n-1]<<endl;
	}
	return 0;
}

