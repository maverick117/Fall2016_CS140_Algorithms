#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define uchar unsigned char

int count,rows;
uchar* sols;

void print(){
  int i,j;
  for(i = 0; i < 8; i++){
    uchar rows = sols[i];
    for(j = 0; j < 8; j++){
      printf("%d ",rows & 1);
      rows >>= 1;
    }
    printf("\n");
  }
  printf("\n");
}

void loop(uchar A, uchar B, uchar C){
  uchar D;
  if (B == (uchar)255) {
    count++;
    printf("Solution %d:\n",count);
    print();
    return;
  }
  rows++;
  D = ~(A|B|C);
  while(D){
    uchar bit = D & -D;
    D -= bit;
    sols[rows] = bit;
    loop((A|bit)<<1,B|bit,(C|bit)>>1);
  }
  rows--;
}

int main(){
  count = 0;
  rows = -1;
  sols = malloc(sizeof(uchar)*8);
  memset(sols, 0 , 8*sizeof(uchar));
  loop(0,0,0);
  printf("Number of solutions: %d\n", count);
  free(sols);
  return 0;
}
