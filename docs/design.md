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
