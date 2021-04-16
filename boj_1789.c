#include <stdio.h>

int main(void) {
  double S,N;
  scanf("%lf",&S);
  for(double i=0; i<93000; i++){
    if(i*(i+1)<=2*S) N=i;
    else if(i*(i+1)>2*S) break;
  }
  printf("%0.lf",N);
}
