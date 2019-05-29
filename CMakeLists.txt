# Requirement

cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)

# ---------------------------------------- PROJECT FILES
# récupère tous les fichiers sources
project(itd_eva)
file(
    GLOB_RECURSE
    MY_SOURCES
    src
)

# ---------------------------------------- FIND DEPENDENCIES

find_package(OpenGL REQUIRED)

#version linux VS windows
if (NOT WIN32)
    find_package(SDL2 REQUIRED)
else()
    set(SDL2_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/lib/SDL2-2.0.9/include)
    set(SDL2_LIBRARIES ${CMAKE_SOURCE_DIR}/lib/SDL2-2.0.9/lib/windows_x86/SDL2.lib;${CMAKE_SOURCE_DIR}/lib/SDL2-2.0.9/lib/windows_x86/SDL2main.lib)
endif()

# ----------------------------------------- INCLUDE DIRECTORIES
# récupère toutes les librairies
include_directories( # Search directories for .h files
    ${OPENGL_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIRS}
    include
)

# ------------------------------------------- BUILD PROJECT
add_executable(${PROJECT_NAME} ${MY_SOURCES})
target_link_libraries(
    ${PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${SDL2_LIBRARIES}
)

if (UNIX) # Use dynamic linking library and maths
    target_link_libraries(${PROJECT_NAME} -ldl -lm)
endif()

#gère affichage dynamique en copiant dll dans dossier de l'exécutable
if (WIN32)
    # Copy dynamic library .dll files to build folder
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PROJECT_SOURCE_DIR}/lib/SDL2-2.0.9/lib/windows_x86/SDL2.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()