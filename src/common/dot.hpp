#ifndef COMMON_DOT_HPP
#define COMMON_DOT_HPP

#include <iostream>
#include <sstream>
#include <type_traits>

#include "common/id.hpp"

namespace tl {
namespace common {

class DotHelper : public Id {
public:
    DotHelper(std::ostream& out, const std::string& graph_name,
              const std::string& prefix = "node_")
        : out_(out), prefix_(prefix) {
        out_ << "digraph " << graph_name << "{\n";
    }

    void WriteEdge(const std::string& inode, const std::string& onode,
                   const std::string& label = "") {
        out_ << "\t" << inode << "->" << onode;
        if (!label.empty()) {
            out_ << "[label=\"" << label << "\"]";
        }
        out_ << "\n";
    }

    template <typename T,
              typename = typename std::enable_if_t<std::is_integral<T>::value>>
    void WriteEdge(T inode, T onode, const std::string& label = "") {
        std::stringstream ss;
        ss << prefix_ << inode;
        std::string is = ss.str();
        ss.str("");
        ss << prefix_ << onode;
        std::string os = ss.str();
        WriteEdge(is, os, label);
    }

    void WriteNode(const std::string& node, const std::string& label = "") {
        if (!label.empty()) {
            out_ << "\t" << node << "[ label=\"" << label << "\"]\n";
        }
    }

    template <typename T,
              typename = typename std::enable_if_t<std::is_integral<T>::value>>
    void WriteNode(T node, const std::string& label = "") {
        std::stringstream ss;
        ss << prefix_ << node;
        std::string ns = ss.str();
        WriteNode(ns, label);
    }

    ~DotHelper() {
        out_ << "}\n";
        out_.flush();
    }

private:
    std::ostream& out_;
    const std::string prefix_;
};

}  // namespace common
}  // namespace tl
#endif
