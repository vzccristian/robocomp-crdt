//
// Created by crivac on 23/11/18.
//

#ifndef PROJECT_GRAPH_H
#define PROJECT_GRAPH_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGLViewer/qglviewer.h>
#include <unordered_map>
#include <any>
#include <QGraphicsEllipseItem>
#include <string>
#include <stdlib.h>


class Graph {
public:
    using Attribs = std::unordered_map<std::string, std::any>;
    using Neighs = std::unordered_map<std::uint32_t, Attribs>;
    using Value = std::tuple<Attribs, Neighs>;
    using Nodes = std::unordered_map<std::uint32_t, Value>;

    typename Nodes::iterator begin() { return nodes.begin(); };

    typename Nodes::iterator end() { return nodes.end(); };

    typename Nodes::const_iterator begin() const { return nodes.begin(); };

    typename Nodes::const_iterator end() const { return nodes.begin(); };

    size_t size() const { return nodes.size(); };

    void addNode(std::uint32_t id) {
        Value v;
        nodes.insert(std::pair(id, v));
    };

    void addEdge(std::uint32_t from, std::uint32_t to) {
        Attribs a;
        std::get<1>(nodes[from]).insert(std::pair(to, a));
    };

    void addNodeAttribs(std::uint32_t id, const Attribs &att) {
        for (auto &[k, v] : att)
            std::get<0>(nodes[id]).insert(std::pair(k, v));
    };

    void addEdgeAttribs(std::uint32_t from, std::uint32_t to, const Attribs &att) {
        auto &edgeAtts = std::get<1>(nodes[from]).at(to);
        for (auto &[k, v] : att)
            edgeAtts.insert(std::pair(k, v));
    };


private:
    Nodes nodes;
};


#endif //PROJECT_GRAPH_H
