cmake_minimum_required(VERSION 3.0.0)
project(asdf VERSION 0.1.0)

add_executable(
  asdf vtest.cpp
  Data.h
  ElData.h
  Visitor.h
  AccumulatingVisitor.h
  AccumulatingVisitor.cpp
  PrintingVisitor.h
  PrintingVisitor.cpp
)

add_compile_options(
	-Wall
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
