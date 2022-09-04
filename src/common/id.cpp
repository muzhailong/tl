#include "common/id.hpp"
namespace tl {
namespace common {

std::atomic<Id::IdValueType> Id::KAutoIncId{10000};

}
}  // namespace tl
