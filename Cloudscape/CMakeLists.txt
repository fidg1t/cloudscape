project(Cloudscape)

file(GLOB_RECURSE CLOUDSCAPE_HEADERS CONFIGURE_DEPENDS include/*.h)
file(GLOB_RECURSE CLOUDSCAPE_SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_library(Cloudscape SHARED
  ${CLOUDSCAPE_HEADERS}
  ${CLOUDSCAPE_SOURCES}
)

# Vendor libraries
add_subdirectory(vendor/SDL3 EXCLUDE_FROM_ALL)
add_subdirectory(vendor/glm  EXCLUDE_FROM_ALL)

add_library(glad STATIC
  vendor/glad/src/glad.c
)

target_include_directories(glad
  PUBLIC
    vendor/glad/include
)

# Hide vendor projects in VS
foreach(tgt
  SDL3-shared
  SDL3-static
  SDL_uclibc
  glm
  glad
)
  if (TARGET ${tgt})
    set_target_properties(${tgt} PROPERTIES FOLDER "Vendor")
  endif()
endforeach()


target_include_directories(Cloudscape
  PUBLIC
    include
)

target_link_libraries(Cloudscape
  PUBLIC
    glm::glm
  PRIVATE
    SDL3::SDL3
    glad
)

target_compile_definitions(Cloudscape PRIVATE CL_ENGINE)

set_target_properties(Cloudscape
  PROPERTIES OUTPUT_NAME "cloudscape"
)
