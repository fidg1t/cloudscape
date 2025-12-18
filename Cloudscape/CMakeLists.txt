project(Cloudscape)

file(GLOB_RECURSE CLOUDSCAPE_HEADERS CONFIGURE_DEPENDS include/*.h)
file(GLOB_RECURSE CLOUDSCAPE_SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE CLOUDSCAPE_SHADERS CONFIGURE_DEPENDS shader/*.vert shader/*.frag)

add_library(Cloudscape SHARED
  ${CLOUDSCAPE_HEADERS}
  ${CLOUDSCAPE_SOURCES}
  ${CLOUDSCAPE_SHADERS}
)

# Vendor libs
add_subdirectory(vendor/SDL3 EXCLUDE_FROM_ALL)
add_subdirectory(vendor/glm  EXCLUDE_FROM_ALL)
add_subdirectory(vendor/spdlog EXCLUDE_FROM_ALL)

add_library(glad STATIC vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC vendor/glad/include)

# Hide vendor projects
foreach(tgt SDL3-shared SDL3-static SDL_uclibc glm glad spdlog)
  if (TARGET ${tgt})
    set_target_properties(${tgt} PROPERTIES FOLDER "Vendor")
  endif()
endforeach()

source_group("Shaders" FILES ${CLOUDSCAPE_SHADERS})

add_custom_command(TARGET Cloudscape POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
          ${CMAKE_CURRENT_SOURCE_DIR}/shader
          $<TARGET_FILE_DIR:Cloudscape>/shader
)

target_include_directories(Cloudscape PUBLIC include)

target_link_libraries(Cloudscape
  PUBLIC
    glm::glm
    spdlog::spdlog
  PRIVATE
    SDL3::SDL3
    glad
)

target_compile_definitions(Cloudscape PRIVATE CL_ENGINE)
set_target_properties(Cloudscape PROPERTIES OUTPUT_NAME "cloudscape")
