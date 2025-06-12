/**
* @author Ayra Babar
* @file doubly_linked_list.cpp
* @brief This file contains the implementation of the doubly linked list header file
* 02/03/2025 - Initial creation & complete implementation of all methods
* 02/05/2025 - Method header comments added
* 02/06/2025 - Changes made to remove method
* 02/27/2025 - Methods printList and reversePrintList were added and
* 			   updates made to methods & comments according to header file
* 04/15/2025 - Updated remove method
* 05/08/2025 - Added and implemented the following methods: getOldestKey, contains, getNodeByKey
*/

#include "doubly_linked_list.h"
#include "dll_node.h"
#include <iostream>

using namespace std;
extern ofstream& getOutFile();

// This constructor makes an empty doubly linked list
DoublyLinkedList::DoublyLinkedList() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

// This destructor clears the list
DoublyLinkedList::~DoublyLinkedList() {
	clear();
}


/**
*
* Returns the number of entries in the list
*
* @return Number of entries in the list
*/
int DoublyLinkedList::getSize() {
    return size;
}


/**
*
* Checks whether the list is empty
*
* @return True if head pointer is nullptr, otherwise return false
*/
bool DoublyLinkedList::isEmpty() {
	return (head == nullptr);
}


/**
*
* Inserts a new node at the head of the list; updates doubly linked list and size
*
* @param	key     The int key for new node
* @param    newNode The new DllNode
*/
void DoublyLinkedList::insertAtHead(int key, DllNode* newNode) {

	if (newNode == nullptr) {
		return;
	}

	newNode->key = key;

	if(isEmpty()) {
		head = tail = newNode;

	} else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}

	size++;
}


/**
*
* Inserts a new node at the tail of the list; updates doubly linked list and size
*
* @param    key     The int key for new node
* @param    newNode The new DllNode
*/
void DoublyLinkedList::insertAtTail(int key, DllNode* newNode) {

	if (newNode == nullptr) {
		return;
	}
	newNode->key = key;

	if(isEmpty()) {
		head = tail = newNode;

	} else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}

	size++;
}


/**
*
* Removes a node with a specific value from the list; updates doubly linked list and size
*
* @param	key		The int key for the node to delete
*/
void DoublyLinkedList::remove(int key) {
	if (isEmpty()) {
		return;
	}

	DllNode *nodeToDelete = head;

	while (nodeToDelete != nullptr) {
		if (nodeToDelete->key == key) {

			if (nodeToDelete->next == nullptr) {
				removeTailNode();

			} else if (nodeToDelete->prev == nullptr) {
				removeHeaderNode();

			} else {

				nodeToDelete->prev->next = nodeToDelete->next;
				nodeToDelete->next->prev = nodeToDelete->prev;
				delete nodeToDelete;
				nodeToDelete = nullptr;
				size--;
			}
			return;
		}
		nodeToDelete = nodeToDelete->next;
	}
}


/**
*
* Removes the header (first) node; updates doubly linked list and size
*/
void DoublyLinkedList::removeHeaderNode() {

	if(isEmpty()) {
		return;
	}
	DllNode *nodeToDelete = head;
	head = head->next;

	// Check if the list becomes empty after removal
	if(head != nullptr) {
		head->prev = nullptr;
	} else {
		tail = nullptr;
	}
	delete nodeToDelete;
	nodeToDelete = nullptr;
	size--;
}


/**
*
* Removes the tail (last) node; updates doubly linked list and size
*/
void DoublyLinkedList::removeTailNode() {

	if(isEmpty()) {
		return;
	}
	DllNode *nodeToDelete = tail;
	tail = tail->prev;

	if(tail != nullptr) {
		tail->next = nullptr;
	} else {
		head = nullptr;
	}

	delete nodeToDelete;
	nodeToDelete = nullptr;
	size--;
}


