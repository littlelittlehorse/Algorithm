# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ymkzpx/CLionProjects/leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ymkzpx/CLionProjects/leetcode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/p1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p1.dir/flags.make

CMakeFiles/p1.dir/p1.cpp.o: CMakeFiles/p1.dir/flags.make
CMakeFiles/p1.dir/p1.cpp.o: ../p1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ymkzpx/CLionProjects/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p1.dir/p1.cpp.o"
	/usr/local/bin/g++-4.9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p1.dir/p1.cpp.o -c /Users/ymkzpx/CLionProjects/leetcode/p1.cpp

CMakeFiles/p1.dir/p1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p1.dir/p1.cpp.i"
	/usr/local/bin/g++-4.9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ymkzpx/CLionProjects/leetcode/p1.cpp > CMakeFiles/p1.dir/p1.cpp.i

CMakeFiles/p1.dir/p1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p1.dir/p1.cpp.s"
	/usr/local/bin/g++-4.9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ymkzpx/CLionProjects/leetcode/p1.cpp -o CMakeFiles/p1.dir/p1.cpp.s

# Object files for target p1
p1_OBJECTS = \
"CMakeFiles/p1.dir/p1.cpp.o"

# External object files for target p1
p1_EXTERNAL_OBJECTS =

p1: CMakeFiles/p1.dir/p1.cpp.o
p1: CMakeFiles/p1.dir/build.make
p1: CMakeFiles/p1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ymkzpx/CLionProjects/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable p1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p1.dir/build: p1

.PHONY : CMakeFiles/p1.dir/build

CMakeFiles/p1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p1.dir/clean

CMakeFiles/p1.dir/depend:
	cd /Users/ymkzpx/CLionProjects/leetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ymkzpx/CLionProjects/leetcode /Users/ymkzpx/CLionProjects/leetcode /Users/ymkzpx/CLionProjects/leetcode/cmake-build-debug /Users/ymkzpx/CLionProjects/leetcode/cmake-build-debug /Users/ymkzpx/CLionProjects/leetcode/cmake-build-debug/CMakeFiles/p1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p1.dir/depend

