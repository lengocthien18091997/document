#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong cây nhị phân
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Hàm tạo một nút mới
Node *createNode(int data)
{
    Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Thêm nút vào cây nhị phân (theo thứ tự nhị phân tìm kiếm)
Node *insert(Node *node, int data)
{
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// Duyệt cây theo thứ tự trước (Preorder) từ trên xuống và từ trái sang phải
void preorder(Node *root)
{
    // nếu node đang duyệt khác null thì in + duyệt trái nó + duyệt phải nó
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Duyệt cây theo thứ tự giữa (Inorder)
void inorder(Node *root)
{
    // nếu node đang duyệt khác null thì duyệt trái nó + in nó + duyệt phải nó
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Duyệt cây theo thứ tự sau (Postorder) từ dưới lên và từ trái sang phải
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("giua: ");
    inorder(root);
    printf("\n");

    printf("truoc: ");
    preorder(root);
    printf("\n");

    printf("sau: ");
    postorder(root);
    printf("\n");

    return 0;
}
