/**
* @author H. Hui
* @file tree_node.h
* @brief Declaration of the TreeNode structure used for Binary Search Tree
*
* 01/14/2025 - H. Hui created file and added comments.
* 01/15/2025 - Modified by H. Hui; modified remove methods; added comments
* 02/01/2025 - H. Hui added doxygen formatted comments
* 05/08/2025 - Modified and implemented by Ayra Babar for academic purposes
* 
* This header file defines the TreeNode structure which is used in the
* construction of a binary tree. Each TreeNode contains a key, the number of
* nodes in its subtree, the height of the node, and pointers to its left and
* right children
*/

#ifndef TREENODE_H
#define TREENODE_H

#include "dll_node.h"

/**
* @struct TreeNode
* @brief Represents a node in a binary tree
*
* A TreeNode is the basic building block of the binary search tree. Each node
* stores a key, the number of nodes in its subtree, its height in the tree,
* and pointers to its left and right child nodes
*/

struct TreeNode {
    int key;                // Key for the tree node
    int numberOfNodes;      // Total nodes in the subtree rooted at this node
    int height;             // Height of the node in the tree
    TreeNode* left;         // Pointer to the left child
    TreeNode* right;        // Pointer to the right child
    DllNode* fifoNode;      // Pointer to the FIFO node (DllNode)


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
    TreeNode(int k = 0, int numNodes = 1, int h = 0, TreeNode* l = nullptr, TreeNode* r = nullptr, DllNode* f = nullptr);


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

    TreeNode(int k, DllNode* fifoNode);
};

#endif // TREENODE_H
