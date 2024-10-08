file(GLOB SceneSrc
        "*.hpp"
        "*.h"
        "*.cpp"
        )

# Compile cpp files
add_executable(SRE-Scenegraph ${SceneSrc})
target_link_libraries(SRE-Scenegraph ${SGE_LIBRARIES})

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

IF (WIN32)
    # Copy dll files to ${CMAKE_CURRENT_BINARY_DIR}/Debug
    file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION Debug)
    file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION Release)
    file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION .)

    # Set working directory to ${CMAKE_CURRENT_BINARY_DIR}/Debug
    set_target_properties(SRE-Scenegraph PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Debug)
ENDIF(WIN32)