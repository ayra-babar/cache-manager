/**
* @author H. Hui
* @file dll_node.cpp
* @brief This file contains constructor implementations for DllNode
*
* 12/30/2024 - Originally created by H. Hui
* 05/08/2025 - Modified and implemented by Ayra Babar for academic purposes
*/

#include <iostream>
#include <fstream>
#include <string>

#include "dll_node.h"

// Declares an external function that logs a message to both a file and the console
extern void logToFileAndConsole(std::string msg);

/**
* @brief Constructor for a DllNode
*
* Initializes a DllNode with the given key and sets other class members to default values
*
* @param	value	The key value for the node
*/

DllNode::DllNode(int value) : key(value), prev(nullptr), next(nullptr) {}

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

DllNode::DllNode(int myValue, std::string myFullName, std::string myAddress, std::string myCity, std::string myState, std::string myZip) : key(myValue), fullName(myFullName), address(myAddress), city(myCity), state(myState), zip(myZip), prev(nullptr), next(nullptr) {}

/**
* @brief Logs the contents of the node to both the console and a log file
*
* If verbose mode is enabled, prints all fields. Otherwise, prints only the key
*/

void DllNode::printNode() {
    bool verbose = false;
    if (verbose) {
        logToFileAndConsole("FIFO info from cacheManager.  Node key: " + std::to_string(key) + "; name: " + fullName + "; address: " + address + "; city: " + city + "; state: " + state + "; zip: " + zip);
    }
    else {
        logToFileAndConsole("FIFO info from cacheManager:  Node key: " + std::to_string(key));
    }
}
