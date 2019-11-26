//
//  最小生成树.c
//  DataStructureCourseDesign
//
//  Created by Macsed on 2019/11/25.
//  Copyright © 2019 Macsed. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int getminiumVertexLength(GraphPoint* point){
    Vertex** vertexes = point->vertexes;
    int minIndex = 0;
    for (int i = 1; i< point->vertexCount; i++) {
        Vertex* vertex = vertexes[i];
        if (vertex->length < vertexes[minIndex]->length && vertex->to->used == 0) {
            minIndex = i;
        }
    }
    
    return vertexes[minIndex]->length;
    
}

GraphPoint* getminiumVertexPoint(GraphPoint* point){
    Vertex** vertexes = point->vertexes;
    int minIndex = 0;
    for (int i = 1; i< point->vertexCount; i++) {
        Vertex* vertex = vertexes[i];
        if (vertex->length < vertexes[minIndex]->length && vertex->to->used == 0) {
            minIndex = i;
        }
    }
    
    return vertexes[minIndex]->to;
    
}

void deleteOtherVertex(GraphPoint* point){
    GraphPoint* nextPoint = getminiumVertexPoint(point);
    
    Vertex* newVertex = (Vertex*)malloc(sizeof(Vertex));
    newVertex->length = getminiumVertexLength(point);
    newVertex->to = nextPoint;
    
    point->vertexCount = 1;
    point->vertexes = &newVertex;
    point->used = 1;
}

GraphPoint* findNextPoint(GraphPoint** graph,int count){
    
    if (count == 0) {
        return NULL;
    }
    
    int minIndex = 0 , minLength = 0;
    minLength = getminiumVertexLength(graph[0]);
    
    for (int i = 1; i<count; i++) {
        GraphPoint* point = graph[i];
        if (minLength > getminiumVertexLength(point)) {
            minLength = getminiumVertexLength(point);
            minIndex = i;
        }
    }
    
    GraphPoint* output = getminiumVertexPoint(graph[minIndex]);
    output->used = 1;
//    deleteOtherVertex(graph[minIndex]);
    
    return output;
    
}


GraphPoint** miniumSpanningTree(GraphPoint** graph,int count){
    
    if (count<=1) {
        return &graph[0];
    }
    
    
    srand(time(NULL));
    int nextIndex = rand() % count;
    GraphPoint* point = graph[nextIndex];
    
    int usedCount = 1;
    GraphPoint** usedGraph = &point;
    
    
    while (usedCount < count) {
        GraphPoint* next;
        next = findNextPoint(usedGraph, usedCount);
        usedGraph[usedCount] = next;
        usedCount++;
    }
    
    
    
//    next->vertexCount = 0;
//    next->vertexes = NULL;
    
    return usedGraph;
}
