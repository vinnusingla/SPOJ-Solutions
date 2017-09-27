#include <iostream>
#include <bits/stdc++.h>
using namespace std;
pair< int ,int >f_a(int x=0,int y=0,int c=0){					//full adder
	int a=x+y+c;
	pair<int ,int >ans;
	ans.first=a%10;          									//sum
	ans.second=a/10;         									//carry
	return ans;
}

class big_no{                                                 //class allows big digit operation
	public:													  //addition,multiplication,regetting big  no as a string,
	vector<int>num;
	big_no(string s=""){									//initializing big no with string 
		int siz=s.size();									//big no. is stored in vector num in reverse manner
		for(int i=siz-1;i>-1;i--){
			num.push_back(s[i]-'0');
		}
	}
	big_no(int a){											//initializing big no with integer
		string s;stringstream ss;
		ss<<a;
		ss>>s;
		int siz=s.size();
		for(int i=siz-1;i>-1;i--){
			num.push_back(s[i]-'0');
		}
	}
	big_no s_d_multiply(int b){    				         //multiplying single digit
		big_no c;
		int siz=num.size();
		pair<int , int>holder;
		holder.second=0;
		for(int i=0;i<siz;i++){
			holder=f_a(b*num[i],holder.second);
			c.num.push_back(holder.first);
		}
		if(holder.second!=0)c.num.push_back(holder.second);
		return c;
	}
	big_no operator+(big_no b){							//addition of two big number
		pair<int , int>holder;
		big_no c;
		int siz=min(num.size(),b.num.size()),nsiz;
		holder.second=0;
		for(int i=0;i<siz;i++){
			holder=f_a(num[i],b.num[i],holder.second);
			c.num.push_back(holder.first);
		}
		if(siz==num.size()){
			nsiz=b.num.size();
			for(int i=siz;i<nsiz;i++){
				holder=f_a(b.num[i],holder.second);
				c.num.push_back(holder.first);
			}
		}
		else{
			nsiz=num.size();
			for(int i=siz;i<nsiz;i++){
				holder=f_a(num[i],holder.second);
				c.num.push_back(holder.first);
			}
		}
		if(holder.second!=0)c.num.push_back(holder.second);
		return c;
	}
	big_no operator*(big_no b){									//multiplication of two big number
		int siz=b.num.size(),dsiz,nsiz,swap;
		big_no temp[siz];
		big_no c;
		for(int i=0;i<siz;i++){
			temp[i]=(*this).s_d_multiply(b.num[i]);
			dsiz=temp[i].num.size();
			for(int j=0;j<i;j++)temp[i].num.push_back(0);
			for(int j=dsiz-1;j>-1;j--){
				temp[i].num[j+i]=temp[i].num[j];
			}
			for(int j=0;j<i;j++)temp[i].num[j]=0;
			c=c+temp[i];
		}
		return c;
	}
	string get_string(){ 								//returns big number as string
		string ans="",t;
		stringstream s;
		int siz=num.size();
		for(int i=siz-1;i>-1;i--){
			s<<num[i];
			s>>t;
			s.clear();
			ans=ans+t;
		}
		return ans;
	}
};
int fact[16];
big_no facs[101];
int main(){
	fact[0]=1;
	for(int i=1;i<11;i++){
		fact[i]=fact[i-1]*i;
	}
	facs[10]=big_no(fact[10]);
	for(int i=11;i<101;i++){
		big_no temp(i);
		facs[i]=facs[i-1]*temp;
	}
    int t,n;
    cin>>t;
    while(t--){
    	cin>>n; 
    	if(n<11)cout<<fact[n]<<endl;
    	else{
    		cout<<facs[n].get_string()<<endl;
		}
	}
    return 0;
}
