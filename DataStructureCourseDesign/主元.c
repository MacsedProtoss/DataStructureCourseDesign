//
//  主元.c
//  DataStructureCourseDesign
//
//  Created by Macsed on 2019/11/25.
//  Copyright © 2019 Macsed. All rights reserved.
//

#include <stdio.h>

int findMainPivot(int* nums , int n){
    int mid = n/2;
    int j = 0;
    int temp;

    if (n == 0){
        return -1;
    }

    if (n == 1){
        return nums[0];
    }

    for (int i=0; i<mid; i++) {
        if (nums[2*i] == nums[2*i+1]) {
                temp = nums[j];
                nums[j++] = nums[2*i];
                nums[2*i] = temp;
        }
    }
    
    temp = findMainPivot(nums, j);

    if (n % 2 == 1) {
        if (temp == -1) {
                return nums[n-1];
        }
    }

    return temp;
    
}
