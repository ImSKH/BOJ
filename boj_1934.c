#include <stdio.h>

int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b,a%b);
}

int main() {
  int T,A,B;
  scanf("%d",&T);
  for(int i=0; i<T; i++){
    scanf("%d %d", &A,&B);
    printf("%d\n",(A*B)/gcd(A,B));
  }
}
