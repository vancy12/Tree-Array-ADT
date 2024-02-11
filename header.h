#include <stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct tree{
    int* root;
    int size;
}tree;

typedef struct stack{
    int top;
    int size;
    int* array;
}stack;