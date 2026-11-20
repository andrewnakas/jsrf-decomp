// A node of a binary tree, with its children at 0x64 and 0x68.
struct Node_000B9C20 {
    char unknown_00[0x64];
    Node_000B9C20 *left;
    Node_000B9C20 *right;
};

// The node that comes count steps after this one in a depth-first walk (left before right), counting down the
// count; 0 when the walk ends first.
Node_000B9C20 *func_000B9C20(Node_000B9C20 *node, int *count)
{
    if (*count == 0) {
        return node;
    }
    --*count;
    if (node->left) {
        Node_000B9C20 *found = func_000B9C20(node->left, count);
        if (found) {
            return found;
        }
    }
    if (node->right) {
        Node_000B9C20 *found = func_000B9C20(node->right, count);
        if (found) {
            return found;
        }
    }
    return 0;
}
