#include <stdio.h>
#include <stdlib.h>

void merge(int ar[], int low, int mid, int high, int size){
  int i=low, j=mid+1, k=low;
  int *tmp=malloc(sizeof(int)*size);
  while(i<=mid&&j<=high){
    if(ar[i]<=ar[j]) tmp[k++]=ar[i++];
    else tmp[k++]=ar[j++];
  }
  while(i<=mid) tmp[k++]=ar[i++];
  while(j<=high) tmp[k++]=ar[j++];
  for(int a=low; a<=high; a++) ar[a]=tmp[a];
}

void mergeS(int ar[], int low, int high, int size){
  if(low<high){
    int mid=(low+high)/2;
    mergeS(ar,low,mid,size);
    mergeS(ar,mid+1,high,size);
    merge(ar,low,mid,high,size);
  }
}

int binSear(int ar[],int size, int trg){
  int low=0, mid;
  int high=size-1;
  while(low<=high){
    mid=(low+high)/2;
    if(trg==ar[mid]) return mid;
    else{
      if(trg>ar[mid]) low=mid+1;
      else high=mid-1;
    }
  }
  return -1;
}

int main(){
  int N;
  int *A,*NGE;
  scanf("%d",&N);
  A=(int*)malloc(sizeof(int)*N);
  NGE=(int*)malloc(sizeof(int)*N);
  for(int i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  for(int i=0; i<N; i++){
    mergeS(A,i,N-1,N);
    
  }
}
