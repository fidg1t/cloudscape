add_library(Cloudscape SHARED
  src/Engine.cpp
  include/Core.h
  include/Engine.h
)

target_include_directories(Cloudscape PUBLIC include)
target_compile_definitions(Cloudscape PRIVATE ENGINE_EXPORTS) # defines the macro for dll exporting / importing

# Set output name for dll (i like lowercase :> )

set_target_properties(Cloudscape PROPERTIES OUTPUT_NAME "cloudscape")