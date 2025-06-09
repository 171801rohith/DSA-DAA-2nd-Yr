#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[25],phno[15];
    struct node* left, *right;
};
typedef struct node *NODE;
int delflag;
NODE createnode(){
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    printf("Enter the name:");
    scanf("%s",temp->name);
    printf("Enter the phone number:");
    scanf("%s",temp->phno);
    temp->left = 0;
    temp->right = 0;
    return temp;
}

void insertBST(NODE root, NODE newNode){
    if(strcmp(newNode->name,root->name)==0)
    {
        printf("Name already exists\n");
        return;
    }
    else if (strcmp(newNode->name,root->name)<0)
    {
        if (root->left == 0)
        root->left = newNode;
        else
        insertBST(root->left, newNode);
    }
    else
    {
        if (root->right == 0)
        root->right = newNode;
        else
        insertBST(root->right, newNode);
    }
}

int search(NODE root, char keyname[]){
    if(!root)
    return -1;
    if(strcmp(keyname,root->name)==0)
    return 1;
    else if(strcmp(keyname,root->name)<0)
    return search(root->left, keyname);
    else
    return search(root->right,keyname);
}

NODE getRightMin(NODE root){
    NODE temp = root;
    while(temp->left != 0)
    {
        temp = temp->left;
    }
    return temp;
}

NODE deleteBST(NODE root, char keyname[]){
    if(!root)
    {
        delflag=-1;
        return 0;
    }
    if(strcmp(keyname,root->name)<0)
    root->left=deleteBST(root->left, keyname);
    else if(strcmp(keyname,root->name)>0)
    root->right=deleteBST(root->right,keyname);
    else
    {
        if(root->left==0 && root->right==0)
        {
            free(root);
            return 0;
        }
        else if(root->left == 0)
        {
            NODE temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == 0)
        {
            NODE temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            NODE rightMin = getRightMin(root->right);
            strcpy(root->name,rightMin->name);
            strcpy(root->phno,rightMin->phno);
            root->right = deleteBST(root->right,rightMin->name);
        }
    }
    return root;
}

void inorder(NODE temp){
    if (temp != 0)
    {
        inorder(temp->left);
        printf("|%s|%s|\t", temp->name,temp->phno);
        inorder(temp->right);
    }
}

void preorder(NODE temp){
    if (temp != 0)
    {
        printf("|%s|%s|\t", temp->name,temp->phno);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(NODE temp){
    if (temp != 0)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("|%s|%s|\t", temp->name,temp->phno);
    }
}

void main(){
    int choice,n,i,keyFound = 0;
    char keyname[25];
    NODE root=0,newNode;
    while(1){
        choice=0;
        printf("\n1. Search a list for a specified name\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the name to be searched:");
            scanf("%s",keyname);
            keyFound = search(root,keyname);
            if(keyFound == 1)
            printf("Name: %s is found in the BST",keyname);
            else
            printf("Name: %s is not found in the BST",
            keyname);
            break;
            case 2: newNode = createnode();
            if(root == 0)
            root = newNode;
            else
            insertBST(root,newNode);
            break;
            case 3: if(root == 0){
                printf("Tree is empty\n");
            }
            else{
                delflag=0;
                printf("Enter the name to be deleted:");
                scanf("%s",keyname);
                root=deleteBST(root,keyname);
                if(delflag==-1)
                printf("Name: %s is not found in the BST\n",keyname);
                else
                printf("Name: %s is deleted from the BST\n",keyname);
            }
            break;
            case 4: if (root == 0)
            {
                printf("Tree is empty\n");
            }
            else
            {
                printf("BST Preorder traversal\n");
                preorder(root);
                printf("\nBST Inorder traversal\n");
                inorder(root);
                printf("\nBST Postorder traversal\n");
                postorder(root);
            }
            break;
            case 5: return;
            default:printf("Wrong choice\n");
            return;
        }
    }
}
