#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
  int age;
  char name[102];
}Member;

void Merge(Member ar[], int low, int mid, int high, int size){
  int i=low, j=mid+1, k=low;
  Member *tmp;
  tmp=(Member *)malloc(sizeof(Member)*size);
  while(i<=mid&&j<=high){
    if(ar[i].age<=ar[j].age) tmp[k++]=ar[i++];
    else tmp[k++]=ar[j++];
  }
  while(i<=mid) tmp[k++]=ar[i++];
  while(j<=high) tmp[k++]=ar[j++];
  for(int a=low; a<=high; a++) ar[a]=tmp[a];
  free(tmp);
}

void MergeS(Member ar[], int low, int high, int size){
  if(low<high){
    int mid=(low+high)/2;
    MergeS(ar,low,mid,size);
    MergeS(ar,mid+1,high,size);
    Merge(ar,low,mid,high,size);
  }
}

int main(){
  Member *person;
  int N;
  int age;
  char name[102];
  scanf("%d",&N);
  person=(Member *)malloc(sizeof(Member)*N);
  for(int i=0; i<N; i++){
    scanf("%d ",&age);
    fgets(name,102,stdin);
    name[strlen(name)-1]='\0';
    person[i].age=age;
    strcpy(person[i].name, name);
  }
  MergeS(person,0,N-1,N);
  for(int j=0; j<N; j++){
    printf("%d %s\n",person[j].age,person[j].name);
  }
}
