#include <iostream>
#include <stack>
using namespace std;

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Stack {
    int top;
    int capacity;
    Node **array;
} Stack;

Node *newNode(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (Node **)malloc(stack->capacity * sizeof(Node *));
    return stack;
}

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, Node *item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

Node *pop(Stack *stack) {
    if (isEmpty(stack)) return NULL;
    return stack->array[stack->top--];
}

Node *peek(Stack *stack) {
    return stack->array[stack->top];
}

bool canRepresentBST(int pre[], int n) {
    stack<int> s;
    int root = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre[i] < root) return false;
        while (!s.empty() && s.top() < pre[i]) {
            root = s.top();
            s.pop();
        }
        s.push(pre[i]);
    }
    return true;
}

void printPostorder(Node *node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

Node *post_order(int *, int);

int main() {
    int arr[1000], x, t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        printPostorder(post_order(arr, n));
        cout << endl;
    }
    return 0;
}

class Solution {
public:
    int i = 0;
    Node* bstFromPreorder(int preorder[], int& sz, int ub = INT_MAX) {
        if (i == sz || preorder[i] > ub) return NULL;
        Node* root = newNode(preorder[i++]);
        root->left = bstFromPreorder(preorder, sz, root->data);
        root->right = bstFromPreorder(preorder, sz, ub);
        return root;
    }
};

Node *post_order(int pre[], int sz) {
    Solution obj;
    Node* root = obj.bstFromPreorder(pre, sz);
    return root;
}
