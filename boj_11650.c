#include <stdio.h>
#include <stdlib.h>


typedef struct _XY{
  int x;
  int y;
} loc;

void merge_x(loc xy[],int low, int mid, int high, int size){
  int i=low, j=mid+1, k=low;
  loc *tmp;
  tmp=(loc *)malloc(sizeof(loc)*size);
  while(i<=mid&&j<=high){
    if(xy[i].x<=xy[j].x) tmp[k++]=xy[i++];
    else tmp[k++]=xy[j++];
  }
  while(i<=mid) tmp[k++]=xy[i++];
  while(j<=high) tmp[k++]=xy[j++];
  for(int a=low; a<=high; a++) xy[a]=tmp[a];
  free(tmp);
}

void merge_y(loc xy[],int low, int mid, int high, int size){
  int i=low, j=mid+1, k=low;
  loc *tmp;
  tmp=(loc *)malloc(sizeof(loc)*size);
  while(i<=mid&&j<=high){
    if(xy[i].y<=xy[j].y) tmp[k++]=xy[i++];
    else tmp[k++]=xy[j++];
  }
  while(i<=mid) tmp[k++]=xy[i++];
  while(j<=high) tmp[k++]=xy[j++];
  for(int a=low; a<=high; a++) xy[a]=tmp[a];
  free(tmp);
}

void mergeS_x(loc xy[], int low, int high, int size){
  int mid;
  if(low<high){
    mid=(low+high)/2;
    mergeS_x(xy,low,mid,size);
    mergeS_x(xy,mid+1,high,size);
    merge_x(xy,low,mid,high,size);
  }
}

void mergeS_y(loc xy[], int low, int high, int size){
  int mid;
  if(low<high){
    mid=(low+high)/2;
    mergeS_y(xy,low,mid,size);
    mergeS_y(xy,mid+1,high,size);
    merge_y(xy,low,mid,high,size);
  }
}

int main(){
  int N,cnt=0;
  int low=0, high=1;
  loc *xy;
  scanf("%d",&N);
  xy = (loc *)malloc(sizeof(loc)*N);
  for(int i=0; i<N; i++) scanf("%d %d", &xy[i].x, &xy[i].y);
  mergeS_x(xy,0,N-1,N);
  while(high<N){
    while(xy[low].x==xy[high].x){
      high++;
    }
    high--;
    if(low==high){
      low++;
      high++;
      continue;
    }
    mergeS_y(xy,low,high,N);
    low=high;
  }
  for(int i=0; i<N; i++) printf("%d %d\n",xy[i].x,xy[i].y);
  free(xy);
}
