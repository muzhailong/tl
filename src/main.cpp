#include <llvm/ADT/ScopedHashTable.h>
#include <llvm/Support/raw_ostream.h>
#include <mlir/IR/MLIRContext.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "clipp.h"
#include "common/dot.hpp"
#include "common/node.hpp"

namespace fs = std::filesystem;

extern std::shared_ptr<tl::common::ModuleNode> program;
extern int yyparse();
extern FILE* yyin;

std::string filename;

void DumpMLIR(llvm::raw_fd_ostream& out) {
    mlir::MLIRContext context;
    context.getOrLoadDialect<tl::dialect::TLDialect>();
    mlir::OpBuilder builder(&context);
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value> symbol_table;
    program->CodeGen(builder, symbol_table);
    mlir::OwningOpRef<mlir::ModuleOp> module = program->GetModule().value();
    module->print(out);
}

int main(int argc, char** argv) {
    std::string in_file = "";
    bool dump_ast = false;
    std::string ast_file = "";
    bool dump_mlir = false;
    std::string mlir_file = "";

    auto cli =
        (clipp::value("input file", in_file),
         clipp::option("-a", "--dump_ast").set(dump_ast).doc("dump ast"),
         clipp::option("-m", "--dump_mlir").set(dump_mlir).doc("dump mlir"),
         clipp::option("-af", "--ast_file") &
             clipp::value("ast output file", ast_file),
         clipp::option("-mf", "--mlir_file") &
             clipp::value("mlir output file", mlir_file));

    if (!clipp::parse(argc, argv, cli))
        std::cout << clipp::make_man_page(cli, argv[0]);

    filename = std::string(in_file);
    if (fs::exists(filename)) {
        filename = fs::canonical(filename).string();
        FILE* fp = fopen(filename.c_str(), "r");
        yyin = fp;
    }
    yyparse();

    if (dump_ast) {
        std::ofstream of(ast_file.size() > 0 ? ast_file : "tl_ast.dot",
                         std::ios::ate);
        tl::common::DotHelper helper{of, "grammer", "node_"};
        program->Print(helper);
    }

    if (dump_mlir) {
        std::error_code ec;
        llvm::raw_fd_ostream out(mlir_file.size() > 0 ? mlir_file : "-", ec);
        if (!ec) {
            DumpMLIR(out);
        }
    }
    return 0;
}