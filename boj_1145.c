#include <stdio.h>
int gcd(int a, int b){
  if(a>b){
    if(b==0) return a;
    return gcd(b,a%b);
  }
  else{
    if(a==0) return b;
    return gcd(b%a,a);
    }
}
int lcm(int a,int b){
  return (a*b)/gcd(a,b);
}
int lcm_3(int a, int b, int c){
  int lcm1 = lcm(a,b);
  return lcm(lcm1,c);
}

void sort(int arr[], int cnt){
  for(int i=0; i<cnt; i++){
    for(int j=0; j<cnt-1; j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
int main(void) {
  int n[5];
  for(int i=0; i<5; i++){
    scanf("%d", &n[i]);
  }
  sort(n,5);

  int lcm9[10];
  lcm9[0]=lcm_3(n[0],n[1],n[2]);
  lcm9[1]=lcm_3(n[0],n[1],n[3]);
  lcm9[2]=lcm_3(n[0],n[1],n[4]);
  lcm9[3]=lcm_3(n[0],n[2],n[3]);
  lcm9[4]=lcm_3(n[0],n[2],n[4]);
  lcm9[5]=lcm_3(n[0],n[3],n[4]);
  lcm9[6]=lcm_3(n[1],n[2],n[3]);
  lcm9[7]=lcm_3(n[1],n[2],n[4]);
  lcm9[8]=lcm_3(n[1],n[3],n[4]);
  lcm9[9]=lcm_3(n[2],n[3],n[4]);

  sort(lcm9,10);

  printf("%d",lcm9[0]);
  
}
