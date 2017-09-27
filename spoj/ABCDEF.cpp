#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[101];

int main() {
	int o,s1,s2;
    long long int ans=0,n,num;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>v1,v2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                num=a[i]*a[j]+a[k];
                v1.push_back(num);
		    }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(a[i]==0)break;
                num=(a[j]+a[k])*a[i];
                v2.push_back(num);
            }
        }
    }
    s1=v1.size();
    s2=v2.size();
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(int i=0;i<s1;i++)cout<<v1[i]<<"	";
    cout<<endl;
    for(int i=0;i<s2;i++)cout<<v2[i]<<"	";
    cout<<endl;
    for(int i=0,j=0;i<s1 && j<s2;){
        if(v1[i]<v2[j])
		i++;
        else if(v1[i]>v2[j])
		j++;
        else{
            int n1=1,n2=1;
            while(i+1<s1 && v1[i]==v1[i+1]){
            	n1++;
            	i++;
			}
            while(j+1<s2 && v2[j]==v2[j+1]){
            	n2++;
            	j++;
			}
            ans=ans+n1*n2;
            i++;j++;
        }
    }
    cout<<ans;
	return 0;
}

