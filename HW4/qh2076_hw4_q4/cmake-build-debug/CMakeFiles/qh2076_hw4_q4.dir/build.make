# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = /Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/qh2076_hw4_q4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/qh2076_hw4_q4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/qh2076_hw4_q4.dir/flags.make

CMakeFiles/qh2076_hw4_q4.dir/main.cpp.o: CMakeFiles/qh2076_hw4_q4.dir/flags.make
CMakeFiles/qh2076_hw4_q4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/qh2076_hw4_q4.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/qh2076_hw4_q4.dir/main.cpp.o -c /Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4/main.cpp

CMakeFiles/qh2076_hw4_q4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/qh2076_hw4_q4.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4/main.cpp > CMakeFiles/qh2076_hw4_q4.dir/main.cpp.i

CMakeFiles/qh2076_hw4_q4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/qh2076_hw4_q4.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4/main.cpp -o CMakeFiles/qh2076_hw4_q4.dir/main.cpp.s

# Object files for target qh2076_hw4_q4
qh2076_hw4_q4_OBJECTS = \
"CMakeFiles/qh2076_hw4_q4.dir/main.cpp.o"

# External object files for target qh2076_hw4_q4
qh2076_hw4_q4_EXTERNAL_OBJECTS =

qh2076_hw4_q4: CMakeFiles/qh2076_hw4_q4.dir/main.cpp.o
qh2076_hw4_q4: CMakeFiles/qh2076_hw4_q4.dir/build.make
qh2076_hw4_q4: CMakeFiles/qh2076_hw4_q4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable qh2076_hw4_q4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/qh2076_hw4_q4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/qh2076_hw4_q4.dir/build: qh2076_hw4_q4

.PHONY : CMakeFiles/qh2076_hw4_q4.dir/build

CMakeFiles/qh2076_hw4_q4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/qh2076_hw4_q4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/qh2076_hw4_q4.dir/clean

CMakeFiles/qh2076_hw4_q4.dir/depend:
	cd /Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4 /Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4 /Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4/cmake-build-debug /Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4/cmake-build-debug /Users/MIKE/Desktop/Bridge/HW/HW/HW4/qh2076_hw4_q4/cmake-build-debug/CMakeFiles/qh2076_hw4_q4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/qh2076_hw4_q4.dir/depend

