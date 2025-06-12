/**
* @author H.Hui
* @file hash_node.h
* @brief This is the node struct header file for HashNode, used in hash_table.cpp
*
* 01/16/2025 - Originally created by H. Hui
* 05/08/2025 - Modified and implemented by Ayra Babar for academic purposes
*/

#ifndef HASH_NODE_H
#define HASH_NODE_H

#include "dll_node.h"

/**
* @class HashNode
* @brief Node structure for Hash Table
*
* A HashNode is the basic building block of the hash table. Each node
* stores a key, a hashcode, prev & next pointers pointing to HashNodes,
* and a pointer to the associated FIFO node
*/

class HashNode {
public:	
	int key;                                                            // Value stored in the node
	int hashCode;													    // Hash code based on array size
	HashNode* next;
	HashNode* prev;

	DllNode* fifoNode;													// Pointer to the FIFO node

/**
* @brief Constructor for a HashNode
*
* Initializes a HashNode with the given key & associated FIFO node and sets other class members to default values
*
* @param	myKey		The key value for the node
* @param	myFifoNode	Pointer to the associated FIFO node
*/
	HashNode(int myKey, DllNode* myFifoNode);

/**
*
* @brief Returns the pointer to the associated FIFO node
*
* @return Pointer to the DllNode
*/
	DllNode* getFifoNode();
};


#endif	// HASH_NODE_H
