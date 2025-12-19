project(Nimbus)

file(GLOB_RECURSE NIMBUS_HEADERS CONFIGURE_DEPENDS include/*.h)
file(GLOB_RECURSE NIMBUS_SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE NIMBUS_SHADERS CONFIGURE_DEPENDS shader/*.vert shader/*.frag)
file(GLOB_RECURSE CLOUDSCAPE_SHADERS
  CONFIGURE_DEPENDS
  ${CMAKE_SOURCE_DIR}/Cloudscape/shader/*.vert
  ${CMAKE_SOURCE_DIR}/Cloudscape/shader/*.frag
)

add_executable(Nimbus
  ${NIMBUS_SOURCES}
  ${NIMBUS_HEADERS}
  ${NIMBUS_SHADERS}
)

source_group("Shaders" FILES ${NIMBUS_SHADERS})

add_custom_command(TARGET Nimbus POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
          ${CMAKE_CURRENT_SOURCE_DIR}/shader
          $<TARGET_FILE_DIR:Nimbus>/shader

  COMMAND ${CMAKE_COMMAND} -E copy_directory
          ${CMAKE_SOURCE_DIR}/Cloudscape/shader
          $<TARGET_FILE_DIR:Nimbus>/shader
)

# ImGui sources
set(IMGUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui)

set(IMGUI_SOURCES
  ${IMGUI_DIR}/imgui.cpp
  ${IMGUI_DIR}/imgui_draw.cpp
  ${IMGUI_DIR}/imgui_widgets.cpp
  ${IMGUI_DIR}/imgui_tables.cpp
  ${IMGUI_DIR}/imgui_demo.cpp
  ${IMGUI_DIR}/backends/imgui_impl_sdl3.cpp
  ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

add_library(imgui STATIC ${IMGUI_SOURCES})

target_include_directories(imgui PUBLIC
  ${IMGUI_DIR}
  ${IMGUI_DIR}/backends
)

target_link_libraries(imgui
  PUBLIC
    SDL3::SDL3
    glad
)

target_link_libraries(Nimbus
  PRIVATE
    Cloudscape
    imgui
    glad
)

target_include_directories(Nimbus PRIVATE include)
