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

NodeTree* findMin(NodeTree* Tree)
{
    if(Tree == NULL)
        return NULL;
    else if(Tree->left == NULL)
        return Tree;
    else
        return findMin(Tree->left);
}

NodeTree* deleteTree(NodeTree* Tree,int element)
{
    //删除节点有几种情况：左右子节点都存在；
    //只有左节点；只有右节点；不存在左右节点；找不到元素
    NodeTree *tmpTree;

    if(Tree == NULL)
        printf("can't find the element");
    else if(Tree->data > element)
    {
        Tree->left = deleteTree(Tree->left,element);
    }
    else if(Tree->data < element)
    {
         Tree->right = deleteTree(Tree->right,element);
    }
    else if(Tree->left && Tree->right)
    {
        //存在2个子节点，左边的指针不用修改
        tmpTree = findMin(Tree->right);//找到右边最小的节点
        Tree->data = tmpTree->data;//将最小的节点放到删除的节点处
        Tree->right = deleteTree(Tree->right,Tree->data);//修改右边的指针
    }else
    {
        //将要删除的节点保存
        tmpTree = Tree;
        if(Tree->left == NULL)
        {
            Tree = Tree->right;  //指针不用修改，直接将右边节点替换删除节点
        }else if(Tree->right == NULL)
        {
            Tree = Tree->left;
        }
        free(tmpTree);//释放删除节点占用的空间
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
        printf("delete number:");
        scanf("%d",&nElement);
        Tree = deleteTree(Tree,nElement);
        printfTree(Tree);
        printf("\n");
    }
    printf("Hello worlddsfasdfs!\n");
    return 0;
}
