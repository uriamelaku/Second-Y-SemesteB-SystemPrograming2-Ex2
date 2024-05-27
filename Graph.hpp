// ooriamelaku@gmail.com
// 208734889
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <stdexcept>

namespace ariel {

    class Graph {
    private:
        std::vector<std::vector<int>> graph;

    public:

        
        void loadGraph(std::vector<std::vector<int>> graph);

        // to print the graph
        void printGraph();
        std::string toString() const;
        friend std::ostream& operator<<(std::ostream& os, const Graph& g);

        // method from Ex1
        size_t size() const;
        const std::vector<std::vector<int>>& getMatrix() const;
        bool isDirected();

        // method of +/-
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);
        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);
        Graph operator+() const;
        Graph operator-() const;

        // method of * - /
        Graph& operator*=(int scalar);
        Graph operator*(int scalar) const;
        Graph operator/(double scalar) const;
        Graph& operator/=(double scalar);
        Graph operator*(const Graph& other) const;

        // method of == / !=
        int operator==(const Graph& other) const;
        int operator!=(const Graph& other) const;

        // help method
        size_t numEdges() const;

        // method of - if a graph inside another
        int isSubsetOf(const Graph& other) const;
        int isProperSubsetOf(const Graph& other) const;

        // method of < / >
        bool operator<(const Graph& other) const;
        int operator>(const Graph& other) const;
        int operator<=(const Graph& other) const;
        int operator>=(const Graph& other) const;

        // method of ++ / --
        Graph& operator++();
        Graph operator++(int);
        Graph& operator--();
        Graph operator--(int);

    };
    //std::ostream& operator<<(std::ostream& os, const Graph& g);

}

#endif