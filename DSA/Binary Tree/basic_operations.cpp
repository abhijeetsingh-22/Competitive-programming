#include <bits/stdc++.h>
using namespace std;
#define ll long long
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// building tree in preorder traversal
node *build_tree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    node *root = new node(d);
    root->left = build_tree();
    root->right = build_tree();
    return root;
}
void print_preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << ", ";
    print_preorder(root->left);
    print_preorder(root->right);
}
void print_inorder(node *root)
{
    if (root == NULL)
        return;
    print_inorder(root->left);
    cout << root->data << ", ";
    print_inorder(root->right);
}
void print_postorder(node *root)
{
    if (root == NULL)
        return;
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->data << ", ";
}
// max depth (of nodes not edges)
int height(node *root)
{
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}

void print_level(node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 1)
    {
        cout << root->data << ", ";
        return;
    }
    print_level(root->left, k - 1);
    print_level(root->right, k - 1);
}
/*
O(n^2) for worst case if the tree is skewed or in form of a
linked list as for each level we need to travel k nodes to TC will
be 1+2+3+...+n which comes out to be n^2;
*/
void print_levelorder(node *root)
{
    if (root == NULL)
        return;
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        print_level(root, i);
        cout << endl;
    }
}
/*
Very intuitive method using queue
Also known as BFS (Breadth First Search)
1. Push the root node in the queue
2. While the queue is not empty pop the from print it and push its child nodes in the back
3. We can use pair of node and level or NULL for keeping track when to make a new line
*/
void print_levelorder_fast(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *f = q.front();
        q.pop();
        if (f == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << f->data << ", ";
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
    }
}

/*
To find the max distance (edges) between two nodes of the tree
Diameter can lie in left subtree/right subtree/or pass through node
We need to find all three and take the max of this
Time complexity is O(n^2) as for every node the height is calculated
*/
int diameter(node *root)
{
    if (root == NULL)
        return 0;

    // left subtree diameter
    int l = diameter(root->left);
    // right subtree diameter
    int r = diameter(root->right);
    int h1 = height(root->left);
    int h2 = height(root->right);
    // h1+h2 diameter passing through root node of currerent tree
    return max(h1 + h2, max(l, r));
}
class Pair
{
public:
    int height;
    int diameter;
};
Pair diameter_optimezed(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.diameter = 0;
        p.height = 0;
        return p;
    }
    Pair left = diameter_optimezed(root->left);
    Pair right = diameter_optimezed(root->right);

    p.height = max(left.height, right.height) + 1;

    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}

/*
Height balaced binary tree is in which
    |h1-h2|<=1       for all the nodes in the tree;
where h1 and h2 are the heights of left and right subtree
*/
/*
If we use preorder traversal calculate height for each node then the TC-> O(n^2) as height is O(n)
but we can use post order traversal and build height from bottom up
and the time complexity of this will be O(n);
*/
// Returns the values isBalanced and the height
pair<bool, int> is_height_balanced(node *root)
{
    // base case
    if (root == NULL)
        return make_pair(true, 0);
    if (root->left == NULL and root->right == NULL)
    {
        return make_pair(true, 1);
    }
    // Recursive case
    auto left = is_height_balanced(root->left);
    auto right = is_height_balanced(root->right);
    int height = max(left.second, right.second) + 1;
    bool is_balanced = (left.first and right.first) and (abs(left.second - right.second) <= 1);

    return make_pair(is_balanced, height);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    node *root;
    root = build_tree();
    print_levelorder(root);
    print_levelorder_fast(root);
    cout << endl;
    cout << "diameter  " << diameter(root) << endl;

    auto p = is_height_balanced(root);
    if (p.first)
        cout << "The tree is balanced " << p.second << endl;
    else
        cout << "The tree is not balanced " << p.second << endl;
    // Pair p = diameter_optimezed(root);

    // cout << "from optimized diameter function diameter " << p.diameter << " height " << p.height;

    // print_level(root, 4);

    // cout << "preorder" << endl;
    // print_preorder(root);
    // cout << endl
    //      << "inorder" << endl;
    // print_inorder(root);
    // cout << endl
    //      << "postorder" << endl;
    // print_postorder(root);
    // cout << endl
    //      << "height is " << height(root);

    return 0;
}