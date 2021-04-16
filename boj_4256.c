#include <stdio.h>
#include <stdlib.h>

int preorder[1001];
int inorder[1001];

void postorder(int root, int st, int end){
  for(int i=st; i<end; i++){
    if(inorder[i]==preorder[root]){
      postorder(root+1,st,i);
      postorder(root+i+1-st,i+1,end);
      printf("%d ", preorder[root]);
    }
  }
}


int main(){
  int T, N;
  scanf("%d",&T);
  for(int i=0; i<T; i++){
    scanf("%d",&N);
    for(int j=0; j<N; j++) scanf("%d",&preorder[j]);
    for(int k=0; k<N; k++) scanf("%d",&inorder[k]);
    postorder(0,0,N);
    printf("\n");
  }
}
