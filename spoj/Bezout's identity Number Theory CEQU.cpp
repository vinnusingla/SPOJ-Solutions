#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd (int m,int n){
    if(n==0)return m;
    else{
        return gcd(n,m%n);
    }
}

int a[31];
int main() {
	int t,a,b,c,g,counter=1;
	cin>>t;
	while(t--){
	    cin>>a>>b>>c;
	    a=abs(a);
	    b=abs(b);
	    c=abs(c);
	    g=gcd(a,b);
	    if(c%g==0)cout<<"Case "<<counter++<<": Yes"<<endl;
	    else cout<<"Case "<<counter++<<": No"<<endl;
	}
	return 0;
}

