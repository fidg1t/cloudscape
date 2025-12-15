project(Nimbus)

file(GLOB_RECURSE NIMBUS_HEADERS CONFIGURE_DEPENDS include/*.h)
file(GLOB_RECURSE NIMBUS_SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(Nimbus ${NIMBUS_SOURCES} ${NIMBUS_HEADERS})

target_link_libraries(Nimbus PRIVATE Cloudscape)
target_include_directories(Nimbus PRIVATE include)