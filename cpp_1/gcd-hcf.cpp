#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,m;
 cin>>n>>m;
 while(n>0 && m>0){
  if(n>m) n=n%m;
  else m=m%n;
}
if(n==0) cout<<m<<endl;
else cout<<n<<endl;
}
