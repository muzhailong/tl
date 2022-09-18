#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "common/dot.hpp"
#include "common/node.hpp"
namespace fs = std::filesystem;

extern std::shared_ptr<tl::common::ModuleNode> program;
extern int yyparse();
extern FILE* yyin;

std::string filename;

int main(int argc, char **argv)
{
    filename = std::string(argv[1]);
    if (fs::exists(filename)) {
        filename = fs::canonical(filename).string();
        FILE* fp = fopen(filename.c_str(), "r");
        yyin = fp;
    }

    yyparse();

    std::ofstream of("1.dot",std::ios::ate);
    tl::common::DotHelper helper{of,"grammer","node_"};
    program->Print(helper);
    return 0;
}