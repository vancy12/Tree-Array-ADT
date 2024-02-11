#include "tree.c"

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

    // inorder traversal
    printf("Inorder travesal(non-recursive)\n");
    inorder(T1);
    printf("\nPreorder travesal(non-recursive)\n");   
    preorder(T1);
    
 
    return 0;
}