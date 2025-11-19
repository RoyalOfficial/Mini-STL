#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include <iostream>
#include "../include/vector.hpp"
#include "../include/algorithm.hpp"

/*
Includes tests for checking vector implementation
Author: Pietro
*/

TEST_CASE("Vector push_back and size") {
    mini_stl::Vector<int> v;

    // Test push_back
    for (int i = 0; i < 10; i++){
        v.push_back(i * 12);
    }

    REQUIRE(v.size() == 10);
    
    for (int i = 0; i < 10; i ++) {
        REQUIRE(v[i] == i * 12);
    }
}

TEST_CASE("Vector pop_back works") {
    mini_stl::Vector<int> v;

    for (int i = 0; i < 10; i++){
        v.push_back(i * 12);
    }

    for (int i = 9; i >= 0; i--){
        REQUIRE(v.size() == i + 1);
        v.pop_back();
    }

    REQUIRE(v.size() == 0);
}

TEST_CASE("Vector clear works") {
    mini_stl::Vector<int> v;

    // Populate vector
    for (int i = 0; i < 10; i++){
        v.push_back(i * 12);
    }

    v.clear();
    REQUIRE(v.size() == 0);
}

TEST_CASE("Resrve works") {
    mini_stl::Vector<int> v;

    v.reserve(50);
    REQUIRE(v.capacity() == 50);
}

TEST_CASE("Linear Search works"){
    mini_stl::Vector<int> v;

    for (int i = 0; i < 10; i++){
        v.push_back(i * 12);
    }

    int* foundval = mini_stl::find(v.begin(), v.end(), 12);
    REQUIRE(*foundval == 12);
}

TEST_CASE("Sort Ascending works"){
    mini_stl::Vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(10 - i);
    }
    mini_stl::sort_ascending(v.begin(), v.end());

    for (int i = 0; i < 10; i++){
        REQUIRE(v[i] == i + 1);
    }
}

TEST_CASE("Sort Descending works"){
    mini_stl::Vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i + 10);
    }
    mini_stl::sort_descending(v.begin(), v.end());
    for (int i = 0; i < 10; i++){
        REQUIRE(v[i] == 19 - i);
    }
}

TEST_CASE("Dot product works"){
    mini_stl::Vector<int> vec1;
    mini_stl::Vector<int> vec2;
    int result;

    for (int i = 0; i < 5; i++){
        vec1.push_back(i);
        vec2.push_back(i+10);
    }

    result = vec1.dot(vec2);

    REQUIRE(result==130);
}

TEST_CASE("Vector addition works"){
    mini_stl::Vector<int> vec1;
    mini_stl::Vector<int> vec2;
    mini_stl::Vector<int> result;

    result.reserve(5);

    for (int i = 0; i < 5; i++){
        vec1.push_back(i);
        vec2.push_back(i+10);
    }
    result = vec1.add(vec2);

    for (int i = 0; i < 5; i++){
        REQUIRE(result[i] == i + (i +10));
    }
}