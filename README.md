# InMemory DB

A lightweight, high-performance in-memory key–value database engine written in C++. Designed to store, retrieve, update, and delete key–value pairs at high speed with thread-safe concurrent access and durable persistence to disk.

---

## Features

- **Fast in-memory storage** using `unordered_map` or a custom hash map
- **Write-ahead log (WAL)** for durability — operations are appended before being applied
- **Periodic snapshots** of the full in-memory state for faster recovery
- **Crash recovery** by replaying the WAL and/or loading the latest snapshot on restart
- **Concurrent access** via `std::shared_mutex` — multiple readers, exclusive writers
- **Clean C++ API**: `put(key, value)`, `get(key)`, `remove(key)`
- **Simple query language**: e.g., `GET user:123`, `PUT user:123 value`
- **Optional TCP server** for networked clients
- **Benchmarks** for measuring read/write latency and throughput under multi-threaded load

---

## Project Structure

```
inmemory_db/
│
├── CMakeLists.txt              # Build configuration
│
├── src/
│   ├── main.cpp                # Entry point — demo/example usage
│   │
│   ├── db/
│   │   ├── Database.hpp        # Database interface (put/get/remove)
│   │   ├── Database.cpp        # Core logic — hash map, record handling
│   │   ├── Record.hpp          # Record struct/class definition
│   │   ├── Persistence.hpp     # Interface for WAL and snapshots
│   │   ├── Persistence.cpp     # File I/O and recovery implementation
│   │   ├── Concurrency.hpp     # Mutex and lock utilities
│   │   └── Concurrency.cpp     # Thread-safety mechanisms
│   │
│   └── utils/
│       ├── Serializer.hpp      # Serialize/deserialize records to/from disk
│       └── Logger.hpp          # Debug/info/error logging
│
├── tests/
│   ├── test_main.cpp           # Test runner entry point (GoogleTest / Catch2)
│   ├── test_database.cpp       # Unit tests for put/get/remove
│   ├── test_persistence.cpp    # Tests for save, load, crash recovery
│   └── test_concurrency.cpp    # Multi-threaded stress tests
│
├── benchmarks/
│   └── benchmark.cpp           # Throughput and latency measurements
│
├── data/                       # WAL and snapshot files (runtime-generated)
│
└── docs/
    ├── design.md               # Architecture, data flow, and assumptions
    └── usage.md                # API and query language reference
```

---

## Architecture Overview

### Data Storage Layer
The core uses an `unordered_map<string, Record>` (or a custom hash map) for O(1) average-case reads and writes. A custom allocator or memory pool can be plugged in for predictable, low-latency allocation.

- **Keys**: strings or fixed-size byte arrays
- **Values**: arbitrary blobs or templated types

### Persistence Layer
Every write is first appended to the **Write-Ahead Log (WAL)** before being applied in memory. Periodically, the full state is flushed to a **snapshot file**. On startup:

1. Load the latest snapshot (if any)
2. Replay any WAL entries written after the snapshot

This ensures durability even in the event of a mid-operation crash.

### Concurrency Layer
A `std::shared_mutex` protects the hash map:

- **Reads** acquire a shared lock — multiple threads read simultaneously
- **Writes** acquire an exclusive lock — no contention with other reads or writes

Lock-free data structures are an optional stretch goal.

### API Layer
```cpp
db.put("user:123", "Alice");
auto val = db.get("user:123");   // returns std::optional<Value>
db.remove("user:123");
```

Simple query language (parsed from string):
```
GET  user:123
PUT  user:123 Alice
DEL  user:123
```

---

## Building

**Requirements**: C++17 or later, CMake 3.15+

```bash
cmake -S . -B build
cmake --build build
```

Run the demo:
```bash
./build/main
```

---

## Testing

```bash
cmake --build build --target tests
./build/tests
```

Test coverage includes:
- Core operations (`put`, `get`, `remove`)
- Persistence: save, reload, crash simulation and recovery
- Concurrency: concurrent reads/writes under high thread count

---

## Benchmarks

```bash
./build/benchmarks
```

Measures read/write latency and throughput under multi-threaded load, and compares against a plain `unordered_map` baseline.

---

## Real-World Use Cases

| Domain | Use Case |
|---|---|
| **IoT Edge Devices** | Store sensor readings locally before syncing to cloud; tolerates power loss via WAL |
| **Gaming Servers** | Fast in-memory session state (player stats, game rooms) with occasional persistence |
| **Financial Applications** | Cache trading data or exchange rates with high concurrency |
| **Web Applications** | Caching layer for hot data, similar to Redis or Memcached |

---

## Why This Project

This project demonstrates:

- **Systems-level thinking**: custom allocators, memory pools, WAL-based persistence
- **Concurrency control**: correct and performant use of C++ threading primitives
- **API design**: clean, extensible interface usable both internally and over a network
- **Scalability**: a foundation that naturally extends toward distributed caching concepts
- **Professional relevance**: mirrors production systems like Redis, RocksDB, and LevelDB

---

## License

MIT