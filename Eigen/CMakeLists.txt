cmake_minimum_required(VERSION 2.8)

project(eigen)

set(SOURCES 
    src/main.cpp
    src/def.cpp
    src/print.cpp
    src/eigen.cpp
    src/f.cpp
)

add_executable(eigen ${SOURCES})

target_include_directories(eigen
    PRIVATE
    	${PROJECT_SOURCE_DIR}/include
)
