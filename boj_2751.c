#include <stdio.h>
#include <stdlib.h>

void merge(int ar[], int low, int mid, int high, int size){
  int i=low, j=mid+1, k=low;
  int *tmp;
  tmp=(int *)malloc(sizeof(int)*size);
  while(i<=mid&&j<=high){
    if(ar[i]<=ar[j]) tmp[k++]=ar[i++];
    else tmp[k++]=ar[j++];
  }
  while(i<=mid) tmp[k++]=ar[i++];
  while(j<=high) tmp[k++]=ar[j++];
  for(int q=low; q<=high; q++) ar[q]=tmp[q];
  free(tmp);
}

void mergeS(int ar[],int low, int high, int size){
  if(low<high){
    int mid=(low+high)/2;
    mergeS(ar,low,mid,size);
    mergeS(ar,mid+1,high,size);
    merge(ar,low,mid,high,size);
  }
}

int main(){
 int N;
 int *num;
 scanf("%d",&N);
 num=(int *)malloc(sizeof(int)*N);
 for(int i=0; i<N; i++){
   scanf("%d",&num[i]);
 }
 mergeS(num,0,N-1,N);
 for(int i=0; i<N; i++){
   printf("%d\n",num[i]);
 }
}
