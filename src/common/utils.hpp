#ifndef COMMON_UTILS_HPP
#define COMMON_UTILS_HPP

#include <atomic>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

namespace tl {
namespace common {

std::string Vec2Str(const std::vector<std::string>& vec);

template <typename Tp>
std::string Vec2Str(const std::vector<Tp>& vec) {
    std::stringstream ss;
    ss << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i != 0) {
            ss << ", " << vec[i];
        } else {
            ss << vec[i];
        }
    }
    ss << "]";
    return ss.str();
}

// $1;
std::string GenerateName();

std::string TokenId2Str(int64_t token_id);

}  // namespace common
}  // namespace tl

#endif
