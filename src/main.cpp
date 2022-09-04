#include <iostream>
#include "common/node.hpp"
#include <fstream>
#include "common/dot.hpp"

extern std::shared_ptr<tl::common::Block> programBlock;
extern int yyparse();
extern FILE* yyin;

int main(int argc, char **argv)
{
    FILE*fp = fopen(argv[1],"r");
    yyin = fp;
    yyparse();

    std::ofstream of("1.dot",std::ios::ate);
    tl::common::DotHelper helper{of,"grammer","node_"};
    programBlock->Print(helper);
    return 0;
}