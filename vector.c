#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

#define  INITIAL_CAPACITY 10

Vector *vector_create(void) {
    Vector *vector = (Vector *)malloc(sizeof(Vector));
    if (vector == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    vector->data = (double *)malloc(INITIAL_CAPACITY * sizeof(double));
    if (vector->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(vector); // 释放前一个分配的内存
        exit(EXIT_FAILURE);
    }

    vector->size = 0;
    vector->capacity = INITIAL_CAPACITY;

    return vector;
}

void vector_push(Vector *vector, double element) {
    // 如果向量已满，则扩展其容量
    if (vector->size >= vector->capacity) {
        vector->capacity *= 2;
        vector->data = (double *)realloc(vector->data, vector->capacity * sizeof(double));
        if (vector->data == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }

    // 添加新元素到向量末尾
    vector->data[vector->size++] = element;
}

double vector_get(Vector *vector, int index) {
    // 检查索引是否有效
    if (index < 0 || index >= vector->size) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }

    return vector->data[index];
}

void vector_free(Vector *vector) {
    // 释放存储元素的数组
    free(vector->data);
    // 释放向量本身的内存
    free(vector);
}

// vector.c

