//
//  链表约瑟夫环.c
//  DataStructureCourseDesign
//
//  Created by Macsed on 2019/11/25.
//  Copyright © 2019 Macsed. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct linkedListNode LinkedListNode;
struct linkedListNode{
    int value;
    LinkedListNode* next;
    LinkedListNode* prev;
};

LinkedListNode* init(int num){
    LinkedListNode* head;
    LinkedListNode* prev;
    
    for (int i = 0; i<num; i++) {
        LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        node->value = i+1;
        if (i == 0) {
            head = node;
            prev = node;
            head->next = head;
            head->prev = prev;
        }else{
            prev->next = node;
            node->prev = prev;
            if (i == num-1) {
                node->next = head;
                head->prev = node;
            }
            prev = node;
        }
        
    }
    
    return head;
}

void Josephus(int num,int step){
    LinkedListNode* node = init(num);
    int count = 0;
    while (node->next != node) {
        count++;
        if (count % step == 0){
            printf("%d ", node->value);
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node = node->next;
        
    }
    printf("%d\n",node->value);
    
}

