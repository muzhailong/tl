#include "common/utils.hpp"
#include "syntax/parser.hpp"

namespace tl {

namespace common {

std::string GenerateName() {
    static std::atomic<size_t> inc(0);
    return std::string("$") + std::to_string(inc.fetch_add(1));
}

std::string TokenId2Str(int64_t token_id) {
    static std::unordered_map<int64_t, std::string> table{
        {SY_MUL , "*"},  {SY_DIV , "/"}, {SY_PLUS , "+"}, {SY_MINUS , "-"},
        {SY_EQUAL, "="}, {SY_CEQ, "=="}, {SY_CNE, "!="},  {SY_CGT, ">"},
        {SY_CLT, "<"},   {SY_CGE, ">="}, {SY_CLE, "<="}};
    if (table.count(token_id)) {
        return table[token_id];
    }
    throw "There not exists " + std::to_string(token_id);
}

}  // namespace common
}  // namespace tl
