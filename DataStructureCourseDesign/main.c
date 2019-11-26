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

typedef struct heap Heap;

struct heap {
    int* heap;
    int count;
};

typedef struct graphPoint GraphPoint;
typedef struct vertex Vertex;

struct graphPoint {
    int value;
    Vertex** vertexes;
    int vertexCount;
    int used;
};

struct vertex {
    GraphPoint* to;
    int length;
};

extern int maxSumOfSubList(int *nums,int n);
extern int findMainPivot(int* nums , int n);
extern void Josephus(int num,int step);
extern int* radixSort(int* input,int count,int n);
extern TreeNode* insertAVLNode(TreeNode* root,int value);
extern Heap* buildHeap(int* nums,int n);
extern int* qucikSort(int* nums,int n);
extern GraphPoint** miniumSpanningTree(GraphPoint** graph,int count);

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
//    int input3[] = {1,2,3,4,5,6,7,8,9};
//    Heap* heap = buildHeap(input3, 9);
//    for (int i = 0; i<= 9; i++) {
//        printf("%d ",heap->heap[i]);
//    }
//    int input4[] = {9,8,7,6,5,4,3,2,1};
//    int* output = qucikSort(input4, 9);
//    for (int i = 0; i<9; i++) {
//        printf("%d ",output[i]);
//    }
    
    GraphPoint** input5 = (GraphPoint**)malloc(sizeof(GraphPoint*));
    int input5n = 3;
    
    Vertex* A1 = (Vertex*)malloc(sizeof(Vertex));
    Vertex* A2 = (Vertex*)malloc(sizeof(Vertex));
    GraphPoint* A = (GraphPoint*)malloc(sizeof(GraphPoint));
    Vertex* B1 = (Vertex*)malloc(sizeof(Vertex));
    Vertex* B2 = (Vertex*)malloc(sizeof(Vertex));
    GraphPoint* B = (GraphPoint*)malloc(sizeof(GraphPoint));
    Vertex* C1 = (Vertex*)malloc(sizeof(Vertex));
    Vertex* C2 = (Vertex*)malloc(sizeof(Vertex));
    GraphPoint* C = (GraphPoint*)malloc(sizeof(GraphPoint));
    
    A1->length = 7;
    A1->to = B;
    A2->length = 5;
    A2->to = C;
    
    B1->length = 7;
    B1->to = A;
    B2->length = 9;
    B2->to = C;
    
    C1->length = 5;
    C1->to = A;
    C2->length = 9;
    C2->to = B;
    
    Vertex** vertexesA = (Vertex**)malloc(sizeof(Vertex*));
    
    A->used = 0;
    A->value = 1;
    A->vertexCount = 2;
    vertexesA[0]=A1;
    vertexesA[1]=A2;
    A->vertexes=vertexesA;
    
    Vertex** vertexesB = (Vertex**)malloc(sizeof(Vertex*));
    
    B->used = 0;
    B->value = 2;
    B->vertexCount = 2;
    vertexesB[0]=B1;
    vertexesB[1]=B2;
    B->vertexes=vertexesB;
    
    Vertex** vertexesC = (Vertex**)malloc(sizeof(Vertex*));
    
    C->used = 0;
    C->value = 3;
    C->vertexCount = 2;
    vertexesC[0]=C1;
    vertexesC[1]=C2;
    C->vertexes=vertexesC;
    
    input5n = 3;
    input5[0] = A;
    input5[1] = B;
    input5[2] = C;
    
    GraphPoint** output = miniumSpanningTree(input5, input5n);
    

    return 0;
}
