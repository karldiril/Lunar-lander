cmake_minimum_required(VERSION 3.15)
project(Lander)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
link_directories(lib)

add_executable(Lander main.cpp
        Lander.h
        Lander.cpp
        SiteAtterrissage.cpp
        SiteAtterrissage.h
        Sprite.h
        Sprite.cpp
        InterfaceLander.h
        InterfaceLander.cpp
        Constantes.h
        Constantes.cpp
        Montagnes.h
        Ligne.h
        Montagnes.cpp)


if(WIN32)
# --- CONFIGURATION WINDOWS ---
    target_link_libraries(Lander 
        raylib
        winmm
        gdi32
        shell32
        user32
        opengl32
    )

elseif(APPLE)
    # --- CONFIGURATION MACOS ---
    target_link_libraries(Lander 
        raylib
        "-framework CoreVideo"
        "-framework IOKit"
        "-framework Cocoa"
        "-framework GLUT"
        "-framework OpenGL"
    )
else()
    # --- CONFIGURATION LINUX ---
    target_link_libraries(Lander raylib GL m pthread dl rt X11)
endif()


# On définit où se trouve le dossier assets à la racine du projet
set(ASSETS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets")


add_custom_command(TARGET Lander POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${ASSETS_DIR}"
    "$<TARGET_FILE_DIR:Lander>/assets"
)