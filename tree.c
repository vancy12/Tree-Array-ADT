// Online C compiler to run C program online
#include "header.h"

tree initBST(tree R, int length){
    R.root = (int*)malloc(sizeof(int)*length);
    R.size = length;
    return R;
}

void initStack(stack* S, int length){
    S->top = -1;
    S->size = length;
    S->array = (int*)malloc(sizeof(int)*length);
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

int isFull(stack S){
    return(S.top == S.size);
}
int isEmpty(stack S){
    return(S.top == -1);
}

void push(stack* S, int index){
    if(isFull(*S))
        return;
    S->top += 1;
    S->array[S->top] = index;
    return;
}

int pop(stack* S){
    if(isEmpty(*S))
        return 0;
    int p = S->array[S->top];
    S->top -= 1;
    return p;
}
void inorder(tree R){
    stack store;
    initStack(&store, R.size);
    int flag = 1;
    int p = 0;
    while(flag){
        if(p < R.size){
            // printf("value being pushed:%d \n", p);
            push(&store, p);
            p = 2*p + 1;
            // printf("new index: %d\n", p);
        }
        
        else{
           if(!isEmpty(store)){
            p = pop(&store);
            // printf("value being popped: %d\n", p);
            printf("%d ", R.root[p]);
            p = 2*p + 2;
           }
           else{
               flag = 0;
           }
           
        }
    }
}

// check again for debugging
void preorder(tree R){
    stack a, b;
    int p = 0;
    initStack(&a, R.size);
    initStack(&b, R.size);
    push(&a, p);
    printf("outside while loop\n");
    while(!isEmpty(a)){
        printf("inside while loop\n");
        printf("value of p:%d", p);
        p = pop(&a);
        push(&a, p);
        if(R.root[2*p+1] != 0 && 2*p+1 <= R.size){
            push(&a, 2*p+1);
        }
        if(R.root[2*p+2] != 0 && 2*p+2 <= R.size){
            push(&a, 2*p+2);
        }
    }
    while(!isEmpty(b)){
        printf("%d ",R.root[pop(&b)]);
    }
}
