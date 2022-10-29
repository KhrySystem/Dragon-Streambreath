#pragma once

#include <dragon/backend.hpp>

namespace Dragon::Stream {
	/// @brief Initializes the Streambreath submodule. Not meant to be called by an outside source.
	/// @return
	DGAPI DgBool32 init();
	/// @brief Terminates the Streambreath submodule. Not meant to be called by an outside source.
	/// @return
	DGAPI void terminate();
}
