#pragma once

#include <string>

namespace Dragon::Error {
	enum ErrorType {
		GENERAL = 0, 
		SPEC_ERROR = 1, 
		NONOPTIMAL = 2,
		FATAL = 3
	};

	enum ErrorSeverity {
		STATUS = 0,
		DEBUG = 1,
		WARNING = 2,
		ERR = 3
	};

	enum System {
		GRAPHICS = 0,
		AUDIO = 1,
		PHYSICS = 2,
		PARTICLE = 3,
		COMPUTE = 4,
		XR = 5,
		METAL = 6,
		NETWORK = 7, 
		INTERNAL = 8
	};
	
	struct ErrorInfo {
		uint16_t code;
		std::string message;
		ErrorType* type;
		ErrorSeverity* severity;
		System* system;
	};
}