# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\real0\CLionProjects\OOP6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\real0\CLionProjects\OOP6\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OOP6.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/OOP6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OOP6.dir/flags.make

CMakeFiles/OOP6.dir/test.cpp.obj: CMakeFiles/OOP6.dir/flags.make
CMakeFiles/OOP6.dir/test.cpp.obj: CMakeFiles/OOP6.dir/includes_CXX.rsp
CMakeFiles/OOP6.dir/test.cpp.obj: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\real0\CLionProjects\OOP6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OOP6.dir/test.cpp.obj"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OOP6.dir\test.cpp.obj -c C:\Users\real0\CLionProjects\OOP6\test.cpp

CMakeFiles/OOP6.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OOP6.dir/test.cpp.i"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\real0\CLionProjects\OOP6\test.cpp > CMakeFiles\OOP6.dir\test.cpp.i

CMakeFiles/OOP6.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OOP6.dir/test.cpp.s"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\real0\CLionProjects\OOP6\test.cpp -o CMakeFiles\OOP6.dir\test.cpp.s

# Object files for target OOP6
OOP6_OBJECTS = \
"CMakeFiles/OOP6.dir/test.cpp.obj"

# External object files for target OOP6
OOP6_EXTERNAL_OBJECTS =

OOP6.exe: CMakeFiles/OOP6.dir/test.cpp.obj
OOP6.exe: CMakeFiles/OOP6.dir/build.make
OOP6.exe: lib/libgtestd.a
OOP6.exe: lib/libgtest_maind.a
OOP6.exe: lib/libgtestd.a
OOP6.exe: CMakeFiles/OOP6.dir/linklibs.rsp
OOP6.exe: CMakeFiles/OOP6.dir/objects1.rsp
OOP6.exe: CMakeFiles/OOP6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\real0\CLionProjects\OOP6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OOP6.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OOP6.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OOP6.dir/build: OOP6.exe
.PHONY : CMakeFiles/OOP6.dir/build

CMakeFiles/OOP6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OOP6.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OOP6.dir/clean

CMakeFiles/OOP6.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\real0\CLionProjects\OOP6 C:\Users\real0\CLionProjects\OOP6 C:\Users\real0\CLionProjects\OOP6\cmake-build-debug C:\Users\real0\CLionProjects\OOP6\cmake-build-debug C:\Users\real0\CLionProjects\OOP6\cmake-build-debug\CMakeFiles\OOP6.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OOP6.dir/depend
