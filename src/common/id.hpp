#ifndef COMMON_ID_T_HPP
#define COMMON_ID_T_HPP
#include <atomic>

namespace tl {
namespace common {

class Id {
public:
    using IdValueType = uint64_t;
    Id() : id_(KAutoIncId.fetch_add(1)){};

    IdValueType GetId() const { return id_; }

private:
    const IdValueType id_;
    static std::atomic<IdValueType> KAutoIncId;
};
}  // namespace common
}  // namespace tl
#endif