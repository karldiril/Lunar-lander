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
target_link_libraries(Lander
        raylib
        "-framework CoreVideo"
        "-framework IOKit"
        "-framework Cocoa"
        "-framework GLUT"
        "-framework OpenGL"
)