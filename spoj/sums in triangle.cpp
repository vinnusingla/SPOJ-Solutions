#include<iostream>
#include<algorithm>
using namespace std;int a[101][101],t,n,i,j;int main(){cin>>t;while(t--){cin>>n;for(i=0;i<n;i++)for(j=0;j<=i;j++)cin>>a[i][j];for(i=n-2;i>=0;i--)for(j=0;j<=i;j++)a[i][j]+=max(a[i+1][j],a[i+1][j+1]);cout<<**a<<endl;}}
