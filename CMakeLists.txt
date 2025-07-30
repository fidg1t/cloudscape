cmake_minimum_require(VERSION 3.16)
project(CloudscapeProject)

# Setup Output Dirs
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Sub directories
add_subdirectory(Cloudscape)
add_subdirectory(Nimbus)