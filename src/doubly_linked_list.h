/**
* @author H. Hui
* @file doubly_linked_list.h
* @brief Declaration of the DoublyLinkedList class and its member functions
*
* 12/30/2024 - H. Hui created file and added comments
* 05/08/2025 - Modified and implemented by Ayra Babar for academic purposes. Added the following
* methods & corresponding header comments: getOldestKey, contains, getNodeByKey
*/


#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include <fstream>
#include <string>

#include "dll_node.h"

/**
 * @class DoublyLinkedList
 * @brief A class representing a doubly linked list using DllNode objects
 *
 * Provides basic and advanced operations such as insertion, deletion, search,
 * and movement of nodes within a doubly linked list structure
 */

class DoublyLinkedList {
public:
    DllNode* head;          // Pointer to the first node (head) in the list
    DllNode* tail;          // Pointer to the last node (tail) in the list

    int size;               // Number of entries in list

    DoublyLinkedList();     // Constructor: Initializes the list to be empty
    ~DoublyLinkedList();    // Destructor: Clears the list

/**
*
* Returns the number of entries in the list
*
* @return Number of entries in the list
*/
    int getSize();

/**
*
* Checks whether the list is empty
*
* @return True if head pointer is nullptr, otherwise return false
*/
    bool isEmpty();


/**
*
* Inserts a new node at the head of the list; updates doubly linked list and size
*
* @param	key     The int key for new node
* @param    newNode The new DllNode
*/
    void insertAtHead(int key, DllNode* newNode);


/**
*
* Inserts a new node at the tail of the list; updates doubly linked list and size
*
* @param    key     The int key for new node
* @param    newNode The new DllNode
*/
    void insertAtTail(int key, DllNode* newNode);


/**
*
* Removes a node with a specific value from the list; updates doubly linked list and size
*
* @param	key		The int key for the node to delete
*/
    void remove(int key);


/**
*
* Removes the header (first) node; updates doubly linked list and size
*/
    void removeHeaderNode();


/**
*
* Removes the tail (last) node; updates doubly linked list and size
*/
    void removeTailNode();


/**
*
* Moves a specific node to the head of the list; updates doubly linked list
*
* @param	key		The int key of the DllNode to move to front of list
*/
    void moveNodeToHead(int key);


/**
*
* Moves a specific node to the tail of the list; updates doubly linked list
*
* @param	key		The int key of the DllNode to move to end of list
*/
    void moveNodeToTail(int key);


/**
*
* Clears the list by deleting all nodes; resets size to 0
*/
    void clear();


/**
*
* Prints the doubly linked list from head to tail to console and output file
*/
    void printList();


/**
*
* Prints the doubly linked list from tail to head to console and output file
*/
    void reversePrintList();

/**
*
* Gets the oldest node of the list (tail of the FIFO list)
*
* @return	DllNode*	Returns the pointer to last node in list
*/
    DllNode* getOldestKey();

/**
*
* Checks if a node exists in the list using a key
*
* @param	keyToFind     The int key to find
*
* @return	true	If list contains that value
*/
    bool contains(int key);

/**
*
* Retrieves a node by its key
*
* @param	keyToFind   The int key to find
*
* @return	DllNode*	Returns the pointer of that node, if it exists in the list
*/
    DllNode* getNodeByKey(int key);

};

#endif	// DOUBLY_LINKED_LIST_H
