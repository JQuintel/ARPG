set(_glfw3_HEADER_SEARCH_DIRS
        "${CMAKE_SOURCE_DIR}/include")

#Look for the correct libraries depending on how we're compiling
if (MSVC)
    set(_glfw3_LIB_SEARCH_DIRS "${CMAKE_SOURCE_DIR}/lib/msvc/")
endif (MSVC)

if (MINGW)
    set(_glfw3_LIB_SEARCH_DIRS "${CMAKE_SOURCE_DIR}/lib/mingw/")
endif (MINGW)

# Search for the header
FIND_PATH(GLFW3_INCLUDE_DIR "GLFW/glfw3.h"
        PATHS ${_glfw3_HEADER_SEARCH_DIRS})

# Search for the library
unset(GLFW3_LIBRARY)
FIND_LIBRARY(GLFW3_LIBRARY NAMES glfw3 glfw
        PATHS ${_glfw3_LIB_SEARCH_DIRS})
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLFW3 DEFAULT_MSG
        GLFW3_LIBRARY GLFW3_INCLUDE_DIR)
message(STATUS "GLFW3 Library = ${GLFW3_LIBRARY}")
message(STATUS "GLFW3 Include = ${GLFW3_INCLUDE_DIR}")


