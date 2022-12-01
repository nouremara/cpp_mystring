# Nour Ahmed
# Matrikal-Nr.: 5200991
# Assignment 1 – Own string Class

#========================================================================
#  @file      : CMakeLists.txt
#  @brief     : Simple CMAKE file used to build the project.
#  @author    : Nour Ahmed
#  @email     : nahmed@stud.hs-bremen.de, nour
#  @repo      : https://github.com/nouremara/cpp_mystring
#  @createdOn : 01.12.2022
#  @version   : 1.0.0
# ========================================================================

# To build the project using CMake:
#  * first make sure CMake is installed on your system.
#  * in a new terminal execute the following comands:
#     cd <path/to/project/folder>
#     mkdir build
#     cd build
#     cmake ..
#     cmake --build .

cmake_minimum_required (VERSION 3.8)
# project specific logic here.
project ("NourUtilString")

# Add source to this project executable.
add_executable (NourUtilString "main.cpp" "utilstring.cpp" "utilstring.h")

# TODO: Add tests and install targets if needed.