/**
*
* Moves a specific node to the head of the list; updates doubly linked list
*
* @param	key		The int key of the DllNode to move to front of list
*/
void DoublyLinkedList::moveNodeToHead(int key) {

	if(isEmpty()) {
		return;
	}

	DllNode *nodeToMove = head;
	while(nodeToMove != nullptr) {

		if(nodeToMove->key == key) {

			if(nodeToMove == head) {
				return;
			}
			if(nodeToMove->next != nullptr) {
				nodeToMove->next->prev = nodeToMove->prev;
			}
			if(nodeToMove->prev != nullptr) {
				nodeToMove->prev->next = nodeToMove->next;
			}
			if(nodeToMove == tail) {
				tail = nodeToMove->prev;
			}

			nodeToMove->next = head;
			nodeToMove->prev= nullptr;
			head->prev = nodeToMove;
			head = nodeToMove;
			return;

		}
			nodeToMove = nodeToMove->next;
	}
}


/**
*
* Moves a specific node to the tail of the list; updates doubly linked list
*
* @param	key		The int key of the DllNode to move to end of list
*/
void DoublyLinkedList::moveNodeToTail(int key) {

	if(isEmpty()) {
		return;
	}

		DllNode *nodeToMove = head;
		while(nodeToMove != nullptr) {

			if(nodeToMove->key == key) {

				if(nodeToMove == tail) {
					return;
				}
				if(nodeToMove == head) {
					head = nodeToMove->next;
					if(head) {
						head->prev = nullptr;
					}
				} else {

					nodeToMove->prev->next = nodeToMove->next;
					// If there is a node after the nodeToMove:
					if(nodeToMove->next) {
						nodeToMove->next->prev = nodeToMove->prev;
					}
				}

				nodeToMove->prev = tail;
				nodeToMove->next= nullptr;
				tail->next = nodeToMove;
				tail = nodeToMove;
				return;

			}
				nodeToMove = nodeToMove->next;
		}
}


/**
*
* Clears the list by deleting all nodes; resets size to 0
*/
void DoublyLinkedList::clear() {

	if(isEmpty()) {
		return;
	}

	DllNode *current = head;
	// Traverse through the entire linked list
	while(current != nullptr) {

		// Store the next node to not lose track of the list
		DllNode *nextNode = current->next;
		delete current;
		current = nextNode;
	}

	current = nullptr;
	head = tail = nullptr;
	size = 0;
}


/**
*
* Prints the doubly linked list from head to tail to console and output file
*/
void DoublyLinkedList::printList() {
    if(isEmpty()) {
    	return;
    }

    ofstream& outFile = getOutFile();
    outFile << "Here are the FIFO List contents:" << endl;

    DllNode *current = head;
    while(current != nullptr) {

    	cout << current->key << " ";
    	outFile << current->key << " ";
    	current = current->next;
    }

    outFile << "End of FIFO List" << endl << endl;
}


/**
*
* Prints the doubly linked list from tail to head to console and output file
*/
void DoublyLinkedList::reversePrintList() {
    if(isEmpty()) {
    	return;
    }

    ofstream& outFile = getOutFile();
    outFile << "Here are the FIFO List contents:" << endl;

    DllNode *current = tail;
    while(current != nullptr) {

    	cout << current->key << " ";
    	outFile << current->key << " ";
    	current = current->prev;
    }

    outFile << "End of FIFO List" << endl << endl;
    cout << endl;
}

/**
*
* Gets the oldest node of the list (tail of the FIFO list)
*
* @return	DllNode*	Returns the pointer to last node in list
*/
DllNode* DoublyLinkedList::getOldestKey() {
	return tail;
}

/**
*
* Checks if a node exists in the list using a key
*
* @param	keyToFind     The int key to find
*
* @return	true	If list contains that value
*/
bool DoublyLinkedList::contains(int keyToFind) {
	if(isEmpty()) {
		return false;
	}

	DllNode* current = head;
	while(current != nullptr) {
		if(current->key == keyToFind) {
			return true;
		}
		current = current->next;
	}

	return false;
}

/**
*
* Retrieves a node by its key
*
* @param	keyToFind   The int key to find
*
* @return	DllNode*	Returns the pointer of that node, if it exists in the list
*/
DllNode* DoublyLinkedList::getNodeByKey(int keyToFind) {
	if(isEmpty()) {
		return nullptr;
	}

	DllNode* current = head;
	while(current != nullptr) {
		if(current->key == keyToFind) {
			return current;
		}
		current = current->next;
	}

	return nullptr;
}
