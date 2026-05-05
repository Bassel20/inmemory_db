add_library(InMemoryDB
    db/Database.cpp
    db/Persistence.cpp
    db/Concurrency.cpp
)

target_include_directories(InMemoryDB PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/db
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)
