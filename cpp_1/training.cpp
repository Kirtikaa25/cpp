int training(int n, vector<vector<int>> &points) {
   vector<vector<int>> dp(n,vector<int>(4,0));
   dp[0][0]=max(points[0][1],points[0][2]);
   dp[0][1]=max(points[0][2],points[0][0]);
   dp[0][2]=max(points[0][1],points[0][0]);
   dp[0][3]=max(points[0][1],max(points[0][0],points[0][2]));
   for(int day=1;day<n;day++){
     for(int last=0;last<4;last++){
       for(int task=0;task<3;task++){
         if(task!=last){
           dp[day][last]=max(dp[day][last],dp[day-1][task]+points[day][task]);
         }
       }
     }
   }
    return dp[n-1][3];
}


// recursive
int solve(int day,int last,vector<vector<int>> &points,vector<vector<int>>& dp){
  if(day==0){
    int maxi=0;
    for(int i=0;i<3;i++){
      if(i!=last){
        maxi=max(maxi,points[0][i]);
      }
    }
    return dp[0][last]=maxi;
  }
  if(dp[day][last]!=-1) return dp[day][last];
  int maxi=0;
  for(int i=0;i<3;i++){
    if(i!=last){
      int point=solve(day-1,i,points,dp)+points[day][i];
      maxi=max(maxi,point);
    }
  }
  return dp[day][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points) {
  vector<vector<int>> dp(n,vector<int>(4,-1));
  for(auto it:dp){
    for(auto it1:it){
      cout<<it1<<" ";
    }
    cout<<endl;
  }
  return solve(n-1,3,points,dp);

}
