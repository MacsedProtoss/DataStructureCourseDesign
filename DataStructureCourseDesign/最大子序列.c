//
//  最大子序列.c
//  DataStructureCourseDesign
//
//  Created by Macsed on 2019/11/25.
//  Copyright © 2019 Macsed. All rights reserved.
//

#include "stdio.h"

int maxSumOfSubList(int *nums,int n){
    int plusTemp = 0,miniumTemp = 0,max = 0;
    
    
    
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        
        if (num < 0) {
            miniumTemp += num;
            if (plusTemp == 0) {
                miniumTemp = 0;
            }else{
                if (plusTemp + miniumTemp < 0) {
                    
                    plusTemp = 0;
                    miniumTemp = 0;
                }else if (i == n-1){
                    miniumTemp -= num;
                }
            }
            
        }else{
            plusTemp += num;
            max = max > plusTemp+miniumTemp ? max : plusTemp+miniumTemp;
        }
        
        
        
        
    }
    
    
    
    return max;
}
