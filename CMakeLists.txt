cmake_minimum_required(VERSION 3.13)
project(StateOne)

set(CMAKE_CXX_STANDARD 14)

add_executable(StateOne main.cpp src/advanceOne.cpp include/advanceOne.h
        testAbout/testCompile.cpp testAbout/testCompile.h testAbout/testCompile2.cpp
        src/ArrayPart.cpp include/ArrayPart.h include/BaseOnePart.h src/BaseOnePart.cpp include/StringPart.h src/StringPart.cpp src/ExerciseOne.cpp include/ExerciseOne.h include/FilePartOne.h src/FilePartOne.cpp noteAbout/linuxAbout.cpp noteAbout/shellCmd.cpp testAbout/testCompile2.h testAbout/testCompile3.h)