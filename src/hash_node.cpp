/**
* @author H. Hui
* @file hash_node.cpp
* @brief This is the implemented node struct source file for HashNode, used in hash_table.cpp
*
* 01/16/2025 - Originally created by H. Hui
* 05/08/2025 - Modified and implemented by Ayra Babar for academic purposes
*/

#include "dll_node.h"
#include "hash_node.h"

/**
* @brief Constructor for a HashNode
*
* Initializes a HashNode with the given key & associated FIFO node and sets other class members to default values
*
* @param	myKey		The key value for the node
* @param	myFifoNode	Pointer to the associated FIFO node
*/

HashNode::HashNode(int myKeyValue, DllNode* myDllNode) : key(myKeyValue), hashCode(-1), next(nullptr), prev(nullptr), fifoNode(myDllNode) {}


/**
*
* @brief Returns the FIFO node associated with this HashNode
*
* @return Pointer to the DllNode
*/
DllNode* HashNode::getFifoNode() {
	return fifoNode;
}
