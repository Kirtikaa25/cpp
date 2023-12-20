int cutRod(vector<int> &price, int n) {
  // Write your code here.
  vector<int> prev(n+1,0);
  for(int i=0;i<=n;i++) prev[i]=i*price[0];
  for(int i=1;i<n;i++){
	  for(int j=1;j<=n;j++){
		  int ntake=prev[j];
		  int take=0;
		  if(i+1<=j) take=price[i]+prev[j-(i+1)];
		  prev[j]=max(ntake,take);
	  }
  }
  return prev[n];
}
