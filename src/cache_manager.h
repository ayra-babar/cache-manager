/**
* @author J. Hui
* @file cache_manager.h
* @brief Header file declaring the CacheManager class for managing a cache system using a hash table, doubly linked list, and binary search tree
*
* 09/23/2024 - Originally created
* 10/17/2024 - Modified by J. Hui
* 01/11/2025 - Modified by H. Hui; 1) Added calculateHashCode, 2) Modified methods to include hash table size parameter
* 01/16/2025 - Modified by H. Hui; Created separate node structure file
* 01/27/2025 - Modified by H. Hui; Added getMaxCacheSize
* 05/08/2025 - Modified and implemented by Ayra Babar for academic purposes
*/

#ifndef CACHE_MANAGER_H
#define CACHE_MANAGER_H

#include "hash_table.h"
#include "doubly_linked_list.h"
#include "binary_search_tree.h"


/**
 * @class CacheManager
 * @brief A class representing a Cache Manager with the combination of doubly linked list, hash table, and binary search tree
 *
 * This class provides methods to manipulate and traverse a cache manager using a hash table for quick lookups, a doubly linked
 * list for FIFO ordering, and a binary search tree for sorted access and range queries
 */
class CacheManager {
private:
	HashTable* hashTable;
	DoublyLinkedList* doublyLinkedList;
	BinarySearchTree* binarySearchTree;

	int maxCacheSize;

public:

/**
* @brief Constructor initializes the cache with the given max size and hash table size
*
* If the hash table size exceeds the max cache size, the max cache size is reset to match the hash table size
*
* @param	myMaxCacheSize	The intended maximum size of the cache
* @param	myHashTableSize	The size of the hash table
*/
	CacheManager(int myMaxCacheSize, int myHashTableSize) {
		if (myHashTableSize > myMaxCacheSize) {
			myMaxCacheSize = myHashTableSize;
		}

		hashTable = new HashTable(myHashTableSize);
		doublyLinkedList = new DoublyLinkedList();
		binarySearchTree = new BinarySearchTree();

		maxCacheSize = myHashTableSize;
	}

/**
* @brief Destructor deallocates memory used by the cache
*/
	~CacheManager() {
		delete hashTable;
		delete doublyLinkedList;
		delete binarySearchTree;
	}


/**
*
* Returns the hash table
*
* @return	HashTable*	Pointer to the hash table
*/
	HashTable* getTable();

/**
*
* Returns the FIFO list
*
* @return	DoublyLinkedList*	Pointer to the FIFO list
*/
	DoublyLinkedList* getList();

/**
*
* Returns the BST
*
* @return	BinarySearchTree*	Pointer to the BST
*/
	BinarySearchTree* getBst();

/**
*
* Returns the number of items in the CacheManager
*
* @return	int		Number of items in the CacheManager
*/
	int getSize();


/**
*
* Checks if CacheManager is empty
*
* @return   bool	True if the CacheManager has zero entries, false otherwise
*/
	bool isEmpty();


/**
*
* Adds a node to the CacheManager
*
* @param    curKey    Key for this node
* @param    myNode    New node to add to the table
*
* @return   bool	true if success, false otherwise
*/
	bool add(int curKey, DllNode* myNode);

/**
*
* Removes node with curKey
*
* @param    curKey     Key of node to remove
*
* @return   bool	True if success, false otherwise
*/
	bool remove(int curKey);

/**
*
* Removes all entries from the CacheManager
*
*/
	void clear();

/**
*
* Retrieves item from the CacheManager
*
* @param    curKey  retrieve node from CacheManager with curKey value
*
* @return   DllNode*	Pointer to the DllNode
*/
	DllNode* getItem(int curKey);

/**
*
* Retrieves max size of cache from the CacheManager
*
* @return   int	max size of cache manager
*/
	int getMaxCacheSize();

/**
*
* Determines if a key value is in the cache
*
* @param    curKey  Retrieve node from cacheManager with curKey value
*
* @return   bool	True if exists, false otherwise
*/
	bool contains(int curKey);


/**
*
* Prints out the cache information
*
*/
	void printCache();


/**
*
* Traverses and prints out the cache information given a low and high value.
*
* @param    low			The lower bound (inclusive) of the range to print
* @param	high		The higher bound (inclusive) of the range to print
*/
	void printRange(int low, int high);


/**
*
* Prints out the cache information in sorted order
*
* @param    ascending	True if output is to be in ascending order, false for descending order
*/
	void printSort(bool ascending);

};


#endif	// CACHE_MANAGER_H
