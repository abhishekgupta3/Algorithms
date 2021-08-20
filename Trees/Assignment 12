/*NAME: ABHISHEK GUPTA 
ROLL NO: 1901EE03
DATE: 12/05/2020
ASSIGNMENT 12
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//node contains three components data, left to store left child address similar right child
typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
} node;

//creates new node using malloc
node *createNode(char data)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->right = 0;
    newNode->left = 0;

    return newNode;
}

//creates the binary tree using inorder and postorder
node *createTree(char in[], char post[], int inSta, int inEnd, int *postEnd)
{
    //when the position reaches to the left of inorder return null
        if (inSta > inEnd) return NULL;

    //creating a node with the last character of postorder and decrementing postorder
        node *Node = createNode(post[*postEnd]);
        (*postEnd)--;

        if (inSta == inEnd) return Node;
    int i; //to find the position of root node
    for (i = inSta; i <= inEnd; i++)
    {
        if (in[i] == Node->data)
            break;
    }
    //recursively calling for left side of the root and the right side of the root
    Node->right = createTree(in, post, i + 1, inEnd, postEnd);

        Node->left = createTree(in, post, inSta, i - 1, postEnd);

        return Node;
}
//finds the depth of the tree
int depth(node *root)
{
    if (root == 0)
        return -1;

    int l = depth(root->left);
    int r = depth(root->right);
    //returns the maximum distance
    if (l > r)
        return (l + 1);
    else
        return (r + 1);
}
//stores the characters in an array

void display(node *node, char arr[])
{

        if (node == NULL) return;
    static int i = 0;
    arr[i++] = node->data;
        display(node->left, arr);
        display(node->right, arr);
}

node *reverse(node *head, int k)
{
    node *current = head;
    node *next = NULL;
    node *prev = NULL;
    int count = 0;

    //     reverse first k nodes of the linked list
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    //     next is now a pointer to (k+1)th node
    //     Recursively call for the list starting from current.
    //     And make rest of the list as next of first node
    if (next != NULL)
        head->next = reverse(next, k);

    //     prev is new head of the input list
    return prev;
}

int main()
{

    FILE *ip;              //input file
    char a[1000], b[1000]; //declaring inorder and postorder array to store the input characters
    ip = fopen("ip.txt", "r");
    if (ip == 0)
    {
        printf("file not found\n"); //when  file doesn't exist
        exit(1);
    }
    fgets(a, 1000, ip);
    //using fgets to store the inorder and postorder in a and b array
    fgets(b, 1000, ip);

    fclose(ip);

    //storing only characters in inorder array from a
    int j = 0;
    char in[100], post[100];
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] >= 65 && a[i] <= 90)
            in[j++] = a[i];
    }
    //storing only characters in postorder array from b
    j = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (b[i] >= 65 && b[i] <= 90)
            post[j++] = b[i];
    }

    int n = strlen(in); //returns length of inorder

    char arr[n]; //array for storing preorder traversal

    int postEnd = n - 1; //points to end of postorder
    //calling create tree function
    node *root = createTree(in, post, 0, n - 1, &postEnd);

    display(root, arr);
    //dep stores the depth of the tree
    int dep = depth(root);

    FILE *op; //outout file
    op = fopen("op.txt", "w");
    //opening output file in write mode
    for (int i = 0; i < n; i++)
        fprintf(op, "%c ", arr[i]);

    fprintf(op, "\n%d", dep);

    fclose(op);

    op = fopen("op.txt", "r");
    //opeing output file in read mode
    char s;
    while ((s = getc(op)) != EOF)
        printf("%c", s);

    fclose(op);
}
