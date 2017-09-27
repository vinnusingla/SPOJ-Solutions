//This code finds all the prime number less than n
// # Sieve of Eratosthenes
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int pno[1000000];
int prime_no_sieve(int n){
	int j;
	memset(pno,0,sizeof(pno));
	for(int i=2;i<n;i++){
		if(pno[i]==0){
			cout<<i<<" ";
			j=i;
			for(int k=1;j<n;k++){
				if(pno[j]==0)pno[j]=1;
				j=j+i;
			}
		}
	}
}

int main(){
	int a;
	cin>>a;
	prime_no_sieve(a);
	//cout<<pno[99929];
	return 0;
}

