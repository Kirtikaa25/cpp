#include <bits/stdc++.h>
int func(int low,int high,vector<int>& arr){
    int i=low;
    int j=high;
    while(i<j){
        while(i<high && arr[low]>=arr[i]){
          i++;
        }
        while(j>low && arr[low]<arr[j]){
          j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(int low,int high,vector<int>& arr){
    if(low<high){
        int pI=func(low,high,arr);
        qs(low,pI-1,arr);
        qs(pI+1,high,arr);
    }
}
vector<int> quickSort(vector<int> arr)

{
    int low=0;
    int high=arr.size()-1;
    qs(low,high,arr);
    return arr;
}

