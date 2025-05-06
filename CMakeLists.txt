cmake_minimum_required(VERSION 3.10)

# Project name and version
project(infotainment-player VERSION 1.0)

# Enable C++11
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2)

# Find GStreamer
find_package(PkgConfig REQUIRED)
pkg_check_modules(GST_BASE REQUIRED IMPORTED_TARGET gstreamer-base-1.0)
pkg_check_modules(GST_AUDIO REQUIRED IMPORTED_TARGET gstreamer-audio-1.0)

# Source directory
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

# Add resources
set(RESOURCES
    ${CMAKE_SOURCE_DIR}/resources.qrc
)

# Add source files
file(GLOB SOURCES
    "${SOURCE_DIR}/*.cpp"
)

# Create executable and link Qt6 Core
add_executable(${PROJECT_NAME} ${SOURCES} ${RESOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE 
    Qt6::Core 
    Qt6::Gui 
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
    PkgConfig::GST_BASE
    PkgConfig::GST_AUDIO
)

# Add include directories
include_directories(
    ${SOURCE_DIR}
    ${Qt6Core_INCLUDE_DIRS}
    ${Qt6Gui_INCLUDE_DIRS}
    ${Qt6Qml_INCLUDE_DIRS}
    /opt/homebrew/Cellar/gstreamer/1.26.1/include/gstreamer-1.0
    /opt/homebrew/Cellar/glib/2.84.1/include
    /opt/homebrew/Cellar/glib/2.84.1/include/glib-2.0
    /opt/homebrew/Cellar/glib/2.84.1/lib/glib-2.0/include
    /Applications/VLC.app/Contents/MacOS/include
)

# Link directories
link_directories(
    /opt/homebrew/Cellar/gstreamer/1.26.1/lib
    /opt/homebrew/Cellar/glib/2.84.1/lib
    /Applications/VLC.app/Contents/MacOS/lib
)

# Set compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")

# Install rules
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)

# Add custom target for cleaning build files
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}"
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${PROJECT_BINARY_DIR}"
    COMMENT "Cleaning build directories"
)

# Add custom target for rebuilding
add_custom_target(rebuild
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}"
    COMMAND ${CMAKE_COMMAND} -E remove_directory "${PROJECT_BINARY_DIR}"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}"
    COMMAND ${CMAKE_COMMAND} -E chdir "${CMAKE_BINARY_DIR}" ${CMAKE_COMMAND} ..
    COMMAND ${CMAKE_COMMAND} --build "${CMAKE_BINARY_DIR}" --config Release
    COMMENT "Rebuilding project"
)
