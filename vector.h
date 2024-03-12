#ifndef LAB_2_VECTOR_H
#define LAB_2_VECTOR_H

#define VECTOR_INITIAL_CAPACITY 10

typedef struct {
    double *data;  // 存储元素的数组
    int size;      // 向量中当前元素的数量
    int capacity;  // 向量当前的容量
} Vector;

Vector *vector_create(void);

void vector_push(Vector *vector, double element);

double vector_get(const Vector *vector, int index);

void vector_free(Vector *vector);

#endif // LAB_2_VECTOR_H


