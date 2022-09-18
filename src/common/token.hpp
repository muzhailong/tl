#ifndef COMMON_TOKEN_HPP
#define COMMON_TOKEN_HPP

#include <cstdint>
#include <iostream>
#include <variant>

#include "common/location.hpp"
#include "common/utils.hpp"

namespace tl {
namespace common {

class TokenInfo {
public:
    using TokenIdType = uint64_t;

    TokenInfo(TokenIdType token, const std::string& ident)
        : tokenId_(token), ident_(ident) {}
    TokenInfo(TokenIdType token) : tokenId_(token), ident_(GenerateName()) {}

    void SetLocation(const std::string& filename,
                     Location::LocationElementType r1,
                     Location::LocationElementType r2,
                     Location::LocationElementType c1,
                     Location::LocationElementType c2) {
        loc_ = {filename, r1, r2, c1, c2};
    }

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
    Location GetLocation() const { return loc_; }

private:
    TokenIdType tokenId_;
    std::variant<int64_t,     // integer value
                 double,      // float value
                 std::string  // str value
                 >
        value_;

    const std::string ident_;

    Location loc_;
};


}  // namespace common
}  // namespace tl
#endif