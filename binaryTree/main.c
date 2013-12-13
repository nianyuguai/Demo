#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}NodeTree;

NodeTree* makeEmpty(NodeTree* Tree)
{
    if(Tree != NULL)
    {
        makeEmpty(Tree->left);
        makeEmpty(Tree->right);
        free(Tree);
    }
    return NULL;
}

NodeTree* insertTree(NodeTree* Tree,int element)
{
    if(Tree == NULL)
    {
        Tree = malloc(sizeof(NodeTree));
        Tree->data = element;
        Tree->left = Tree->right = NULL;
    }else if(element < Tree->data)
    {
        Tree->left = insertTree(Tree->left,element);
    }else if(element > Tree->data)
    {
        Tree->right = insertTree(Tree->right,element);
    }
    return Tree;
}

void printfTree(NodeTree* Tree)
{
    if(Tree == NULL)
        return;
    else{
        printfTree(Tree->left);
        printf("%d ",Tree->data);
        printfTree(Tree->right);
    }

}

int main()
{
    int n,i,nElement;
    NodeTree* Tree;
    while(~scanf("%d",&n))
    {
        Tree = makeEmpty(NULL);
        for(i = 0;i < n;i++)
        {
            scanf("%d",&nElement);
            Tree = insertTree(Tree,nElement);
        }
        printfTree(Tree);
        printf("\n");
    }
    printf("Hello world!\n");
    return 0;
}
