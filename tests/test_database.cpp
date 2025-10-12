#include <gtest/gtest.h>
#include "Database.hpp"

TEST(InMemoryDBTest, PutAndGetRecord) {
    InMemoryDB db;
    UserRecord rec1;
    rec1.name = "Alice";
    rec1.age = 30;
    db.put("user1", rec1);

    UserRecord* result = db.get("user1");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->name, "Alice");
    EXPECT_EQ(result->age, 30);
}

TEST(InMemoryDBTest, GetNonExistentRecordReturnsNullptr) {
    InMemoryDB db;
    UserRecord* result = db.get("missing");
    EXPECT_EQ(result, nullptr);
}

TEST(InMemoryDBTest, RemoveRecord) {
    InMemoryDB db;
    UserRecord rec2;
    rec2.name = "Bob";
    rec2.age = 25;
    db.put("user2", rec2);

    db.remove("user2");
    UserRecord* result = db.get("user2");
    EXPECT_EQ(result, nullptr);
}

TEST(InMemoryDBTest, OverwriteRecord) {
    InMemoryDB db;
    UserRecord rec;
    rec.name = "Charlie";
    rec.age = 40;
    db.put("user3", rec);

    UserRecord rec_new;
    rec_new.name = "CharlieUpdated";
    rec_new.age = 41;
    db.put("user3", rec_new);

    UserRecord* result = db.get("user3");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->name, "CharlieUpdated");
    EXPECT_EQ(result->age, 41);
}

TEST(InMemoryDBTest, CheckIfRecordExists) {
    InMemoryDB db;
    UserRecord rec;
    rec.name = "Charlie";
    rec.age = 40;
    db.put("user3", rec);
    
    EXPECT_TRUE(db.checkIfExists("user3"));
    EXPECT_FALSE(db.checkIfExists("nonexistent"));
}