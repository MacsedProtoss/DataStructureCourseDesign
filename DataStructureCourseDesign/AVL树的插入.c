//
//  AVL树的插入.c
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

int getTreeHeight(TreeNode* root){
    if (root != NULL) {
        return getTreeHeight(root->leftSon)>getTreeHeight(root->rightSon) ? getTreeHeight(root->leftSon)+1 : getTreeHeight(root->rightSon)+1 ;
    }else{
        return 0;
    }
    
    return -1;
}

int getBalanceNum(TreeNode* root){
    return getTreeHeight(root->leftSon)-getTreeHeight(root->rightSon);
}

TreeNode* rotateTreeToRight(TreeNode* root){
    TreeNode* newRoot = root->leftSon;
    newRoot->rightSon = root;
    root->leftSon = NULL;
    return newRoot;
}

TreeNode* rotateTreeToLeft(TreeNode* root){
    TreeNode* newRoot = root->rightSon;
    newRoot->leftSon = root;
    root->rightSon = NULL;
    return newRoot;
}

TreeNode* ReBalance(TreeNode* root){
    int num = getBalanceNum(root);
    if (num>1) {
        if (getBalanceNum(root->leftSon)>0) { //LL
            return rotateTreeToLeft(root);
        }else if(getBalanceNum(root->leftSon)<=0){ //LR
            root->leftSon = rotateTreeToLeft(root->leftSon);
            return rotateTreeToRight(root);
        }
    }else if (num < -1){
        if (getBalanceNum(root->leftSon)<=0) { //RR
            return rotateTreeToRight(root->rightSon);
        }else if (getBalanceNum(root->leftSon)>0){ //RL
            root->rightSon = rotateTreeToRight(root->rightSon);
            return rotateTreeToLeft(root);
        }
    }
    
    return root;
}

TreeNode* insertAVLNode(TreeNode* root,int value){
    
    if (root == NULL) {
        TreeNode* newRoot = (TreeNode*)malloc(sizeof(TreeNode));
        newRoot->leftSon=NULL;
        newRoot->rightSon=NULL;
        newRoot->value = value;
        return newRoot;
        
    }else{
        if (root->value == value) {
            return root;
        }else{
            if (root->value < value) {
                insertNode(root->leftSon, value);
            }else{
                insertNode(root->rightSon, value);
            }
        }
    }

    return ReBalance(root);
}
