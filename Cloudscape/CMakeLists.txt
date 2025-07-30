project(Cloudscape)

file(GLOB_RECURSE CLOUDSCAPE_HEADERS CONFIGURE_DEPENDS include/*.h)
file(GLOB_RECURSE CLOUDSCAPE_SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_library(Cloudscape SHARED ${CLOUDSCAPE_HEADERS} ${CLOUDSCAPE_SOURCES})

target_include_directories(Cloudscape PUBLIC include)

# defines the macro for dll exporting / importing
target_compile_definitions(Cloudscape PRIVATE ENGINE_EXPORTS)

# Set output name for dll (i like lowercase :> )

set_target_properties(Cloudscape PROPERTIES OUTPUT_NAME "cloudscape")