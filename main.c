#include "tree.c"

int main() {

    tree T1;
    T1 = initBST(T1, 7);
    printf("size of tree: %d\n", T1.size);

    // T1 = insertBST(T1, 20);
    // T1 = insertBST(T1, 30);
    // T1 = insertBST(T1, 40);
    // T1 = insertBST(T1, 25);
    // T1 = insertBST(T1, 10);
    // T1 = insertBST(T1, 15);
    // T1 = insertBST(T1, 5);
    
    int choice, data;
    do {
        printf("\nMenu:\n");
        printf("1. Insert into BST\n");
        printf("2. Non-Recursive Inorder Traversal\n");
        printf("3. Non-Recursive Preorder Traversal\n");
        printf("4. Non-Recursive Postorder Traversal\n");
        printf("5. Level-wise Traversal\n");
        printf("6. Check if BST is Complete\n"); 
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                T1 = insertBST(T1, data);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(T1);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(T1);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(T1);
                printf("\n");
                break;
            case 5:
                printf("Level-wise Traversal: ");
                levelwise(T1);
                printf("\n");
                break;
            case 6:
                isComplete(T1);
                break;
            case 7:
                free(T1.root);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 7.\n");
        }
    } while(choice != 7);
 
    return 0;
}