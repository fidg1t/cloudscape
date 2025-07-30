add_executable(Nimbus
  src/main.cpp
)

target_link_libraries(Nimbus PRIVATE Cloudscape)
target_include_directories(Nimbus PRIVATE ${PROJECT_SOURCE_DIR}/Nimbus/include)

 