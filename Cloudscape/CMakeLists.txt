project(Cloudscape)

file(GLOB_RECURSE CLOUDSCAPE_HEADERS CONFIGURE_DEPENDS include/*.h)
file(GLOB_RECURSE CLOUDSCAPE_SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_library(Cloudscape SHARED
  ${CLOUDSCAPE_HEADERS}
  ${CLOUDSCAPE_SOURCES}
)

add_subdirectory(vendor/SDL3 EXCLUDE_FROM_ALL)

set_property(
  DIRECTORY vendor/SDL3
  PROPERTY FOLDER "Vendor"
)

target_include_directories(Cloudscape
  PUBLIC
    include
)

target_link_libraries(Cloudscape
  PRIVATE
    SDL3::SDL3
)

target_compile_definitions(Cloudscape PRIVATE CL_ENGINE)

set_target_properties(Cloudscape
  PROPERTIES OUTPUT_NAME "cloudscape"
)
