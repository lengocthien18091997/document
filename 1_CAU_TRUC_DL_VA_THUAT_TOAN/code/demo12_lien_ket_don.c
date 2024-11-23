#include <stdio.h>

// khai báo
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Tạo node mới
struct Node *create(int value)
{
    Node *newEle = (struct Node *)malloc(sizeof(struct Node));
    newEle->data = value;
    newEle->next = NULL;
    return newEle;
};

// Hàm duyệt danh sách và in ra các giá trị
void printList(Node *head)
{
    printf("\n");
    Node *x = head;
    while (x != NULL)
    {
        printf("%d -> ", x->data);
        x = x->next;
    }
    printf("NULL\n");
}

// Duyệt và tìm node = value
Node *find(Node *head, int value)
{
    Node *x = head;
    while (x != NULL)
    {
        if (x->data == value)
        {
            return x;
        }
        x = x->next;
    }
}

// Hàm chèn nút vào đầu danh sách
Node *insertAtHead(Node *head, int value)
{
    Node *newNode = create(0);
    newNode->next = head;
    return newNode;
}

// Hàm chèn nút vào cuối danh sách
void insertAtEnd(Node *head, int value)
{
    Node *newNode = create(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *node = head;
    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = newNode;
}

// Chèn trước 1 node
Node *insertBeforNode(Node *head, Node *nodeBiChen, int value)
{
    // tìm node trước node
    Node *truocNode = head;
    while (truocNode->next != nodeBiChen)
    {
        truocNode = truocNode->next;
    }

    // Tao node moi can chen
    Node *new = create(value);
    // chen giua
    truocNode->next = new;
    new->next = nodeBiChen;
    return new;
}

// Hàm xóa node va tra vef head moi
Node *deleteNode(Node *head, Node *nodeBiXoa)
{
    if (head == NULL || nodeBiXoa == NULL)
    {
        return head;
    }
    if (head == nodeBiXoa)
    {
        head = head->next;
        free(nodeBiXoa);
        return head;
    }
    else
    {
        head->next = deleteNode(head->next, nodeBiXoa);
        return head;
    }
}

// dao vi tri node
Node *daoViTri(Node *head)
{
    Node *cur = head;
    Node *next, *pre;
    pre = NULL;
    next = NULL;

    while (cur != NULL)
    {
        // luu cur vào biến next
        next = cur->next;
        // gán next của cur = pre
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    head = pre;
    return head;
}

int main()
{
    Node *head, *node1, *node2;
    head = create(1);
    node1 = create(2);
    node2 = create(3);
    head->next = node1;
    node1->next = node2;
    printList(head);
    find(head, 3);
    Node *head1 = insertAtHead(head, 0);
    printList(head1);
    insertAtEnd(head1, 4);
    printList(head1);
    insertBeforNode(head1, node1, 9);
    printList(head1);
    deleteNode(head1, node1);
    printList(head1);
    Node *head2 = daoViTri(head1);
    printList(head2);
    return 0;
}
