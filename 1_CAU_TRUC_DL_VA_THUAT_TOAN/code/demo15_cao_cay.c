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
    Node *node = (Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int height2(Node *node)
{
    if (node == NULL)
        return 0;
    int maxH = 0;
    Node *left = node->left;
    while (left != NULL)
    {
        int h = height2(left);
        if (h > maxH)
        {
            maxH = h;
        }
        left = left->right;
    }
    return maxH + 1;
}

int findDepth(Node *root, Node *node, int d)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root == node)
    {
        return 1;
    }
    // tim trong cay con trai
    int leftDepth = findDepth(root->left, node, d + 1);
    if (leftDepth != 0)
        return leftDepth;
    // Tim trong cay con phai
    return findDepth(root->right, node, d + 1);
}

int findDepth2(Node *root, int value, int d)
{
    if (root == NULL)
        return -1;
    if (root->data == value)
        return d;
    Node *left = root->left;
    while (left != NULL)
    {
        if (left->data == value)
            return d + 1;
        int dv = findDepth2(left, value, d + 1);

        if (dv > 0)
            return dv;

        left = left->right;
    }
    return -1;
}

// Hàm tính tổng của tất cả các nút lá
int tongNutLa(Node *root)
{
    if (root == NULL)
        return 0;

    // Nếu là nút lá (không có con trái và con phải)
    if (root->left == NULL && root->right == NULL)
        return root->data;

    // Nếu không phải là nút lá, tính tổng trong cây con trái và cây con phải
    return tongNutLa(root->left) + tongNutLa(root->right);
}
// dem cac nut la

int demNutLa(Node *root)
{
    if (root == NULL)
        return 0;

    // Nếu là nút lá (không có con trái và con phải)
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Nếu không phải là nút lá, đếm trong cây con trái và cây con phải
    return demNutLa(root->left) + demNutLa(root->right);
}

// Hàm đếm số lượng nút có 2 nút con
int demCacNutCo2NutCon(Node *root)
{
    if (root == NULL)
        return 0;

    // Kiểm tra xem nút có 2 con trái và phải không
    int count = (root->left != NULL && root->right != NULL) ? 1 : 0;

    // Đệ quy đếm trong cây con trái và cây con phải
    return count + demCacNutCo2NutCon(root->left) + demCacNutCo2NutCon(root->right);
}

int main()
{
    Node *root = createNode(7);
    root->left = createNode(3);
    root->left->left = createNode(8);
    root->left->right = createNode(12);
    root->right = createNode(4);
    root->right->left = createNode(11);
    root->right->right = createNode(2);
    root->left->left->left = createNode(6);
    root->left->left->right = createNode(5);
    root->left->left->right->left = createNode(9);
    printf("heigh: %d", height(root->left));
    printf("\n");
    printf("heigh2: %d", height2(root->left));
    printf("\n");
    printf("depth: %d", findDepth(root, root->left->left, 1));
    printf("\n");
    printf("depth2: %d", findDepth2(root, 8, 1));
    printf("\n");
    printf("tong cac nut la: %d", tongNutLa(root));
    printf("\n");
    printf("dem cac nut co 2 nut con : %d", demCacNutCo2NutCon(root));
    printf("\n");
    printf("dem cac nut la: %d", demNutLa(root));
}