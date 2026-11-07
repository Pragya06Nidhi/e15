////////////////////////////////////////////////////////
// ECE 3574 Exercise: Unit Tests with Catch - starter code
//
#define CATCH_CONFIG_NO_POSIX_SIGNALS
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <map>
#include <string>

TEST_CASE("multimap basic insert and size", "[multimap]") {

    std::multimap<std::string, std::string> m;

    REQUIRE(m.empty());
    REQUIRE(m.size() == 0);

    m.insert(std::pair<std::string, std::string>("Ross", "Betsy"));

    REQUIRE_FALSE(m.empty());
    REQUIRE(m.size() == 1);

    m.insert(std::pair<std::string, std::string>("Ross", "Rachel"));

    // multimap allows duplicate keys
    REQUIRE(m.size() == 2);
    REQUIRE(m.count("Ross") == 2);
}


TEST_CASE("multimap find and count", "[multimap]") {

    std::multimap<int, std::string> m;

    m.insert({1, "one"});
    m.insert({2, "two"});
    m.insert({2, "another two"});
    m.insert({3, "three"});

    REQUIRE(m.count(1) == 1);
    REQUIRE(m.count(2) == 2);
    REQUIRE(m.count(4) == 0);

    auto result = m.find(3);

    REQUIRE(result != m.end());
    REQUIRE(result->first == 3);
    REQUIRE(result->second == "three");

    REQUIRE(m.find(10) == m.end());
}


TEST_CASE("multimap erase and clear", "[multimap]") {

    std::multimap<std::string, int> m;

    m.insert({"pear", 1});
    m.insert({"pear", 2});
    m.insert({"banana", 3});

    REQUIRE(m.size() == 3);

    // erase by key removes every element with that key
    m.erase("pear");

    REQUIRE(m.size() == 1);
    REQUIRE(m.count("pear") == 0);
    REQUIRE(m.count("banana") == 1);

    m.clear();

    REQUIRE(m.empty());
    REQUIRE(m.size() == 0);
}


TEST_CASE("multimap assignment operator", "[multimap]") {

    std::multimap<int, char> m1;

    m1.insert({1, 'C'});
    m1.insert({2, 'A'});
    m1.insert({2, 'T'});

    std::multimap<int, char> m2;

    m2 = m1;

    REQUIRE(m2.size() == m1.size());
    REQUIRE(m2.count(1) == 1);
    REQUIRE(m2.count(2) == 2);

    auto result = m2.find(1);

    REQUIRE(result != m2.end());
    REQUIRE(result->second == 'C');
}