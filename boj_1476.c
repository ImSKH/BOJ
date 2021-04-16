#include <stdio.h>

int main(void) {
  int E,S,M,year;
  scanf("%d %d %d",&E,&S,&M);
  if(E==S&&S==M){
    printf("%d",E);
    return 0;}
  for(int a=0; a<=28*19;a++){
    for(int b=0; b<=15*19; b++){
      for(int c=0; c<=15*28; c++){
        if((15*a+E==28*b+S)&&(28*b+S==19*c+M)){
          printf("%d",15*a+E);
          break;
        }
      }
    }
  }
  return 0;
}
