/**
* @author H. Hui
* @file dll_node.h
* @brief This header file defines the dll_node (Doubly Linked List Node) structure
*
* 12/30/2024 - Originally created by H. Hui
* 05/08/2025 - Modified and implemented by Ayra Babar for academic purposes
*/

#ifndef DLL_NODE_H
#define DLL_NODE_H

#include <string>

/**
* @class DllNode
* @brief Node structure for Doubly Linked List
*
* A DllNode is the basic building block of the doubly linked list. Each node
* stores a key, the full name, the address, the city, the state, and zip code,
* along with previous & next pointers that point to DllNodes or nullptr
*/

class DllNode {
public:
    int key;

    std::string fullName;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;

    DllNode* prev;    // Pointer to the previous node in the list
    DllNode* next;    // Pointer to the next node in the list

/**
* @brief Constructor for a DllNode
*
* Initializes a DllNode with the given key and sets other class members to default values
*
* @param	value	The key value for the node
*/
    DllNode(int value);

/**
* @brief Full constructor for a DllNode
*
* Initializes a DllNode with full user data
*
* @param	value		The key value for the node
* @param	fullName	The full name associated with the node
* @param	address		The address of the individual
* @param	city		The city of the individual
* @param	state		The state of the individual
* @param	zip			The zip code of the individual
*/
    DllNode(int value, std::string fullName, std::string address, std::string city, std::string state, std::string zip);

/**
*
* @brief Method to print the doubly linked list node data
*/

    void printNode();
};

#endif	// DLL_NODE_H
