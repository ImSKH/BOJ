#include <stdio.h>
#include <stdlib.h>

void merge(int ar[], int low, int mid, int high, int size){
  int i=low, j=mid+1, k=low;
  int *tmp = (int*)malloc(sizeof(int)*size);
  while(i<=mid&&j<=high){
    if(ar[i]<=ar[j]) tmp[k++]=ar[i++];
    else tmp[k++]=ar[j++];
  }
  while(i<=mid) tmp[k++]=ar[i++];
  while(j<=high) tmp[k++]=ar[j++];
  for(int h=low; h<=high; h++) ar[h]=tmp[h];
  free(tmp);
}

void mergeSort(int ar[], int low, int high, int size){
  if(low<high){
    int mid=(low+high)/2;
    mergeSort(ar,low,mid,size);
    mergeSort(ar,mid+1,high,size);
    merge(ar, low, mid, high, size);
  }
}

int binSear(int ar[],int size, int trg){
  int low=0;
  int high=size-1;
  int mid;

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
  int n_A, n_B;
  int *A, *B, *C;
  int cnt=0,id;
  scanf("%d %d",&n_A,&n_B);
  A = (int *)malloc(sizeof(int)*n_A);
  B = (int *)malloc(sizeof(int)*n_B);
  C = (int *)malloc(sizeof(int)*n_A);
  for(int i=0; i<n_A; i++){
    scanf("%d",&A[i]);
  }
  for(int i=0; i<n_B; i++){
    scanf("%d",&B[i]);
  }
  mergeSort(A,0,n_A-1,n_A);
  mergeSort(B,0,n_B-1,n_B);
  
  for(int i=0; i<n_A; i++){
    id = binSear(B,n_B,A[i]);
    if(id==-1){
      C[cnt]=A[i];
      cnt++;
    }
  }
  printf("%d\n",cnt);
  for(int i=0; i<cnt; i++){
    printf("%d ",C[i]);
  }
}
