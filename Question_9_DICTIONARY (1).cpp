#include <iostream>
#include <map>
// Node structure for the height-balanced tree
struct Node 
{
    std::string keyword;
    std::string meaning;
    int height;
    Node* left;
    Node* right;
};

// Function to calculate the height of a node
int getHeight(Node* node) 
{
    if (node == nullptr) 
    {
        return -1;
    }
    return node->height;
}

// Function to update the height of a node
void updateHeight(Node* node) 
{
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Function to perform a right rotation
Node* rotateRight(Node* node) 
{
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

// Function to perform a left rotation
Node* rotateLeft(Node* node) 
{
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

// Function to balance the subtree rooted at 'node'
Node* balance(Node* node) 
{
    updateHeight(node);
    if (getHeight(node->left) - getHeight(node->right) > 1) 
    {
        if (getHeight(node->left->left) >= getHeight(node->left->right)) 
        {
            node = rotateRight(node);
        }
        else 
        {
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        }
    } 
    else if (getHeight(node->right) - getHeight(node->left) > 1) 
    {
        if (getHeight(node->right->right) >= getHeight(node->right->left)) 
        {
            node = rotateLeft(node);
        } 
        else 
        {
            node->right = rotateRight(node->right);
            node = rotateLeft(node);
        }
    }
    return node;
}

// Function to insert a new keyword and meaning into the tree
Node* insert(Node* node, const std::string& keyword, const std::string& meaning) 
{
    if (node == nullptr) 
    {
        Node* newNode = new Node;
        newNode->keyword = keyword;
        newNode->meaning = meaning;
        newNode->height = 0;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    if (keyword < node->keyword) 
    {
        node->left = insert(node->left, keyword, meaning);
    } 
    else if (keyword > node->keyword) 
    {
        node->right = insert(node->right, keyword, meaning);
    } 
    else 
    {
        // Keyword already exists, update the meaning
        node->meaning = meaning;
        return node;
    }
    return balance(node);
}

// Function to delete a keyword from the tree
Node* remove(Node* node, const std::string& keyword) 
{
    if (node == nullptr) 
    {
        return nullptr;
    }
    if (keyword < node->keyword) 
    {
        node->left = remove(node->left, keyword);
    } 
    else if (keyword > node->keyword) 
    {
        node->right = remove(node->right, keyword);
    } 
    else 
    {
        if (node->left == nullptr && node->right == nullptr) 
        {
            delete node;
            return nullptr;
        } 
        else if (node->left == nullptr) 
        {
            Node* rightChild = node->right;
            delete node;
            return rightChild;
        } 
        else if (node->right == nullptr) 
        {
            // right == nullptr) {
            Node* leftChild = node->left;
            delete node;
            return leftChild;
        } 
        else 
        {
            // Node has two children, find the successor
            Node* successor = node->right;
            while (successor->left != nullptr) 
            {
                successor = successor->left;
            }
            node->keyword = successor->keyword;
            node->meaning = successor->meaning;
            node->right = remove(node->right, successor->keyword);
         }
    }
    return balance(node);
}

// Function to update the meaning of a keyword
Node* update(Node* node, const std::string& keyword, const std::string& meaning) 
{
    if (node == nullptr) 
    {
        return nullptr;
    }
    if (keyword < node->keyword) 
    {
        node->left = update(node->left, keyword, meaning);
    } 
    else if (keyword > node->keyword) 
    {
        node->right = update(node->right, keyword, meaning);
    } 
    else 
    {
        // Keyword found, update the meaning
        node->meaning = meaning;
    }
    return node;
}

// Function to display the data in ascending order
void displayAscending(Node* node) 
{
    if (node == nullptr) 
    {
        return;
    }
    displayAscending(node->left);
    std::cout << node->keyword << ": " << node->meaning << std::endl;
    displayAscending(node->right);
}

// Function to display the data in descending order
void displayDescending(Node* node) 
{
    if (node == nullptr) 
    {
        return;
    }
    displayDescending(node->right);
    std::cout << node->keyword << ": " << node->meaning << std::endl;
    displayDescending(node->left);
}

// Function to find the maximum number of comparisons required to find a keyword
int findMaxComparisons(Node* node, const std::string& keyword, int comparisons) 
{
    if (node == nullptr) 
    {
        return comparisons;
    }
    if (keyword == node->keyword) 
    {
        return comparisons + 1;
    } 
    else if (keyword < node->keyword) 
    {
        return findMaxComparisons(node->left, keyword, comparisons + 1);
    } 
    else 
    {
        return findMaxComparisons(node->right, keyword, comparisons + 1);
    }
}

int main() 
{
    Node* root = nullptr;
    // Add new keywords
    root = insert(root, "apple", "A fruit");
    root = insert(root, "banana", "A tropical fruit");
    root = insert(root, "carrot", "A vegetable");
    // Update the meaning of a keyword
    root = update(root, "apple", "A delicious fruit");
    // Display the data in ascending order
    std::cout << "Data in ascending order:" << std::endl;
    displayAscending(root);
    // Display the data in descending order
    std::cout << "Data in descending order:" << std::endl;
    displayDescending(root);
    // Find the maximum number of comparisons required to find a keyword
    std::string keyword = "carrot";
    int maxComparisons = findMaxComparisons(root, keyword, 0);
    std::cout << "Maximum comparisons required to find \"" << keyword << "\": " << maxComparisons
    << std::endl;
    // Delete a keyword
    root = remove(root, "banana");
    // Display the updated data in ascending order
    std::cout << "Updated data in ascending order:" << std::endl;
    displayAscending(root);
    // Find the maximum number of comparisons required to find a
    // keyword
    keyword = "carrot";
    maxComparisons = findMaxComparisons(root, keyword, 0);
    std::cout << "Maximum comparisons required to find \"" << keyword << "\": " << maxComparisons
    << std::endl;
    // Clean up the memory
    // ...

    return 0;
}