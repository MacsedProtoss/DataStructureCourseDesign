//
//  main.c
//  DataStructureCourseDesign
//
//  Created by Macsed on 2019/11/25.
//  Copyright © 2019 Macsed. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode TreeNode;

struct treeNode{
    int value;
    TreeNode* leftSon;
    TreeNode* rightSon;
};

extern int maxSumOfSubList(int *nums,int n);
extern int findMainPivot(int* nums , int n);
extern void Josephus(int num,int step);
extern int* radixSort(int* input,int count,int n);
extern TreeNode* insertAVLNode(TreeNode* root,int value);

int main(int argc, const char * argv[]) {
    // insert code here...
//    int input1[] = {1,3,-2,5,-7,6};
//    int input1n = 5;
//    printf("%d",maxSumOfSubList(input1, input1n));
//    Josephus(8, 3);
//    int input2[] = {1,3,2,5,7,6,1,2,3,4,5,6,7,9,8,7,6,5,4,34,3,2,1};
//    int input2count = 23;
//    int input2n = 6;
//    int* output = radixSort(input2, input2count, input2n);
//    for (int i = 0; i<input2count; i++) {
//        printf("%d ",output[i]);
//    }
    return 0;
}
