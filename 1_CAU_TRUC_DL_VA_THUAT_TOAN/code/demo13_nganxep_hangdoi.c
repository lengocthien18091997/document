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

// them vao ngan xep
Node *push(Node *head, int value)
{
    Node *new = create(value);
    if (head == NULL)
    {
        return new;
    }
    else
    {
        new->next = head;
        return new;
    }
}

// lay khoi ngan xep
Node *pop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *p = head;
        head = head->next;
        free(p);
        return head;
    }
}

int deQue(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *end = head;
    int ans;
    if (end->next == NULL)
    {
        ans = end->data;
        free(end);
        head = NULL;
        return ans;
    }
    while (end->next->next != NULL)
    {
        end = end->next;
    }
    Node *endCuoi;
    endCuoi = end->next;
    end->next = NULL;
    ans = endCuoi->data;
    free(endCuoi);
    return ans;
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

    // ngan xep
    Node *head1 = push(head, 0);
    printList(head1); // them 0

    Node *head2 = pop(head1);
    printList(head2); // xoa 0

    // hang doi
    Node *head3 = push(head2, 0); // them 0
    printList(head3);

    deQue(head3);
    printList(head3); // xoa 3

    return 0;
}
