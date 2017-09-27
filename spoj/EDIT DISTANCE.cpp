#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int ans[2001][2001];                               //STORING PROBLEM SOLS.

int main() {
	int t,sa,sb,d;
	string a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;                                 //INPUTTING 2 STRINGS
		sa=a.size();
		sb=b.size();
		for(int i=0;i<=max(sa,sb);i++){
			ans[0][i]=i;
			ans[i][0]=i;
		}
		for(int i=1;i<=sa;i++){                                             //THE PROBLEM HAS DP SOLT.
			for(int j=1;j<=sb;j++){                                         //IT MAY COME FROM INS , DEL , CONV. OR NOTHING(D==0)
				d=1;
				ans[i][j]=min( ans[i][j-1]+1, ans[i-1][j]+1) ;
				if(a[i-1]==b[j-1]) d=0;
				ans[i][j]=min(ans[i-1][j-1]+d , ans[i][j]);
				//cout<<i<<" "<<j<<" "<<ans[i][j]<<endl;
			}
		}
		cout<<ans[sa][sb]<<endl;                                            //PRINTING ANS
	}
	return 0;
}
