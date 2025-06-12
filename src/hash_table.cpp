/**
* @author Ayra Babar
* @file hash_table.cpp
* @brief This file contains the implementation of the a hash table
*
* 02/10/2025 - Initial creation & implementation of the first 6 methods
* 02/20/2025 - Method header comments added & implementation of last 5 methods
* 02/27/2025 - printTable method was added
*/

#include "hash_table.h"
#include "hash_node.h"
#include <iostream>
#include <fstream>
using namespace std;
extern ofstream& getOutFile();


// Destructor defined
HashTable::~HashTable() {
	clear();
}


/**
*
* Returns the hash table
*
* @return	HashNode**	Pointer to the hash table array
*/
HashNode** HashTable::getTable() {
	return table;
}


/**
*
* Returns the size of the hash table
*
* @return	int		Size of the hash table array
*/
int HashTable::getSize(){
	return numberOfBuckets;
}


/**
*
* Calculates the hash code
*
* @param    currentKey     The key used to compute the hash code
*
* @return	int		Hash code for currentKey
*/
int HashTable::calculateHashCode(int currentKey){
	return ((currentKey) % numberOfBuckets);
}


/**
*
* Checks if HashTable is empty
*
* @return	bool	True if the table has zero entries, false otherwise
*/
bool HashTable::isEmpty(){
	return (numberOfItems == 0);
}


/**
*
* Returns the number of items in the hash table
*
* @return	int		Number of items in the table
*/
int HashTable::getNumberOfItems(){
	return numberOfItems;
}


/**
*
* Adds a node to the hash table
*
* @param    curKey    Key for this node
* @param    myNode    New node to add to the table
*
* @return	bool	True if successful, false otherwise
*/
bool HashTable::add(int curKey, HashNode* myNode){

	// Compute hash code for curKey
	int hashCode = calculateHashCode(curKey);

	// Check if the value is already in the hash table
	if(contains(curKey)) {
		return true;
	}

	if(table[hashCode] == nullptr) {
		table[hashCode] = myNode;
		myNode->next = nullptr;
		myNode->prev = nullptr;

	} else {

		// Adding new node at the head of our doubly linked list
		HashNode* current = table[hashCode];
		myNode->next = current;
		myNode->prev = nullptr;
		current->prev = myNode;
		table[hashCode] = myNode;

	}
	numberOfItems++;
	return true;
}


/**
*
* Removes node with curKey
*
* @param    key     Key of node to remove
*
* @return	bool	True if successful, false otherwise
*/
bool HashTable::remove(int curKey) {

    // Compute hash code for the key
    int hashCode = calculateHashCode(curKey);

    HashNode* current = table[hashCode];

    while (current != nullptr) {

        if (current->key == curKey) {

            // If the node to delete is the head of the chain
            if (current == table[hashCode]) {
                table[hashCode] = current->next;

                if (table[hashCode] != nullptr) {
                    table[hashCode]->prev = nullptr;
                }

            } else {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
            }

            numberOfItems--;
            delete current;
            current = nullptr;
            return true;
        }

        current = current->next;
    }

    return false;
}


/**
*
* Removes all entries from the table
*/
void HashTable::clear(){

	if(isEmpty()) {
		return;
	}

	for(int i = 0; i < numberOfBuckets; i++) {

		HashNode *current = table[i];

		while(current != nullptr) {
			HashNode *nextNode = current->next;
			delete current;
			current = nextNode;
		}
		table[i] = nullptr;
	}

	numberOfItems = 0;
}


/**
*
* Retrieves item from the hash table
*
* @param    curKey  Retrieve node from hash table with curKey value
*
* @return	HashNode*	Pointer to the HashNode
*/
HashNode* HashTable::getItem(int curKey){

	if(isEmpty()) {
		return nullptr;
	}

	int hashCode = calculateHashCode(curKey);

	HashNode *current = table[hashCode];

	while(current != nullptr) {

		if(current->key == curKey) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}


/**
*
* Verifies if a key is in the hash table
*
* @param    curKey  Check key for hash table with curKey value
*
* @return	bool	True if found, false otherwise
*/
bool HashTable::contains(int curKey){

	if(isEmpty()) {
		return false;
	}

	int hashCode = calculateHashCode(curKey);

	HashNode *current = table[hashCode];
	while(current != nullptr) {

		if(current->key == curKey) {
			return true;
		}
		current = current->next;
	}
	return false;
}


/**
*
* Prints out the contents of table; output is sent to console and to file
*/
void HashTable::printTable(){

	ofstream& outFile = getOutFile();

	for(int i = 0; i < numberOfBuckets; ++i) {

		if(table[i] == nullptr) {

			cout << "Bucket " << i << ": Empty" << endl;
			outFile << "Bucket " << i << ": Empty" << endl;

		} else {

			cout << "Bucket " << i << ":" << endl;
			outFile << "Bucket " << i << ":" << endl;

			HashNode *current = table[i];
			while(current != nullptr) {
				cout << "FIFO info from cacheManager: Node key: ";
				cout << current->key << endl;

				outFile << "FIFO info from cacheManager: Node key: ";
				outFile << current->key << endl;

				current = current->next;
			}
		}
			cout << endl;
			outFile << endl;
	}
	cout << "End of table" << endl;
	outFile << "End of table" << endl;
}
