// ooriamelaku@gmail.com
// 208734889
#include "Graph.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
using namespace ariel;

void Graph::loadGraph(vector<vector<int>> graph) {
    for (const auto& row : graph) {
        if (row.size() != graph.size()) {
            cout << "Invalid graph: The graph is not a square matrix." << endl;
            return;
        }
    }
    this->graph = graph;
}
// cout << g1
namespace ariel{
    std::ostream& operator<<(std::ostream& os, const Graph& g) {
        const auto& matrix = g.getMatrix();
        for (const auto& row : matrix) {
            os << "[";
            for (size_t i = 0; i < row.size(); ++i) {
                os << row[i];
                if (i != row.size() - 1) { // Don't print comma after the last element
                    os << ", ";
                }
            }
            os << "]\n";
        }
        return os;
    }
    string Graph::toString() const {
    string result;
    for (size_t i = 0; i < graph.size(); ++i) {
        result += "[";
        for (size_t j = 0; j < graph[i].size(); ++j) {
            result += to_string(graph[i][j]);
            if (j != graph[i].size() - 1) {
                result += ", ";
            }
        }
        result += "]";
        if (i != graph.size() - 1) {
            result += ", ";
        }
    }
    return result;
}
}
// g1 + g2
Graph Graph::operator+(const Graph& other) const {
    if (this->graph.size() != other.graph.size()) {
        cout << "Graphs must be of the same size to add" << endl;
        exit(1);
    }

    Graph result;
    result.graph = this->graph; // Copy the graph of the current object

    for (size_t i = 0; i < graph.size(); ++i) {
        for (size_t j = 0; j < graph[i].size(); ++j) {
            result.graph[i][j] += other.graph[i][j];
        }
    }

    return result;
}
// g1 += g2
Graph& Graph::operator+=(const Graph& other) {
        if (this->graph.size() != other.graph.size()) {
            cout << "Graphs must be of the same size to add" << endl;
            exit(1);
        }
        Graph result = *this;
        *this = result + other;
        return *this;
    }
