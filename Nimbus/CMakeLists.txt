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



target_link_libraries(Nimbus
  PRIVATE
    Cloudscape
    glad        # only if Nimbus calls OpenGL directly
)

target_include_directories(Nimbus PRIVATE include)
