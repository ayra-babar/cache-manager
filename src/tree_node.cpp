/**
* @author H. Hui
* @file tree_node.cpp
* @brief Constructor implementations for the TreeNode class
*
* 01/14/2025 - H. Hui created file and added comments
* 01/15/2025 - Modified by H. Hui; modified remove methods; added comments
* 02/01/2025 - H. Hui added doxygen formatted comments
* 05/08/2025 - Modified and implemented by Ayra Babar for academic purposes
*/

#include "tree_node.h"

/**
*
* @brief Constructor for TreeNode with key and FIFO node
*
* Initializes a TreeNode with the given key and FIFO node, while all other
* members are set to default values
*
* @param	k			The key of the node
* @param	fifoNode	Pointer to the associated FIFO node (DllNode)
*/

TreeNode::TreeNode(int k, DllNode* f) {
    key = k;
    numberOfNodes = 0;
    height = 0;
    left = nullptr;
    right = nullptr;
    fifoNode = f;
}

/**
* @brief Constructor for TreeNode
*
* This constructor initializes a TreeNode with the specified key, number
* of nodes, height, and pointers to the left and right children. If no
* values are provided, it initializes the node with default values.
*
* @param	k			The key of the node (default is 0).
* @param	numNodes	The number of nodes in the subtree (default is 1).
* @param	h			The height of the node (default is 0).
* @param	l			Pointer to the left child (default is nullptr).
* @param	r			Pointer to the right child (default is nullptr).
*/

TreeNode::TreeNode(int k, int numNodes, int h, TreeNode* l, TreeNode* r, DllNode* f)
    : key(k), numberOfNodes(numNodes), height(h), left(l), right(r), fifoNode(f) {}
