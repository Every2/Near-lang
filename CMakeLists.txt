cmake_minimum_required(VERSION 3.12)
project(near-lang)

set(CMAKE_CXX_STANDARD 20)


set(SOURCES
    main.cpp
    src/Error/errorHandler.hpp
    src/Stream/filestream.hpp
    src/Scanner/Scanner.hpp
    src/Token/token.hpp
        include/stringTrim.hpp
        include/stringSplit.hpp
)


add_executable(near-lang ${SOURCES})
