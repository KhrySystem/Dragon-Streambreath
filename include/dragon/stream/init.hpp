#pragma once

#include <dragon/dg_backend.hpp>

namespace Dragon::Stream {
	/// @brief Initializes the Streambreath submodule. Not meant to be called by an outside source.
	/// @return
	DGAPI void init();
	/// @brief Terminates the Streambreath submodule. Not meant to be called by an outside source.
	/// @return
	DGAPI void terminate();
}
