project(Cloudscape)

# Gather engine sources and headers
file(GLOB_RECURSE CLOUDSCAPE_HEADERS CONFIGURE_DEPENDS include/*.h)
file(GLOB_RECURSE CLOUDSCAPE_SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Add the engine library
add_library(Cloudscape SHARED ${CLOUDSCAPE_HEADERS} ${CLOUDSCAPE_SOURCES})

# Include engine headers
target_include_directories(Cloudscape PUBLIC include)

# Include SDL3 headers privately
target_include_directories(Cloudscape PRIVATE ${CMAKE_SOURCE_DIR}/vendor/SDL3/include)

# Link SDL3 privately to the engine
target_link_libraries(Cloudscape PRIVATE SDL3)

# Defines the macro for dll exporting / importing
target_compile_definitions(Cloudscape PRIVATE CL_ENGINE)

# Set output name for dll (I like lowercase :>)
set_target_properties(Cloudscape PROPERTIES OUTPUT_NAME "cloudscape")
