cmake_minimum_required(VERSION 3.7)

project(myapp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_gfx REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${SDL2_MIXER_INCLUDE_DIR}
    ${SDL2_TTF_INCLUDE_DIR}
    ${SDL2_GFX_INCLUDE_DIR}
)

file(GLOB MYSOURCE
    "src/*.hpp"
    "src/*.cpp"
)

add_executable(myapp WIN32 ${MYSOURCE})

target_link_libraries(myapp ${SDL2MAIN_LIBRARY}
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_MIXER_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
    ${SDL2_GFX_LIBRARIES}
)

install(TARGETS myapp DESTINATION ${CMAKE_SOURCE_DIR}/bin)
