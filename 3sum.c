#include <stdio.h>
#include <stdlib.h>


void DEBUG_PRINT(int* nums, int len){
  int i;
  for (i = 0; i < len; i++){
    printf("%d ",nums[i]);
  }
  printf("\n");

}
void q_sort(int* nums, int len){

  int i,j,pivot;
  int left = 0;
  int right = len-2;
  if(len <= 1) return;
  pivot = nums[len-1];
  while(left < right){
    while(left < right && nums[left] <= pivot) left++;
    while(left < right && nums[right] >= pivot) right--;
    i = nums[left];
    nums[left] = nums[right];
    nums[right] = i;
  }

  /* The number at nums[left] when left == right is larger than pivot. */
  if(nums[left] > pivot){
    q_sort(&nums[0],left);
    q_sort(&nums[right],len-left-1);
    for(j = len - 1; j > right; j--) nums[j] = nums[j-1];
    nums[right] = pivot;
  }
  else {
    q_sort(&nums[0],left+1);
    q_sort(&nums[right+1],len-left-2);
    for(j = len-1; j > right+1;j--) nums[j] = nums[j-1];
    nums[right+1] = pivot;
  }
}

int main(){

  int a,i,j,k;
  int *nums;
  scanf("%d",&a);

  nums = malloc(sizeof(int)*a);

  if(nums == NULL) return 1;

  for(i = 0; i < a; i++){
    scanf("%d",&j);
    nums[i] = j;
  }

  q_sort(nums,a);

  /*DEBUG_PRINT(nums,a);*/

  for(i = 0; i < a - 2; i++){
    j = i+1;
    k = a-1;
    while (j < k){

      /*DEBUG*/
      /*DEBUG_PRINT(nums,a);
      printf("i=%d, j=%d, k=%d\n",i,j,k);*/

      if(nums[i] + nums[j] + nums[k] < 0) j++;
      else if (nums[i] + nums[j] + nums[k] > 0) k--;
      else{
        printf("Found numbers %d + %d + %d == 0.\n",nums[i],nums[j],nums[k]);
        free(nums);
        return 0;
      }
    }
  }

  printf("No combination can be found.\n");

  free(nums);

  return 0;
}
