//
//  基数排序.c
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
};

LinkedListNode** radixList;

void insertNode(int atIndex, int input){

    LinkedListNode* head = radixList[atIndex];

    if (head != NULL) {
        LinkedListNode* node = head;
        LinkedListNode* prev = head;
        while (node->next != NULL && node->value < input) {
            prev = node;
            node = node->next;
        }

        LinkedListNode* new = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        new->value = input;

        if (node == head) {
            if (node->value < input){
                node->next = new;
                new->next = NULL;
            }else{
                new->next = node;
                radixList[atIndex] = new;
            }
        }else if(node->next != NULL){
            new -> next = node;
            prev -> next = new;
        }else if(node -> next == NULL){
            if (node->value < input){
                node->next = new;
                new->next = NULL;
            }else{
                prev-> next = new;
                new->next = node;
            }
        }

    }else{
        LinkedListNode* new = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        new->next = NULL;
        new->value = input;
        radixList[atIndex] = new;
    }

}

LinkedListNode* mergeLinkedList(LinkedListNode* head1,LinkedListNode* head2){
    LinkedListNode* output = NULL;
    LinkedListNode* temp = NULL;

    while (head1 != NULL && head2 != NULL) {
        int value1 = head1->value,value2 = head2->value;
        LinkedListNode* new = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        if (value1 < value2) {
            new->next = NULL;
            new->value = value1;
            head1 = head1->next;
        }else{
            new->next = NULL;
            new->value = value2;
            head2 = head2->next;
        }

        if (output == NULL) {
            output = new;
            temp = output;
        }else{
            temp->next = new;
            temp = new;
        }
    }

    while (head1 != NULL) {
        LinkedListNode* new = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        new->next = NULL;
        new->value = head1->value;
        if (output == NULL) {
            output = new;
            temp = output;
        }else{
            temp->next = new;
            temp = new;
        }
        head1 = head1->next;
    }

    while (head2 != NULL) {
        LinkedListNode* new = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        new->next = NULL;
        new->value = head2->value;
        if (output == NULL) {
            output = new;
            temp = output;
        }else{
            temp->next = new;
            temp = new;
        }
        head2 = head2->next;
    }
    return output;
}

void initLinkedLists(int n){
    for (int i = 0; i<n; i++) {
    radixList[i] = NULL;
    }
}

int* radixSort(int* input,int count,int n){
    LinkedListNode* outputLinkedList = NULL;
    int* output = malloc(sizeof(int)*n);
    int outputIndex = 0;
    radixList = malloc(sizeof(LinkedListNode*)*n);
    initLinkedLists(n);
    for (int i = 0; i< count; i++) {
        int item = input[i];
        insertNode(item%n, item);
    }

    if (n > 0) {
        outputLinkedList = radixList[0];
    }

    for (int i = 0; i<n-1; i++) {
        outputLinkedList = mergeLinkedList(outputLinkedList, radixList[i+1]);
    }

    while (outputLinkedList != NULL) {
        output[outputIndex] = outputLinkedList->value;
        outputLinkedList = outputLinkedList->next;
        outputIndex++;
    }
    return output;
}
