#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  int a,b,i,j;
  char * c,*d;
  int * mat;
  scanf("%d%d",&a,&b);

  if(a <= 0 || b <= 0){
    printf("0\n");
    return 0;
  }

  c = malloc(sizeof(char)*(a+1));
  d = malloc(sizeof(char)*(b+1));
  mat = malloc(sizeof(int)*a*b);
  memset(mat,0,sizeof(int)*a*b);

  scanf("%s",c);
  scanf("%s",d);

  for(i=0;i<a;i++){
    for(j=0;j<b;j++){
      if(c[i] == d[j]){
        mat[i*b+j] = 1 + ((i == 0 || j == 0)?0:mat[(i-1)*b+j-1]);
      }
    }
  }
  j = 0;
  for(i = 0; i < a*b; i++){
    if(mat[i] > j) j = mat[i];
  }

  printf("%d\n",j);

  free(c);
  free(d);
  free(mat);

  return 0;

}
