cmake_minimum_required(VERSION 3.12)
project(near-lang)

set(CMAKE_CXX_STANDARD 20)


set(SOURCES
    main.cpp
    src/Error/errorHandler.cpp
    src/Stream/fileStream.cpp
    src/Scanner/Scanner.cpp
    src/Token/token.cpp
)


add_executable(near-lang ${SOURCES})
