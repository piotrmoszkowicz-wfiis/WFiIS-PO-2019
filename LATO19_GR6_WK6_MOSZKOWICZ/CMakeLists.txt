cmake_minimum_required(VERSION 3.0.0)
project(asdf VERSION 0.1.0)

add_executable(
  asdf printtest.cpp
  ConsolePrinter.h
  ConsolePrinter.cpp
  StringConvertable.h
  AttColor.h
  AttFormat.h
  MyText.h
  MyText.cpp
  MyLine.h
  MyLine.cpp
)

add_compile_options(
	-Wall
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
