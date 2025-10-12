inmemory_db/  
│  
├── CMakeLists.txt  
│   Build configuration for the project (targets, compiler flags, libraries).  
│  
├── src/  
│   ├── main.cpp  
│   │   Entry point of the program; runs example usage or demo of the database.  
│   │  
│   ├── db/  
│   │   ├── Database.hpp  
│   │   │   Class definition for the database interface (put/get/remove).  
│   │   │  
│   │   ├── Database.cpp  
│   │   │   Implementation of the database core logic (unordered_map, record handling).  
│   │   │  
│   │   ├── Record.hpp  
│   │   │   Definition of the data record (struct/class with attributes).  
│   │   │  
│   │   ├── Persistence.hpp  
│   │   │   Interface for saving/loading data (write-ahead log, snapshots).  
│   │   │  
│   │   ├── Persistence.cpp  
│   │   │   Implementation of file I/O and recovery logic.  
│   │   │  
│   │   ├── Concurrency.hpp  
│   │   │   Wrapper utilities for mutexes, locks, and thread-safe access.  
│   │   │  
│   │   └── Concurrency.cpp  
│   │       Implementation of thread-safety mechanisms for database operations.  
│   │  
│   └── utils/  
│       ├── Serializer.hpp  
│       │   Functions for serializing and deserializing records to/from disk.  
│       │  
│       └── Logger.hpp  
│           Simple logging utilities (debug/info/error).  
│  
├── tests/  
│   ├── test_main.cpp  
│   │   Test runner entry point (using GoogleTest or Catch2).  
│   │  
│   ├── test_database.cpp  
│   │   Unit tests for core database operations (put/get/remove).  
│   │  
│   ├── test_persistence.cpp  
│   │   Unit tests for saving, loading, crash recovery.  
│   │  
│   └── test_concurrency.cpp  
│       Stress tests with multiple threads performing operations.  
│  
├── benchmarks/  
│   └── benchmark.cpp  
│       Performance measurement of database operations under load.  
│  
└── docs/  
    └── design.md  
        High-level design document explaining architecture, data flow, and assumptions.  


Features that could be added (in review)

1. Update Record Fields
Allow partial updates to a record without overwriting the entire entry.

2. List All Keys / Records
Methods to retrieve all keys or all records for iteration or bulk operations.

3. Count Records
Return the number of records currently stored.

4. Clear Database
Remove all records from the database.

5. Existence Check
Method to check if a key exists (contains(key)).

6. Persistence
Save/load the database to/from disk (serialization).

7. Thread Safety
Add concurrency controls (mutexes) for multi-threaded access.

8. Search/Filter
Find records by field values or custom predicates.

9. TTL/Expiration
Support time-to-live for records, auto-removing expired entries.

10. Transaction Support
Allow atomic batches of operations.