// g1 = g2 - g3
Graph Graph::operator-(const Graph& other) const {
     if (this->graph.size() != other.graph.size()) {
        cout << "Graphs must be of the same size to add" << endl;
        exit(1);
    }

    Graph result = *this;

    for (size_t i = 0; i < graph.size(); ++i) {
        for (size_t j = 0; j < graph[i].size(); ++j) {
            result.graph[i][j] -= other.graph[i][j];
        }
    }

    // Check for negative elements in the resulting graph
    for (size_t i = 0; i < result.graph.size(); ++i) {
        for (size_t j = 0; j < result.graph[i].size(); ++j) {
            if (result.graph[i][j] < 0) {
                throw std::runtime_error("Error: Negative weight encountered");
            }
        }
    }

    return result;
}
// g1 -= g2
Graph& Graph::operator-=(const Graph& other) {
    if (this->graph.size() != other.graph.size()) {
        cout << "Graphs must be of the same size to add" << endl;
        exit(1);
    }
    Graph result = *this;
    *this = result - other;
    return *this;
}
// g1 *= 2
Graph& Graph::operator*=(int scalar) {
    if (scalar < 0) {
        throw std::runtime_error("Error: scalar value cannot be negative");
    }
    for (auto& row : this->graph) {
        for (auto& element : row) {
            element *= scalar;
        }
    }
    return *this;
}
// g1 * 2  // use the operator *=
Graph Graph::operator*(int scalar) const {
    if (scalar <= 0) {
        throw std::runtime_error("Error: scalar value cannot be negative");
    }
    Graph result = *this; // Create a copy of the current graph
    result *= scalar; // Use the *= operator to multiply the copy by the scalar
    return result;
}
// g1 / 2 
Graph Graph::operator/(double scalar) const {
    if (scalar <= 0) {
        throw std::runtime_error("Error: scalar value cannot be negative or zero");
    }
    Graph result = *this; // Create a copy of the current graph
    result /= scalar; // Use the *= operator to multiply the copy by the scalar
    return result; // Return the result
}
// g1 /= 2  // use the operator /=
Graph& Graph::operator/=(double scalar) {
    if (scalar < 0) {
        throw std::runtime_error("Error: scalar value cannot be negative");
    }
    for (auto& row : this->graph) {
        for (auto& element : row) {
            element /= scalar;
        }
    }
    return *this;
}
// g1 * g2
Graph Graph::operator*(const Graph& other) const {
    // Check if the number of columns in the first matrix equals the number of rows in the second matrix
    if (this->graph[0].size() != other.graph.size()) {
        throw std::invalid_argument("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }

    // Create a result matrix with dimensions of the first matrix's rows and the second matrix's columns
    Graph result;
    result.graph.resize(this->graph.size(), std::vector<int>(other.graph[0].size(), 0));

    // Perform matrix multiplication
    for (size_t i = 0; i < this->graph.size(); ++i) {
        for (size_t j = 0; j < other.graph[0].size(); ++j) {
            for (size_t k = 0; k < other.graph.size(); ++k) {
                result.graph[i][j] += this->graph[i][k] * other.graph[k][j];
            }
        }
    }

    return result;
}
// +g1
Graph Graph::operator+() const {
    return *this;
}
// -g1
Graph Graph::operator-() const {
    Graph result = *this;
    for (size_t i = 0; i < graph.size(); ++i) {
        for (size_t j = 0; j < graph[i].size(); ++j) {
            result.graph[i][j] = -result.graph[i][j];
        }
    }
    return result;
}
// g1 == g2
int Graph::operator==(const Graph& other) const {
    if (this->graph.size() != other.graph.size() || this->graph[0].size() != other.graph[0].size() ){
        return 0;
    }
    auto matrix1 = this->getMatrix();
    auto matrix2 = other.getMatrix();
    for (size_t i = 0; i < matrix1.size(); ++i) {
        for (size_t j = 0; j < matrix1[i].size(); ++j) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}
// g1 != g2
int Graph::operator!=(const Graph& other) const {
        return !(*this == other);
    }

size_t Graph::numEdges() const {
    size_t count = 0;
    auto adjacencyMatrix = this->getMatrix();
    for (const auto& row : adjacencyMatrix) {
        for (const auto& val : row) {
            if (val != 0) {
                count++;
            }
        }
    }
    return count;
}

int Graph::isSubsetOf(const Graph& other) const {

    auto adjacencyMatrix = this->getMatrix();
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            if (adjacencyMatrix[i][j] != 0 && adjacencyMatrix[i][j] != other.getMatrix()[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}
int Graph::isProperSubsetOf(const Graph& other) const {
    return isSubsetOf(other) && this->numEdges() < other.numEdges();
}
// g1 < g2
bool Graph::operator<(const Graph& other) const {
    // case of g1 inside g2 and numEdges of g1 < numEdges of g2. return 1
    if (isProperSubsetOf(other) && this->numEdges() < other.numEdges()) {
        return true;
    }
    // case of g1 not inside g2 but numEdges of g1 < numEdges of g2. return 1
    else if(isProperSubsetOf(other) == 0 && this->numEdges() < other.numEdges()) {
        return true;
    }
    // case of numEdges of g1 = numEdges of g2 but the matrix size of g1 < matrix size of g2. return 1
    else if(this->numEdges() == other.numEdges()) {
        if(this->getMatrix().size() < other.getMatrix().size()){
            return true;

        }
        else{
            return false;
        }
    }
    //it means g1 is not a proper subset of g2
    return false;

}
// g1 > g2
int Graph::operator>(const Graph& other) const {
    // case of g2 inside g1 and numEdges of g2 < numEdges of g1. return 1
    if (isProperSubsetOf(other) == 0 && other.numEdges() < this->numEdges()) {
        return 1;
    }
    // case of g2 not inside g1 but numEdges of g2 < numEdges of g1. return 1
    else if(isProperSubsetOf(other) == 0 && this->numEdges() > other.numEdges()) {
        return 1;
    }
    // case of numEdges of g1 = numEdges of g2 but the matrix size of g1 > matrix size of g2. return 1
    else if(this->numEdges() == other.numEdges()) {
        if(this->getMatrix().size() > other.getMatrix().size()){
            return 1;

        }
        else{
            return 0;
        }
    }
    //it means g1 is not a proper subset of g2
    return 0;

}
//g1 <= g2
int Graph::operator<=(const Graph& other) const {
    if(*this < other){
        return 1;
    }
    if (*this == other)
    {
        return 1;
    }
    return 0;
}
//g1 >= g2
int Graph::operator>=(const Graph& other) const {
    if(*this > other){
        return 1;
    }
    if (*this == other)
    {
        return 1;
    }
    return 0;
}
// ++g1
Graph& Graph::operator++() {
    for (auto& row : this->graph) {
        for (auto& element : row) {
            element += 1;
        }
    }
    return *this;
}
// g1++
Graph Graph::operator++(int) {
    Graph result = *this;
    for (auto& row : this->graph) {
        for (auto& element : row) {
            element += 1;
        }
    }
    return result;
}
// --g1
Graph& Graph::operator--() {
    for (auto& row : this->graph) {
        for (auto& element : row) {
            element -= 1;
        }
    }
    return *this;
}
// g1--
Graph Graph::operator--(int) {
    Graph result = *this;
    for (auto& row : this->graph) {
        for (auto& element : row) {
            element -= 1;
        }
    }
    return result;
}
void Graph::printGraph() {
    int numVertices = graph.size();
    int numEdges = 0;

    // Count the number of edges
    for (size_t i = 0; i < graph.size(); ++i) {
        for (size_t j = i + 1; j < graph[i].size(); ++j) {
            if (graph[i][j] != 0) {
                numEdges++;
            }
            if (graph[j][i] != 0) { 
                numEdges++;
            }
        }
    }
    // For undirected graphs, divide by 2 since each edge is counted twice
    if (!isDirected()) {
        numEdges /= 2;
    }
    cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges." << endl;
}

size_t Graph::size() const {
    return (size_t)graph.size();
}

const vector<vector<int>>& Graph::getMatrix() const {
    return graph;
}

bool Graph::isDirected() {
    for (size_t i = 0; i < graph.size(); ++i) {
        for (size_t j = i + 1; j < graph[i].size(); ++j) {
            // If there's an edge from i to j or from j to i, but not both, the graph is directed
            if ((graph[i][j] != 0 && graph[j][i] == 0) || (graph[i][j] == 0 && graph[j][i] != 0)) {
                return true;
            }
            // If both edges exist but have different weights, the graph is directed
            if (graph[i][j] != graph[j][i]) {
                return true;
            }
        }
    }
    return false;
}