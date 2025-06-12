/**
* @author Ayra Babar
* @file binary_search_tree.cpp
* @brief Implementation of a binary search tree
*
* 03/17/2025 - Initial creation & method header comments added & getRoot, isEmpty,
*			   printInOrder, printPostOrder, printPreOrder, clear &
*			   printPreOrderHelper, printPostOrderHelper, printInOrderHelper,
*			   getHeightOfTree, getHeight, destructor, & constructor implemented
* 03/19/2025 - addToTree, getNumberOfTreeNodes, contains, & removeNode implemented
* 03/20/2025 - printBreadthFirst, printDepthFirst, clear, deleteTree, printNodeFromTree & implemented
* 04/10/2025 - Updated printNodeFromTree
* 04/24/2025 - Following methods & their comment headers added: printReverseOrder, printRange,
*			   printReverseOrderHelper, printRangeHelper
* 05/01/2025 - Following methods were implemented: printReverseOrder, printRange, printReverseOrderHelper,
			   printRangeHelper
*/

#include "binary_search_tree.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
using namespace std;
extern ofstream& getOutFile();


/**
*
* @brief Default constructor for BinarySearchTree
*
* Initializes an empty binary search tree
*/
BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}


/**
*
* @brief Destructor for BinarySearchTree
*
* Frees the dynamically allocated memory by deleting all nodes in the tree
*/
BinarySearchTree::~BinarySearchTree() {
	clear();
}

/**
*
* @brief Adds a node with the specified key to the tree
*
* @param	key		The key to be added to the tree
* @param	dllNode	The DllNode used to create new TreeNode
*/
void BinarySearchTree::addToTree(int key, DllNode* dllNode) {

	TreeNode* newNode = new TreeNode(key, dllNode);
	if(root == nullptr) {
		root = newNode;
		return;
	}

	TreeNode *current = root;
	TreeNode *parent = nullptr;

	while (current != nullptr) {
		parent = current;

		if(key < current->key) {
			current = current->left;

		} else if (key > current->key) {
			current = current->right;

		} else {
			return;
		}
	}

	if (parent->key < key) {
		parent->right = newNode;
	} else {
		parent->left = newNode;
	}
}


/**
*
* @brief Removes a node with the specified key from the tree
*
* @param	key		The key of the node to remove.
* @return	bool	True if the node was removed, false if the key wasn't found
*/
bool BinarySearchTree::removeNode(int key) {

	if(root == nullptr || !contains(key)) {
		return false;
	}

	TreeNode *current = root;
	TreeNode *parent = nullptr;

	while (current != nullptr) {
		if (key == current->key) {
			break;

		} else if(key < current->key) {
			parent = current;
			current = current->left;

		} else {
			parent = current;
			current = current->right;
		}
	}

	// Case 1: If the node to delete is a leaf node
	if ((current->right == nullptr) && (current ->left == nullptr)) {
		if (current == root) {
			delete root;
			root = nullptr;
			return true;
		}
		if(parent->right == current) {
			parent->right = nullptr;
		} else {
			parent->left = nullptr;
		}

		delete current;
		current = nullptr;
		return true;
	}

	// Case 2: If the node to delete has one child
	if((current->right == nullptr) || (current ->left == nullptr)) {

		TreeNode *child = (current->left == nullptr) ? current->right : current->left;

		if(current == root) {
			root = child;
		} else if (parent->right == current) {
			parent->right = child;
		} else {
			parent->left = child;
		}

		delete current;
		current = nullptr;
		return true;
	}

	// Case 3: If the node to delete has two children
	TreeNode *parentOfSuccessor = current;
	TreeNode *successor = current->right;

	while(successor->left != nullptr) {
		parentOfSuccessor = successor;
		successor = successor->left;
	}

	current->key = successor->key;
	current->fifoNode = successor->fifoNode;

	if(successor->right == nullptr) {		// Checks if successor has no children
		if(successor != current->right) {
			parentOfSuccessor->left = nullptr;
		}

	} else if (successor == current->right) {		// if the successor is current's right node
		current->right = successor->right;

	} else {
		parentOfSuccessor->left = successor->right;		// if the successor has a right child
	}

	delete successor;
	successor = nullptr;
	return true;
}


/**
*
* @brief Gets the height of the tree
*
* The height of the tree is defined as the length of the longest path from
* the root to a leaf node
*
* @return	int		The height of the tree.
*/
int BinarySearchTree::getHeightOfTree() const {

	return getHeight(root);

}

namespace {
	int countNodes(TreeNode* node);
}

/**
*
* @brief Gets the number of nodes in the tree
*
* @return	int		The number of nodes in the tree
*/
int BinarySearchTree::getNumberOfTreeNodes() const {

	if (isEmpty()) {
		return 0;
	}

	return countNodes(root);
}


