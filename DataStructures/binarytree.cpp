#include <iostream>
using namespace std;

struct bst_node
{
    int data;
    int number;
    bst_node *left;
    bst_node *right;
};

class bst
{

public:
    bst_node *root;

    bst()
    {
    root = NULL;
    }

    ~bst()
    {
    destroy_bst(root);
    }

void destroy_bst(bst_node *leaf)
{
    if (leaf != NULL)
    {
        destroy_bst(leaf->left);
        destroy_bst(leaf->right);
    }
    delete leaf;
}

bool isEmpty()
{
    return (root=NULL);
}

void insert(int item)
{
    if (root != NULL)
    {
        insert(root, item);
    }
    else
    {
        root = new bst_node;
        root->data = item;
        root->left = NULL;
        root->right = NULL;
    }
}

void insert(bst_node *leaf, int item)
{
    if (item < leaf->data)
    {
        if (leaf->left != NULL)
        {
            insert(leaf->left, item);
        }
        else
        {
            leaf->left = new bst_node;
            leaf->left->data = item;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else
    {
        if (leaf->right != NULL)
        {
            insert(leaf->right, item);
        }
        else
        {
            leaf->right = new bst_node;
            leaf->right->data = item;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

bst_node *find(int item)
{
    return find(root, item);
}

bst_node *find(bst_node *leaf, int item)
{
    if (leaf == NULL || leaf->data == item)
        return leaf;
    if (leaf->data < item)
        return find(leaf->right, item);
    return find(leaf->left, item);

}

bool isLeafNode(bst_node *leaf)
{
    if (leaf != NULL && leaf->left == NULL && leaf->right == NULL)
        return true;
    return false;
}

bst_node *findMin(bst_node* leaf)
{
    if (leaf == NULL)
    {
        return leaf;
    }
    else if (leaf->left == NULL)
    {
        return leaf;
    }
    else return findMin(leaf->left);

}

bst_node *remove(int item)
{
    return remove(root, item);
}

bst_node *remove(bst_node *leaf, int item)
{
    bst_node *tmp;
    if (leaf == NULL)
        return NULL;

    if (item < leaf->data)
    {
        leaf->left = remove(leaf->left, item);
    }
    else if (item > leaf->data)
    {
        leaf->right = remove(leaf->right, item);
    }
    else
    {
        if (isLeafNode(leaf))
        {
            delete leaf;
            leaf = NULL;
        }
        else if (leaf->right && leaf->left)
        {
            bst_node *tmp = findMin(leaf->right);
            leaf->data = tmp->data;
            leaf->right = remove(leaf->right, leaf->data);
        }
        else
        {
            tmp = leaf;
            if (leaf->right == NULL)
            {
                leaf = leaf->left;
            }
            else if (leaf->left == NULL)
            {
                leaf = leaf->right;
                delete tmp;
            }
        }
    }
    return leaf;
}

int maxDepth(bst_node* leaf)
{
    if (leaf == NULL)
    {
        return 0;
    }
    else
    {
        int ld = maxDepth(leaf->left);
        int rd = maxDepth(leaf->right);
        return (max(ld, rd) +1);
    }
}

void INorder_traversal(bst_node *root_node)
{
    if (root_node != NULL)
    {
        INorder_traversal(root_node->left);
        cout << root_node->data << endl;
        INorder_traversal(root_node->right);
    }
}

void PREorder_traversal(bst_node *root_node)
{
    if (root_node != NULL)
    {
        cout << root_node->data << endl;
        PREorder_traversal(root_node->left);
        PREorder_traversal(root_node->right);
    }
}

void POSTorder_traversal(bst_node *root_node)
{
    if (root_node != NULL)
    {
        POSTorder_traversal(root_node->left);
        POSTorder_traversal(root_node->right);
        cout << root_node->data << endl;
    }
}
};

int main()
{
    bst my_tree;
    my_tree.insert(10);
    my_tree.insert(9);
    my_tree.insert(6);
    my_tree.insert(5);
    my_tree.insert(7);
    my_tree.insert(4);
    my_tree.insert(2);
    cout << "PRE" << endl;
    my_tree.PREorder_traversal(my_tree.root);
    cout << "IN" << endl;
    my_tree.INorder_traversal(my_tree.root);
    cout << "POST" << endl;
    my_tree.POSTorder_traversal(my_tree.root);
    cout << "Max depth: " << my_tree.maxDepth(my_tree.root) << endl;
    return 0;
}
