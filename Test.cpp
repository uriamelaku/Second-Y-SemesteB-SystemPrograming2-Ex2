// ooriamelaku@gmail.com
// 208734889
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

// Test 1 - g1 + g2
TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.toString() == "[0, 2, 1], [2, 0, 3], [1, 3, 0]");
}

// Test 2 - g1 - g2
TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 1},
        {2, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    CHECK(g3.toString() == "[0, 0, 1], [0, 0, -1], [1, -1, 0]");
}

// Test 3 - g1 * 2
TEST_CASE("Test graph multiplication by scalar")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g3 = g1 * 2;
    CHECK(g3.toString() == "[0, 2, 0], [2, 0, 2], [0, 2, 0]");
}

// Test 4 - g1 * g2
TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    CHECK(g4.toString() == "[1, 0, 2], [1, 3, 1], [1, 0, 2]");
}

// Test 5 - g1 / 2
TEST_CASE("Test graph division by scalar")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g1.loadGraph(graph);
    ariel::Graph g3 = g1 / 2;
    CHECK(g3.toString() == "[0, 1, 0], [1, 0, 1], [0, 1, 0]");
}

// Test 6 - g1 == g2
TEST_CASE("Test graph equality") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(weightedGraph);

    CHECK(g1 == g2);
}

// Test 7 - g1 != 2
TEST_CASE("Test graph inequality") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g3;
    vector<vector<int>> differentGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g3.loadGraph(differentGraph);

    CHECK(g1 != g3);
}
// Test 8 - g1 < 2
TEST_CASE("Test operator < for graphs") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 < g2);
    CHECK_FALSE(g2 < g1);
}
// Test 9 - g1 > 2
TEST_CASE("Test operator > for graphs") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    CHECK(g1 > g2);
    CHECK_FALSE(g2 > g1);
}
// Test 10 - g1 <= 2
TEST_CASE("Test operator<= for graphs") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g3.loadGraph(graph3);

    CHECK(g1 <= g2);
    CHECK(g1 <= g3);
    CHECK_FALSE(g2 <= g1);
}
// Test 11 - g1 >= 2
TEST_CASE("Test operator>= for graphs") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g3.loadGraph(graph3);

    CHECK(g2 >= g1);
    CHECK(g1 >= g3);
    CHECK_FALSE(g1 >= g2);
}



// Test 12
TEST_CASE("Test graph pre-increment") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ++g1;
    CHECK(g1.toString() == "[1, 2, 1], [2, 1, 2], [1, 2, 1]");
}
// Test 13
TEST_CASE("Test graph post-increment") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    g1++;
    CHECK(g1.toString() == "[1, 2, 1], [2, 1, 2], [1, 2, 1]");

    g1++;
    CHECK(g1.toString() == "[2, 3, 2], [3, 2, 3], [2, 3, 2]");
}
// Test 14
TEST_CASE("Test graph pre-decrement") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    --g1;
    CHECK(g1.toString() == "[-1, 0, -1], [0, -1, 0], [-1, 0, -1]");
}
// Test 15
TEST_CASE("Test graph post-decrement") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    g1--;
    CHECK(g1.toString() == "[-1, 0, -1], [0, -1, 0], [-1, 0, -1]");

    g1--;
    CHECK(g1.toString() == "[-2, -1, -2], [-1, -2, -1], [-2, -1, -2]");
}
// Test 16
TEST_CASE("Test number of edges")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    CHECK(g1.numEdges() == 4);

    ariel::Graph g2;
    vector<vector<int>> graphWithMoreEdges = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graphWithMoreEdges);
    CHECK(g2.numEdges() == 6);
}

// Test 17
TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}