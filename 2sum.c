#include <stdio.h>
#include <stdlib.h>


void DEBUG_printnums(int * nums, int len){
  int i;
  for (i = 0; i < len; i++){
    printf("%d ",nums[i]);
  }
  printf("\n");
}

void q_sort(int* nums, int len){
  int left,right,i;
  int pivot = nums[len-1];
  if(len<=1) return;
  left = 0;
  right = len - 2;
  while(left < right){
    while(left < right && nums[left] <= pivot) {
      left++;
    }
    while(left < right && nums[right] >= pivot) {
      right--;
    }
    i = nums[left];
    nums[left] = nums[right];
    nums[right] = i;
  }
  if(nums[left] > pivot){
    q_sort(&nums[0],left);
    q_sort(&nums[left],len - left - 1);
    for(i = len-1; i > left; i--){
      nums[i] = nums[i-1];
    }
    nums[left] = pivot;
  }
  else if (nums[left] <= pivot){
    q_sort(&nums[0],left + 1);
    q_sort(&nums[left+1],len - left - 2);
    for(i = len-1; i > left + 1; i--){
      nums[i] = nums[i-1];
    }
    nums[left+1] = pivot;
  }
}

int main(){
  int ref,cnt,left,right;
  int* nums;
  scanf("%d",&ref);
  scanf("%d",&cnt);
  nums = malloc(sizeof(int)*cnt);
  for(left = 0; left < cnt; left++){
    scanf("%d", &right);
    nums[left] = right;
  }
  q_sort(nums,cnt);
  left = 0;
  right = cnt -1;
  
  while(left < right){
    if (nums[left] + nums[right] < ref) left++;
    else if (nums[left] + nums[right] > ref) right--;
    else {
      printf("Found two numbers %d and %d.\n",nums[left],nums[right]);
      free(nums);
      return 0;
    } 
  }
  printf("Could not find two numbers.\n");
  free(nums);
  return 1;
}
