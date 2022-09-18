#ifndef COMMON_Location_HPP
#define COMMON_Location_HPP

#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>

#include "common/status.hpp"
#include "mlir/IR/Value.h"

namespace tl {
namespace common {

class Location {
public:
    using LocationElementType = int64_t;
    static const LocationElementType kUnknown = -1;
    Location()
        : first_line(kUnknown),
          last_line(kUnknown),
          first_column(kUnknown),
          last_column(kUnknown) {}
    Location(const std::string& filename, LocationElementType first_line,
             LocationElementType last_line, LocationElementType first_column,
             LocationElementType last_column)
        : filename(filename),
          first_line(first_line),
          last_line(last_line),
          first_column(first_column),
          last_column(last_column) {}
    bool IsUnknown() const;
    Status UpdateLocation(const Location& pos);
    Status UpdateLocation(std::shared_ptr<Location> pos);
    Status UpdateLocation(Location* pos);
    mlir::Location ToMLIRLocation(mlir::MLIRContext* context) const;
    std::string ToString() const;

private:
    bool IsUnknown(LocationElementType p) const { return p == kUnknown; }
    std::optional<std::string> filename;
    LocationElementType first_line;
    LocationElementType last_line;
    LocationElementType first_column;
    LocationElementType last_column;
};

}  // namespace common
}  // namespace tl

#endif