
file(GLOB ParticleSystemSrc
        "*.hpp"
        "*.h"
        "*.cpp"
        )

# Compile cpp files
add_executable(SRE-ParticleSystem ${ParticleSystemSrc})
target_link_libraries(SRE-ParticleSystem ${SGE_LIBRARIES})

# copy files to dest
file(COPY particle-pack-01 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

IF (WIN32)
    # Copy dll files to ${CMAKE_CURRENT_BINARY_DIR}/Debug
    file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

    # Set working directory to ${CMAKE_CURRENT_BINARY_DIR}/Debug
    set_target_properties(SRE-ParticleSystem PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Debug)
ENDIF(WIN32)
