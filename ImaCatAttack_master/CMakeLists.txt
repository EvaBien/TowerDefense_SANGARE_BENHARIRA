# Requirement

cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 14)

# ---------------------------------------- PROJECT FILES
# récupère tous les fichiers sources
project(itd_eva)
set(MY_SOURCES src/Building.cpp src/Tile.cpp src/CatMonster.cpp src/Entity.cpp src/Game.cpp src/Map.cpp src/TextureController.cpp src/Tower.cpp src/Tower_Defense_Main.cpp src/Window.cpp)

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
# Search directories for .h files
include_directories( 
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
