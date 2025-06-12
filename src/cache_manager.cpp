/**
* @author Ayra Babar
* @file cache_manager.cpp
* @brief * @brief Implementation of a cache manager using a hash table, doubly linked list, and binary search tree
*
* 02/24/2025 - Initial creation & method header comments added
* 02/27/2025 - The following methods were implemented: getTable, getList, getSize,
*              isEmpty, and getMaxCacheSize
* 03/03/2025 - The following methods were implemented: add, remove, contains, clear, getItem
* 04/15/2025 - Made changes to add() function according to the teacher's feedback for test case 4
* 04/24/2025 - Implemented & added method header comments to: getBst
* 05/01/2025 - Updated methods to include manipulations with BST (add, remove, clear) & implemented + added
			   method headers to printSort & printRange
*/

#include "cache_manager.h"
#include <iostream>
#include <fstream>
using namespace std;
extern ofstream& getOutFile();


/**
*
* Returns the hash table
*
* @return	HashTable*	Pointer to the hash table
*/
HashTable* CacheManager::getTable() {
	return hashTable;
}


/**
*
* Returns the FIFO list
*
* @return	DoublyLinkedList*	Pointer to the FIFO list
*/
DoublyLinkedList* CacheManager::getList() {
	return doublyLinkedList;
}


/**
*
* Returns the BST
*
* @return	BinarySearchTree*	Pointer to the BST
*/
	BinarySearchTree* CacheManager::getBst() {
		return binarySearchTree;
	}


/**
*
* Returns the number of items in the CacheManager
*
* @return	int		Number of items in the CacheManager
*/
int CacheManager::getSize() {
	return (doublyLinkedList->getSize());
}


/**
*
* Checks if CacheManager is empty
*
* @return   bool	True if the CacheManager has zero entries, false otherwise
*/
bool CacheManager::isEmpty() {
	return (getSize() == 0);
}


/**
*
* Adds a node to the CacheManager
*
* @param    curKey    Key for this node
* @param    myNode    New node to add to the table
*
* @return   bool	true if success, false otherwise
*/
bool CacheManager::add(int curKey, DllNode* myNode) {

    if (getTable()->contains(curKey)) {
        getList()->remove(curKey);
        getTable()->remove(curKey);
    }

    while (getList()->getSize() >= getMaxCacheSize()) {
        if (getList()->tail != nullptr) {
        	int keytoDelete = getList()->tail->key;
            getTable()->remove(keytoDelete);
            getBst()->removeNode(keytoDelete);
            getList()->removeTailNode();
        }
    }

    HashNode* newNode = new HashNode(curKey, myNode);
    bool tableSuccessful = getTable()->add(curKey, newNode);
    getBst()->addToTree(curKey, myNode);

    if (tableSuccessful) {
        getList()->insertAtHead(curKey, myNode);
    }

    return tableSuccessful;
}


/**
*
* Removes node with curKey
*
* @param    curKey     Key of node to remove
*
* @return   bool	True if success, false otherwise
*/
bool CacheManager::remove(int curKey) {

	if(isEmpty()) {
		return false;
	}

	int oldSize = getList()->getSize();
	getList()->remove(curKey);

	bool tableSuccessful = getTable()->remove(curKey);

	bool treeSuccessful = getBst()->removeNode(curKey);

	return (tableSuccessful && treeSuccessful && (oldSize > (getList()->getSize())));
}


/**
*
* Removes all entries from the CacheManager
*
*/
void CacheManager::clear() {

	if(isEmpty()) {
		return;
	}

	getList()->clear();
	getTable()->clear();
	getBst()->clear();

}


/**
*
* Retrieves item from the CacheManager
*
* @param    curKey  retrieve node from CacheManager with curKey value
*
* @return   DllNode*	Pointer to the DllNode
*/
DllNode* CacheManager::getItem(int curKey) {

	if(isEmpty()) {
		return nullptr;
	}

	DllNode* current = getList()->head;
	while(current != nullptr) {
		if(current->key == curKey){
			getList()->moveNodeToHead(curKey);
			return current;
		}
		current = current->next;
	}

	return nullptr;
}


/**
*
* Retrieves max size of cache from the CacheManager
*
* @return   int	max size of cache manager
*/
int CacheManager::getMaxCacheSize() {
	return maxCacheSize;
}


/**
*
* Determines if a key value is in the cache
*
* @param    curKey  Retrieve node from cacheManager with curKey value
*
* @return   bool	True if exists, false otherwise
*/
bool CacheManager::contains(int curKey) {

	if(isEmpty()) {
		return false;
	}

	if(getTable()->contains(curKey)) {
		getList()->moveNodeToHead(curKey);
		return true;
	}

	return false;
}


/**
*
* Prints out the cache information
*
*/
void CacheManager::printCache() {

	ofstream& outFile = getOutFile();

	cout<< endl << "Printing out the cache contents" << endl << endl;
	outFile << endl << "Printing out the cache contents" << endl << endl;

	cout << "Here are the FIFO List contents:" << endl;
	getList()->printList();
	cout << "End of FIFO List" << endl << endl;

	cout << "Here are the Hash Table contents (" << getSize()<< " entries):" << endl;
	outFile << "Here are the Hash Table contents (" << getSize()<< " entries):" << endl;
	getTable()->printTable();
	cout << endl;
	outFile << endl;

	getBst()->printInOrder();
	cout << endl;
	getBst()->printReverseOrder();
	cout << endl << "End of cache contents" << endl << endl;
	outFile << endl << "End of cache contents" << endl << endl;

}


/**
*
* Traverses and prints out the cache information given a low and high value.
*
* @param    low			The lower bound (inclusive) of the range to print
* @param	high		The higher bound (inclusive) of the range to print
*/
void CacheManager::printRange(int low, int high) {
	getBst()->printRange(low, high);
}


/**
*
* Prints out the cache information in sorted order
*
* @param    ascending	True if output is to be in ascending order, false for descending order
*/
void CacheManager::printSort(bool ascending) {

	ofstream& outFile = getOutFile();
	cout << endl;
	outFile << endl;
	if(ascending) {
		getBst()->printInOrder();
	} else {
		getBst()->printReverseOrder();
	}
}
