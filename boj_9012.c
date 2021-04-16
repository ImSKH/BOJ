#include <stdio.h>

char s_o[1000];
int r=-1;

void push(){
  ++r;
}

void pop(){
  --r;
}

int main(){
  int T=0, rss=0, k;
  int rs[1000]={0,};
  char c;
  char s;
  scanf("%d",&T);
  scanf("%c",&s);
  for(int i=0; i<T; i++){
    r=-1;
    rss=0;
    k=0;
    while(1){
      scanf("%c",&c);
      if(c=='(') ++r;
      else if(c==')'){
        --r;
      }
      rs[k]=r;
      ++k;
      if(c=='\n') break;
    }
    rs[k]=r;
    for(int i=0; i<k; i++){
      if(rs[i]==-2){
        rss = -2;
        printf("NO\n");
        break;
      }
    }
    if((rss!=-2)&&(rs[k]==-1)){
        printf("YES\n");
    }
    else if((rss!=-2)&&(rs[k]>=0)){
        printf("NO\n");
    }
  }
}