/**
*
* @brief Checks if the tree contains a node with the specified key
*
* @param	key		The key to search for in the tree
* @return	bool	True if the key exists in the tree, false otherwise
*/
bool BinarySearchTree::contains(int key) const {

	if(isEmpty()) {
		return false;
	}

	TreeNode *current = root;
	while (current != nullptr) {

		if (key == current->key) {
			return true;

		} else if(key < current->key) {
			current = current->left;

		} else {
			current = current->right;
		}
	}

	return false;
}

/**
*
* @brief Gets the root node of the tree
*
* @return	TreeNode*	Pointer to the root node of the tree
*/
TreeNode* BinarySearchTree::getRoot() const {
	return root;
}


/**
*
* @brief Checks if the tree is empty
*
* @return	bool	True if the tree is empty, false otherwise
*/
bool BinarySearchTree::isEmpty() const {
	return (getRoot() == nullptr);
}


/**
*
* @brief Clears the entire tree
*
* Deletes all the nodes in the tree, freeing up memory
*/
void BinarySearchTree::clear() {

	deleteTree(root);
	root = nullptr;
}


/**
*
* @brief Prints the data of a specific node
*
* This function prints the key, number of nodes in the subtree, and height of the given node
*
* @param	node	Pointer to the node whose data is to be printed
*/
void BinarySearchTree::printNodeFromTree(TreeNode* node) const {

	 if (node == nullptr || isEmpty() || !contains(node->key)) {
	     return;
	 }

	int heightAtNode = getHeight(node);

	if(node == root) {
		heightAtNode = 1;
	}

	TreeNode *current = root;
	while (current != nullptr) {

		if (node->key == current->key) {
			cout << "Node Key: " << node->key << endl;
			cout << "Height of Tree at this Node is: " << heightAtNode << endl;
			cout << "Count of Tree Nodes: " << countNodes(node) << endl;
			break;
		} else if(node->key < current->key) {
			current = current->left;

		} else {
			current = current->right;
		}
	}
}


/**
*
* @brief Performs an in-order traversal of the tree and prints the nodes
*
* In-order traversal visits the left subtree, the node, and then the right subtree
*/
void BinarySearchTree::printInOrder() const {

	ofstream& outFile = getOutFile();
	cout << "Performing In-Order Traversal" << endl;
	outFile << "Performing In-Order Traversal" << endl;
	printInOrderHelper(root);
	cout << "End of binary search tree" << endl << endl;
	outFile << "End of binary search tree" << endl << endl;
}


/**
*
* @brief Performs an reverse traversal of the tree and prints the nodes
*
* Reverse traversal visits the right subtree, the node, and then the left subtree
*/
void BinarySearchTree::printReverseOrder() const {

	ofstream& outFile = getOutFile();
	cout << "Performing Reverse Order Traversal" << endl;
	outFile << "Performing Reverse Order Traversal" << endl;
	printReverseOrderHelper(root);
	cout << "End of binary search tree" << endl << endl;
	outFile << "End of binary search tree" << endl << endl;
}


/**
*
* @brief Performs a pre-order traversal of the tree and prints the nodes
*
* Pre-order traversal visits the node, the left subtree, and then the right subtree
*/
void BinarySearchTree::printPreOrder() const {

	ofstream& outFile = getOutFile();
	cout << "Performing Pre-Order Traversal" << endl;
	outFile << "Performing Pre-Order Traversal" << endl;
	printPreOrderHelper(root);
	cout << endl;
	outFile << endl;
}


/**
*
* @brief Performs a post-order traversal of the tree and prints the nodes
*
* Post-order traversal visits the left subtree, the right subtree, and then the node
*/
void BinarySearchTree::printPostOrder() const {

	ofstream& outFile = getOutFile();
	cout << "Performing Post-Order Traversal" << endl;
	outFile << "Performing Post-Order Traversal" << endl;
	printPostOrderHelper(root);
	cout << endl;
}


/**
*
* @brief Performs a depth-first traversal (same as pre-order traversal) and prints the nodes
*
* Depth-first traversal visits the node first, then the left subtree, and then the right subtree
*/
void BinarySearchTree::printDepthFirst() const {

	ofstream& outFile = getOutFile();
	cout << "Performing Depth First via PreOrder Traversal" << endl;
	outFile << "Performing Depth First via PreOrder Traversal" << endl;
	printPreOrder();
}


/**
*
* @brief Performs a breadth-first traversal of the tree and prints the nodes
*
* Breadth-first traversal visits nodes level by level, from left to right
*/
void BinarySearchTree::printBreadthFirst() const {

	ofstream& outFile = getOutFile();
	cout << "Performing Breadth First Traversal" << endl;
	outFile << "Performing Breadth First Traversal" << endl;

    if (isEmpty()) {
        return;
    }

    queue<TreeNode*> queueBST;
    queueBST.push(root);

    while (!queueBST.empty()) {
        TreeNode* current = queueBST.front();
        queueBST.pop();

        cout << current->key << endl;
        outFile << current->key << endl;

        if (current->left) {
        	queueBST.push(current->left);
        }
        if (current->right) {
        	queueBST.push(current->right);
        }
    }
}


