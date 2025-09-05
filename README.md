
# Cache Manager

**Cache Manager** is a C++ project designed to simulate and test a cache system using various data structures including:
- Doubly Linked Lists 
- Hash Tables
- Binary Search Trees

## Project Structure

```
cache-manager/
├── README.md
├── generated_output_file.txt
├── json.hpp
├── cache_manager_config.json
├── cache_manager_test_cases.json
├── uml-diagrams/                     
│   ├── BinarySearchTree.png
│   ├── DoublyLinkedList.png
│   ├── HashTable.png
│   └── CacheManager.png
├── src/                              
│   ├── binary_search_tree.cpp
│   ├── binary_search_tree.h
│   ├── cache_manager.cpp
│   ├── cache_manager.h
│   ├── cache_test_driver.cpp
│   ├── dll_node.cpp
│   ├── dll_node.h
│   ├── doubly_linked_list.cpp
│   ├── doubly_linked_list.h
│   ├── hash_node.cpp
│   ├── hash_node.h
│   ├── hash_table.cpp
│   ├── hash_table.h
│   ├── tree_node.cpp
│   └── tree_node.h

```

## Features

- Custom implementation of:
  - Hash tables and hash nodes
  - Doubly linked lists and nodes
  - Binary search trees and tree nodes
- JSON-based configuration (`cache_manager_config.json`)
- JSON-based test cases (`cache_manager_test_cases.json`)
- Output logging (`generated_output_file.txt`)
- Unit test and validation via `cache_test_driver.cpp`

## Dependencies

- C++17 or later
- [nlohmann/json](https://github.com/nlohmann/json) (included as `json.hpp`)

## Build & Run Instructions

1. Ensure a C++17-compatible compiler is installed (e.g., **g++ via MinGW-w64**).
2. Ensure **Git Bash** is installed and being used as your terminal.
3. **Extract all files** from the ZIP archive into a regular folder.
4. Open **Git Bash** and navigate to the project directory. For example:

```bash
cd "/c/Users/User/Desktop/cache_manager_project/Cache Manager"
```

5. Compile the code using:
```bash
g++ -std=c++17 -I. Isrc -o cache_test_driver.exe src/*.cpp
```
May have to press **Enter** twice before proceeding to step 6.

6. Run the executable:

```bash
./cache_test_driver.exe
```

## Example Usage

- Modify `cache_manager_test_cases.json` to define the test operations.
- Optionally configure runtime settings in `cache_manager_config.json`.
- Run `cache_test_driver.exe` to execute the test cases.
- Results will be written to `generated_output_file.txt`.

## Test Case Format

Each test case is defined inside `cache_manager_test_cases.json`, following this structure:

```json
{
  "cacheManager": [
    {
      "testCase1": [
        { "isEmpty": {} },
        { "add": {
            "key": 101,
            "fullName": "John Doe",
            "address": "1234 Main St",
            "city": "Oakland",
            "state": "CA",
            "zip": "12345"
          }
        },
        { "printSort": { "ascending": "true" } },
        { "remove": { "key": 101 } },
        { "isEmpty": {} }
      ]
    }
  ]
}
```

## UML Diagrams

### BinarySearchTree
![BinarySearchTree](uml-diagrams/BinarySearchTreeUML.png)

### DoublyLinkedList
![DoublyLinkedList](uml-diagrams/DoublyLinkedListUML.png)

### HashTable
![HashTable](uml-diagrams/HashTableUML.png)

### CacheManager
![CacheManager](uml-diagrams/CacheManagerUML.png)

## Author

*Ayra Babar*

## License

This project is licensed under the MIT License.
