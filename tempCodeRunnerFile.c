#include <stdio.h>
#include <stdbool.h>
int nums[4] = {1,2,3,4};
int numsSize = 4;
bool containsDuplicate(int* nums, int numsSize){
    int duplicate = 0;
    for(int i= 0;i<numsSize;i++){
        for(int k=0;k<numsSize;k++){
            if(nums[i] == nums[k]){
                duplicate++;
            }
            if(duplicate>2){
                printf("true");
                return 1;
            }
        }
    }
    printf("false");
    return 0;
}