//
//  建堆与堆排序.c
//  DataStructureCourseDesign
//
//  Created by Macsed on 2019/11/25.
//  Copyright © 2019 Macsed. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct heap Heap;

struct heap {
    int* heap;
    int count;
};

int* rebuildHeapArray(int* array , int n){
    if (n == 1) {
        return array;
    }else if (array[n/2] < array[n]){
        int temp = array[n];
        array[n] = array[n/2];
        array[n/2] = temp;
        return rebuildHeapArray(array, n/2);
    }else{
        return array;
    }
    return array;
}

Heap* reBuildHeap(Heap* heap){
    
    heap->heap = rebuildHeapArray(heap->heap, heap->count);
    
    return heap;
}

Heap* insertToHeap(Heap* heap,int value){
    heap->count+=1;
    heap->heap[heap->count] = value;
    heap = reBuildHeap(heap);
    
    return heap;
}

Heap* buildHeap(int* nums,int n){
    Heap* heap = (Heap*)malloc(sizeof(heap));
    heap->count = 0;
    heap->heap = (int*)malloc(sizeof(int));
    heap->heap[0] = 0;
    
    
    for (int i = 0; i< n; i++) {
        heap = insertToHeap(heap, nums[i]);
    }
    
    return heap;
    
}
