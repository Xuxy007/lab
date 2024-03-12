#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

#define  INITIAL_CAPACITY 10
//子问题1
Vector *vector_create(void) {
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    if (vector == NULL) {
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);
    }

    vector->data = (double *)malloc(INITIAL_CAPACITY * sizeof(double));
    if (vector->data == NULL) {
        fprintf(stderr, "内存分配失败\n");
        free(vector); // 释放先前分配的内存
        exit(EXIT_FAILURE);
    }

    vector->size = 0;
    vector->capacity = INITIAL_CAPACITY;

    return vector;
}

void vector_push(Vector *vector, double element) {
    // 如果向量已满，则增加其容量
    if (vector->size >= vector->capacity) {
        int new_capacity = vector->capacity * 2;
        double *new_data = (double *)realloc(vector->data, new_capacity * sizeof(double));
        if (new_data == NULL) {
            fprintf(stderr, "内存重新分配失败\n");
            exit(EXIT_FAILURE);
        }
        vector->data = new_data;
        vector->capacity = new_capacity;
    }

    // 将新元素添加到向量末尾
    vector->data[vector->size++] = element;
}

double vector_get(Vector *vector, int index) {
    // 检查索引是否有效
    if (index < 0 || index >= vector->size) {
        fprintf(stderr, "索引超出范围\n");
        exit(EXIT_FAILURE);
    }

    return vector->data[index];
}

void vector_free(Vector *vector) {
    // 释放存储元素的数组
    free(vector->data);
    // 释放向量本身分配的内存
    free(vector);
}

// vector.c


