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
CMAKE_SOURCE_DIR = C:\Users\real0\CLionProjects\OOP4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\real0\CLionProjects\OOP4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ex.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex.dir/flags.make

CMakeFiles/ex.dir/example.cpp.obj: CMakeFiles/ex.dir/flags.make
CMakeFiles/ex.dir/example.cpp.obj: ../example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\real0\CLionProjects\OOP4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex.dir/example.cpp.obj"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ex.dir\example.cpp.obj -c C:\Users\real0\CLionProjects\OOP4\example.cpp

CMakeFiles/ex.dir/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex.dir/example.cpp.i"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\real0\CLionProjects\OOP4\example.cpp > CMakeFiles\ex.dir\example.cpp.i

CMakeFiles/ex.dir/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex.dir/example.cpp.s"
	C:\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\real0\CLionProjects\OOP4\example.cpp -o CMakeFiles\ex.dir\example.cpp.s

# Object files for target ex
ex_OBJECTS = \
"CMakeFiles/ex.dir/example.cpp.obj"

# External object files for target ex
ex_EXTERNAL_OBJECTS =

ex.exe: CMakeFiles/ex.dir/example.cpp.obj
ex.exe: CMakeFiles/ex.dir/build.make
ex.exe: CMakeFiles/ex.dir/linklibs.rsp
ex.exe: CMakeFiles/ex.dir/objects1.rsp
ex.exe: CMakeFiles/ex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\real0\CLionProjects\OOP4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ex.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex.dir/build: ex.exe
.PHONY : CMakeFiles/ex.dir/build

CMakeFiles/ex.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ex.dir/clean

CMakeFiles/ex.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\real0\CLionProjects\OOP4 C:\Users\real0\CLionProjects\OOP4 C:\Users\real0\CLionProjects\OOP4\cmake-build-debug C:\Users\real0\CLionProjects\OOP4\cmake-build-debug C:\Users\real0\CLionProjects\OOP4\cmake-build-debug\CMakeFiles\ex.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex.dir/depend

