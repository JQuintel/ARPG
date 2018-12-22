cmake_minimum_required(VERSION 3.10)
project(OpenGLTest)

if (MSVC)
    link_directories("${CMAKE_SOURCE_DIR}/lib/msvc")
endif ()

if (MINGW)
    link_directories("${CMAKE_SOURCE_DIR}/lib/mingw")
endif ()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)
find_package(GLFW3 REQUIRED)

add_library(GLAD "thirdparty/glad.c")

set(LIBS glfw3 opengl32 GLAD)
set(CMAKE_CXX_STANDARD 14)

configure_file("${CMAKE_SOURCE_DIR}/src/configuration/RootDir.h.in" "${CMAKE_SOURCE_DIR}/src/configuration/RootDir.h")

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/src/*.h)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

include_directories("${CMAKE_SOURCE_DIR}/src)" "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} ${LIBS})

# Create virtual folders to make it look nicer in VS
if (MSVC_IDE)
    # Macro to preserve source files hierarchy in the IDE
    macro(GroupSources curdir)
        file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${curdir} ${PROJECT_SOURCE_DIR}/${curdir}/*)

        foreach (child ${children})
            if (IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${curdir}/${child})
                GroupSources(${curdir}/${child})
            else ()
                string(REPLACE "/" "\\" groupname ${curdir})
                string(REPLACE "src" "Sources" groupname ${groupname})
                source_group(${groupname} FILES ${PROJECT_SOURCE_DIR}/${curdir}/${child})
            endif ()
        endforeach ()
    endmacro()

    # Run macro
    GroupSources(src)
endif ()

# Copy dlls
if (MSVC)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${PROJECT_SOURCE_DIR}/dlls"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif ()
