#include<bits/stdc++.h>
void print(string s,vector<string>& sub){
    int n=s.length();
    int m=1<<n;
    for(int num=0;num<m;num++){
        string s2;
        for(int i=0;i<n;i++){
            if(num &(1<<i)){
              s2+=s[i];
            }
            sub.push_back(s2);
        }
    }
}
int main(){
    string s;
    cin>>s;
    vector<string> sub;
    print(s,sub);
    for(auto it:sub){
        cout<<it<<endl;
    }
}
