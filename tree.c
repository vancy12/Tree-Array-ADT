// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct tree{
    int* root;
    int size;
}tree;

tree initBST(tree R, int length){
    R.root = (int*)malloc(sizeof(int)*length);
    R.size = length;
    return R;
}

tree insertBST(tree R, int data){
    int idx = 0;
    
    // for(int i =0; i < R.size; i++){
    //  R.root[i] = 0;
    // }
    
    while(idx < R.size){
        if(R.root[idx] == 0){
            R.root[idx] = data;
            break;
        }
        else if(data < R.root[idx]){
            idx = 2*idx+1;
        }
        else if(data > R.root[idx]){
            idx = 2*idx+2;
        }
    }
    return R;
}

void levelwise(tree R){
    for(int i = 0; i < R.size; i++){
        printf("%d ", R.root[i]);
    }
    return;
}

void isComplete(tree R){
    int count = 0, level = 1;
    for(int i = 0; i < R.size; i++){
        if(R.root[i] != 0)
            count++;
    }

    int calculate = pow(2, level)-1;
    while(calculate < R.size){
        calculate = pow(2, level)-1;
        if (count == calculate){
            printf("\nComplete BST\n");
            return;
        }
        if(count > calculate){
            level++;
            continue;
        }
        if(count < calculate){
            printf("\nIncomplete BST\n");
            return;
        }
    }
}
int main() {

    tree T1;
    T1 = initBST(T1, 7);
 printf("size of tree: %d\n", T1.size);
//  printf("default contents of array:");
//  for(int i = 0; i < T1.size; i++){
//      printf("%d ", T1.root[i]);
//  }
    T1 = insertBST(T1, 20);
    T1 = insertBST(T1, 30);
    T1 = insertBST(T1, 40);
    T1 = insertBST(T1, 25);
    T1 = insertBST(T1, 10);
    T1 = insertBST(T1, 15);
    T1 = insertBST(T1, 5);
    levelwise(T1);
    isComplete(T1);
    
 
    return 0;
}