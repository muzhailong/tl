#include <sstream>

#include "common/location.hpp"

namespace tl {
namespace common {

bool Location::IsUnknown() const {
    return !filename.has_value() || IsUnknown(first_line) ||
           IsUnknown(last_line) || IsUnknown(first_column) ||
           IsUnknown(last_column);
}

Status Location::UpdateLocation(const Location& pos) {
    // assert((!filename.has_value() || !pos.filename.has_value() ||
    //         filename.value() == pos.filename.value()) &&
    //        "filename is different!");
    if (!filename.has_value() && pos.filename.has_value()) {
        filename = pos.filename.value();
    }

    if (IsUnknown(first_line)) {
        first_line = pos.first_line;
        first_column = pos.first_column;
    } else if (!IsUnknown(pos.first_line)) {
        if (pos.first_line < first_line) {
            first_line = pos.first_line;
            first_column = pos.first_column;
        }
    }

    if (IsUnknown(last_line)) {
        last_line = pos.last_line;
        last_column = pos.last_column;
    } else if (!IsUnknown(pos.last_line)) {
        if (pos.last_line > last_line) {
            last_line = pos.last_line;
            last_column = pos.last_column;
        }
    }

    return Status::TL_OK;
}

Status Location::UpdateLocation(std::shared_ptr<Location> pos) {
    return UpdateLocation(*pos);
}

Status Location::UpdateLocation(Location* pos) { return UpdateLocation(*pos); }

mlir::Location Location::ToMLIRLocation(mlir::MLIRContext* context) const {
    return mlir::FileLineColLoc::get(
        context, mlir::StringRef(filename->c_str()), first_line, first_column);
}

std::string Location::ToString() const {
    std::stringstream ss;
    if (filename.has_value()) {
        ss << filename.value();
        ss << ":" << first_line << ":" << first_column;
    }
    return ss.str();
}

}  // namespace common
}  // namespace tl
