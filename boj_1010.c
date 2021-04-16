#include <stdio.h>

double fac(int n){
  if(n==0) return 1;
  return n*fac(n-1);
}

int main(void) {
  int T ;
  scanf("%d",&T);
  int n[T],m[T];
  for(int i=0; i<T; i++){
    scanf("%d %d",&n[i],&m[i]);
  }
  
  double brd[T];
  for(int j=0; j<T;j++){
    brd[j]=fac(m[j])/(fac(m[j]-n[j])*fac(n[j]));
  }

  for(int k=0; k<T; k++){
    printf("%0.lf\n",brd[k]);
  }

  }
