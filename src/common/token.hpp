#ifndef COMMON_TOKEN_HPP
#define COMMON_TOKEN_HPP

#include <cstdint>
#include <iostream>
#include <variant>

#include "common/utils.hpp"

namespace tl {
namespace common {

class TokenInfo {
public:
    using TokenIdType = uint64_t;

    TokenInfo(TokenIdType token, const std::string& ident)
        : tokenId_(token), ident_(ident) {}
    TokenInfo(TokenIdType token) : tokenId_(token), ident_(GenerateName()) {}

    template <typename Tp>
    void SetValue(Tp value) {
        value_ = value;
    }

    template <typename Tp>
    Tp GetValue() {
        return std::get<Tp>(value_);
    }

    std::string GetIdent() const { return ident_; }

    TokenIdType GetTokenId() const { return tokenId_; }

private:
    TokenIdType tokenId_;
    std::variant<int64_t,     // integer value
                 double,      // float value
                 std::string  // str value
                 >
        value_;

    const std::string ident_;
};


}  // namespace common
}  // namespace tl
#endif