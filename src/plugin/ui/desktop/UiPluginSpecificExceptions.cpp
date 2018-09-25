#include "UiPluginSpecificExceptions.h"

NonMatchingDependencyTypeException::NonMatchingDependencyTypeException(std::string_view errorMessage)
	: std::runtime_error(errorMessage.data())
{}
