#pragma once

#include <dragon/backend.hpp>

///
/// @brief Error namespace. Contains the ErrorInfo class.
///
namespace Dragon::Error {
	struct ErrorInfo {
		DgString code;
		DgString message;
	};
}