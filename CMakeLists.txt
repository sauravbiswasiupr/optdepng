CMake_Minimum_Required(VERSION 2.8.12)
Project(OptDePng C CXX)

Add_Executable(OptDePng
  optglobals.h
  optdepng.cpp
  optdepng.h
  test.cpp)
