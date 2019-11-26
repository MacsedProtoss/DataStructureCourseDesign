//
//  快速排序.c
//  DataStructureCourseDesign
//
//  Created by Macsed on 2019/11/25.
//  Copyright © 2019 Macsed. All rights reserved.
//

#include <stdio.h>

int* loopQucikSort(int* nums , int start ,int end){
    
    if (start >= end) {
        return nums;
    }
    
    int pivot = end;
    int left = 0;
    int right = end - 1;
    
    while (left < right) {
        while (nums[left]<nums[pivot]) {
            left++;
        }
        while (nums[right]>nums[pivot]) {
            right--;
        }
        
        if (left<= right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
    }
    
    if (nums[left] > nums[end]) {
        int temp = nums[end];
        nums[end] = nums[left];
        nums[left] = temp;
    }else if (nums[left] < nums[end]){
        left++;
        int temp = nums[end];
        nums[end] = nums[left];
        nums[left] = temp;
    }
    
    nums = loopQucikSort(nums,start,left-1);
    nums = loopQucikSort(nums,left+1,end);
    
    return nums;
    
}

int* qucikSort(int* nums,int n){
    
    return loopQucikSort(nums,0,n-1);
    
}