/**
*
* Traverses and prints out the cache information given a low and high value
*
* @param    low			The lower bound (inclusive) of the range to print
* @param	high		The higher bound (inclusive) of the range to print
*/
void BinarySearchTree::printRange(int low, int high) {

	ofstream& outFile = getOutFile();
	cout << "Printing Range from " << low << " to " << high << endl;
	outFile << "Printing Range from " << low << " to " << high << endl;
	printRangeHelper(root, low, high);
}


/**
*
* @brief Deletes the tree starting from the specified node
*
* Recursively deletes all nodes in the tree
*
* @param	node	The starting node to begin deleting the tree
*/
void BinarySearchTree::deleteTree(TreeNode* node) {

	if(node == nullptr) {
		return;
	}

	stack<TreeNode*> stackBST;
	TreeNode *current = node;
	stackBST.push(current);

	while(!stackBST.empty()) {

		current = stackBST.top();
		stackBST.pop();

		if(current->right) {
			stackBST.push(current->right);
		}

		if(current->left) {
			stackBST.push(current->left);
		}

		delete current;
		current = nullptr;
	}
}


/**
*
* @brief Helper function to calculate the height of a node
*
* This function is used by `getHeightOfTree` to calculate the height of the tree
*
* @param 	node 	Pointer to the node whose height is to be calculated
* @return	int		The height of the given node
*/
int BinarySearchTree::getHeight(TreeNode* node) const {

	if(node == nullptr || !contains(node->key)) {
		return 0;
	}

	int lDepth = getHeight(node->left);
	int rDepth = getHeight(node->right);
	return max(lDepth, rDepth) + 1;

}


/**
*
* @brief Helper function for recursive in-order traversal
*
* This function is called recursively to perform an in-order traversal starting from the given node
*
* @param	node	Pointer to the node from which to begin the in-order traversal
*/
void BinarySearchTree::printInOrderHelper(TreeNode* node) const {

	if(node == nullptr) {
		return;
	}

	ofstream& outFile = getOutFile();
	printInOrderHelper(node->left);
	cout << "Node Key: " << node->key << endl;
	outFile << "Node Key: " << node->key << endl;
	printInOrderHelper(node->right);
}


/**
*
* @brief Helper function for recursive reverse traversal
*
* * This function is called recursively to perform a reverse in-order traversal from the given node
*
* @param node A pointer to the node from which to begin the in-order traversal
*/
void BinarySearchTree::printReverseOrderHelper(TreeNode* node) const {

	if(node == nullptr) {
		return;
	}

	ofstream& outFile = getOutFile();
	printReverseOrderHelper(node->right);
	cout << "Node Key: " << node->key << endl;
	outFile << "Node Key: " << node->key << endl;
	printReverseOrderHelper(node->left);
}


/**
*
* @brief Helper function for recursive pre-order traversal
*
* This function is called recursively to perform a pre-order traversal starting from the given node
*
* @param	node	Pointer to the node from which to begin the pre-order traversal
*/
void BinarySearchTree::printPreOrderHelper(TreeNode* node) const {

	if(node == nullptr) {
		return;
	}

	ofstream& outFile = getOutFile();
	cout << "Node Key: " << node->key << endl;
	outFile << "Node Key: " << node->key << endl;
	printPreOrderHelper(node->left);
	printPreOrderHelper(node->right);
}


/**
*
* @brief Helper function for recursive post-order traversal
*
* This function is called recursively to perform a post-order traversal starting from the given node
*
* @param	node	Pointer to the node from which to begin the post-order traversal
*/
void BinarySearchTree::printPostOrderHelper(TreeNode* node) const {

	if(node == nullptr) {
		return;
	}

	ofstream& outFile = getOutFile();
	printPostOrderHelper(node->left);
	printPostOrderHelper(node->right);
	cout << "Node Key: " << node->key << endl;
	outFile << "Node Key: " << node->key << endl;
}


/**
*
* Method to traverse and print out the cache information given a low and high value
*
* @param    low			The lower bound (inclusive) of the range to print
* @param	high		The higher bound (inclusive) of the range to print
*/
void BinarySearchTree::printRangeHelper(TreeNode* node, int low, int high) {

	if(node == nullptr) {
		return;
	}

	ofstream& outFile = getOutFile();

	if(low < node->key) printRangeHelper(node->left, low, high);
	if (node->key >= low && node->key <= high) {
		cout << "Node Key: " << node->key << endl;
		outFile << "Node Key: " << node->key << endl;
	}
	if(high > node->key) printRangeHelper(node->right, low, high);
}


namespace {
	int countNodes(TreeNode* node) {

		if(node == nullptr) {
			return 0;
		}
		return 1 + (countNodes(node->left)) + countNodes(node->right);
	}
}
