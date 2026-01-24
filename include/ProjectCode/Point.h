#pragma once

#include "ProjectCode_API.h"

class Point
{
public:

	// On Windows, at least one API must be exported in order for a library to be
	// generated. Without this, UnitTestExe will complain about ProjectCode.lib
	// not existing, which thwarts building this starter code out of the box.
	//
	// Remove this API and comment once you've implemented real content for this class.
    PROJECTCODE_API void PlaceholderApiFunction();
};
