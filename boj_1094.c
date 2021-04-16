#include <stdio.h>

int bitmask(int x){
  if(x==0) return 0;
  return x%2+bitmask(x/2);
}

int main(void) {
  int x;
  scanf("%d",&x);
  printf("%d",bitmask(x));
}  
