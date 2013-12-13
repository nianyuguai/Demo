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
    //ɾ���ڵ��м�������������ӽڵ㶼���ڣ�
    //ֻ����ڵ㣻ֻ���ҽڵ㣻���������ҽڵ㣻�Ҳ���Ԫ��
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
        //����2���ӽڵ㣬��ߵ�ָ�벻���޸�
        tmpTree = findMin(Tree->right);//�ҵ��ұ���С�Ľڵ�
        Tree->data = tmpTree->data;//����С�Ľڵ�ŵ�ɾ���Ľڵ㴦
        Tree->right = deleteTree(Tree->right,Tree->data);//�޸��ұߵ�ָ��
    }else
    {
        //��Ҫɾ���Ľڵ㱣��
        tmpTree = Tree;
        if(Tree->left == NULL)
        {
            Tree = Tree->right;  //ָ�벻���޸ģ�ֱ�ӽ��ұ߽ڵ��滻ɾ���ڵ�
        }else if(Tree->right == NULL)
        {
            Tree = Tree->left;
        }
        free(tmpTree);//�ͷ�ɾ���ڵ�ռ�õĿռ�
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
    printf("Hello world!\n");
    return 0;
}
