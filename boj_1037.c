#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int d;
  int *g;
  scanf("%d",&d);
  g=(int*)malloc(sizeof(int)*d);
  for(int i=0; i<d; i++){
    scanf("%d",&g[i]);
  }
  for(int j=0; j<d; j++){
    for(int k=0; k<d-1; k++){
      if(g[k]>g[k+1]){
        int temp = g[k];
        g[k] = g[k+1];
        g[k+1] =temp;
      }
    }
  }
  printf("%d",g[0]*g[d-1]);
  free(g);
}
