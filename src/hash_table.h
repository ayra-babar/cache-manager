/**
* @author H. Hui
* @file hash_table.h
* @brief Header file declaring methods for the HashTable class
*
* 09/23/2024 - Originally created
* 10/17/2024 - Modified by J. Hui
* 01/11/2025 - Modified by H. Hui; 1) Added calculateHashCode, 2) Modified methods to include hash table size parameter
* 01/16/2025 - Modified by H. Hui; Created separate node structure file
* 04/24/2025 - Modified and implemented by Ayra Babar for academic purposes;
*              Other changes: 1) Added destructor declaration, 2) Inserted iostream directive, 3) Created method headers
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "hash_node.h"
#include <iostream>

/**
 * @class HashTable
 * @brief A class representing a hash table using HashNode objects
 *
 * Provides basic and advanced operations such as insertion, deletion, and search of nodes within a hash table structure
 */
class HashTable {
private:
	HashNode** table;
	int numberOfBuckets;
	int numberOfItems;

public:
	// Default constructor
	HashTable();
	~HashTable();
	
	// Constructor initializes an empty hash table
	HashTable(int hashTableSize) : table(nullptr), numberOfBuckets(hashTableSize), numberOfItems(0) {
		table = new HashNode * [hashTableSize];
		std::cout << "hashTableSize: " << hashTableSize << std::endl;
		for (int i = 0; i < hashTableSize; i++) {
			table[i] = nullptr;
		}
	}

/**
*
* Returns the hash table
*
* @return	HashNode**	Pointer to the hash table array
*/
	HashNode** getTable();

/**
*
* Returns the size of the hash table
*
* @return	int		Size of the hash table array
*/
	int getSize();

/**
*
* Calculates the hash code
*
* @param    currentKey     The key used to compute the hash code
*
* @return	int		Hash code for currentKey
*/
	int calculateHashCode(int currentKey);

/**
*
* Checks if HashTable is empty
*
* @return	bool	True if the table has zero entries, false otherwise
*/
	bool isEmpty();

/**
*
* Returns the number of items in the hash table
*
* @return	int		Number of items in the table
*/
	int getNumberOfItems();

/**
*
* Adds a node to the hash table
*
* @param    curKey    Key for this node
* @param    myNode    New node to add to the table
*
* @return	bool	True if successful, false otherwise
*/
	bool add(int curKey, HashNode* myNode);

/**
*
* Removes node with curKey
*
* @param    key     Key of node to remove
*
* @return	bool	True if successful, false otherwise
*/
	bool remove(int curKey);

/**
*
* Removes all entries from the table
*/
	void clear();

/**
*
* Retrieves item from the hash table
*
* @param    curKey  Retrieve node from hash table with curKey value
*
* @return	HashNode*	Pointer to the HashNode
*/
	HashNode* getItem(int curKey);


/**
*
* Verifies if a key is in the hash table
*
* @param    curKey  Check key for hash table with curKey value
*
* @return	bool	True if found, false otherwise
*/
	bool contains(int curKey);

/**
*
* Prints out the contents of table; output is sent to console and to file
*/
	void printTable();

};


#endif	// HASH_TABLE_H
