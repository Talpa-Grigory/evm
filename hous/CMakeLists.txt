cmake_minimum_required(VERSION 2.8)

project(hous)

set(SOURCES 
    src/main.cpp
    src/def.cpp
    src/print.cpp
    src/hous.cpp
)

add_executable(hous ${SOURCES})

target_include_directories(hous
    PRIVATE
    	${PROJECT_SOURCE_DIR}/include
)
