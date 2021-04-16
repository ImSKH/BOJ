#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV 8001

void merge(int ar[], int low, int mid, int high, int size){
  int i=low, j=mid+1, k=low;
  int *tmp=(int *)malloc(sizeof(int)*size);
  while(i<=mid&&j<=high){
    if(ar[i]<=ar[j]) tmp[k++]=ar[i++];
    else tmp[k++]=ar[j++];
  }
  while(i<=mid) tmp[k++]=ar[i++];
  while(j<=high) tmp[k++]=ar[j++];
  for(int a=low; a<=high; a++) ar[a]=tmp[a];
  free(tmp);
}

void mergeS(int ar[], int low, int high, int size){
  if(low<high){
    int mid=(low+high)/2;
    mergeS(ar,low,mid,size);
    mergeS(ar,mid+1,high,size);
    merge(ar,low,mid,high,size);
  }
}

double numavg(int ar[],int size){
  double re=0;
  for(int i=0; i<size; i++){
    re+=ar[i];
  }
  re = round(re/size);
  if(re==-0) re = 0;
  return re;
}

int midavg(int ar[], int size){
  return ar[(size/2)];
} 

int mstfv(int ar[], int size){
  int cnt[MAXV]={0,};
  int ncnt[MAXV]={0,};
  int n=0, k=0, re=0;
  for(int i=0; i<size; i++){
    ar[i]=ar[i]+4000;
  }
  for(int i=0; i<size; i++){
    cnt[ar[i]]++;
  }
  for(int i=0; i<MAXV; i++){
    if(cnt[i]>k) k=cnt[i];
  }
  for(int i=0; i<MAXV; i++){
    if(cnt[i]==k){
      ncnt[n++]=i;
    }
  }
  if(n>1) re=ncnt[1];
  else re=ncnt[0];
  return re-=4000;
}

int range(int ar[], int size){
  return ar[size-1]-ar[0];
}


int main(){
  int N;
  int *num;
  scanf("%d",&N);
  num=(int *)malloc(sizeof(int)*N);
  for(int i=0; i<N; i++) scanf("%d",&num[i]);
  mergeS(num,0,N-1,N);
  printf("%0.f\n",numavg(num,N));  
  printf("%d\n",midavg(num,N));  
  printf("%d\n",mstfv(num,N));  
  printf("%d\n",range(num,N));
}
