# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/muzi/Training/EventLoop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/muzi/Training/EventLoop/build

# Include any dependencies generated for this target.
include CMakeFiles/Event_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Event_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Event_test.dir/flags.make

CMakeFiles/Event_test.dir/src_test/main.cpp.o: CMakeFiles/Event_test.dir/flags.make
CMakeFiles/Event_test.dir/src_test/main.cpp.o: ../src_test/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/muzi/Training/EventLoop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Event_test.dir/src_test/main.cpp.o"
	/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Event_test.dir/src_test/main.cpp.o -c /home/muzi/Training/EventLoop/src_test/main.cpp

CMakeFiles/Event_test.dir/src_test/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Event_test.dir/src_test/main.cpp.i"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/muzi/Training/EventLoop/src_test/main.cpp > CMakeFiles/Event_test.dir/src_test/main.cpp.i

CMakeFiles/Event_test.dir/src_test/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Event_test.dir/src_test/main.cpp.s"
	/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/muzi/Training/EventLoop/src_test/main.cpp -o CMakeFiles/Event_test.dir/src_test/main.cpp.s

# Object files for target Event_test
Event_test_OBJECTS = \
"CMakeFiles/Event_test.dir/src_test/main.cpp.o"

# External object files for target Event_test
Event_test_EXTERNAL_OBJECTS =

Event_test: CMakeFiles/Event_test.dir/src_test/main.cpp.o
Event_test: CMakeFiles/Event_test.dir/build.make
Event_test: CMakeFiles/Event_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/muzi/Training/EventLoop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Event_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Event_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Event_test.dir/build: Event_test

.PHONY : CMakeFiles/Event_test.dir/build

CMakeFiles/Event_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Event_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Event_test.dir/clean

CMakeFiles/Event_test.dir/depend:
	cd /home/muzi/Training/EventLoop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/muzi/Training/EventLoop /home/muzi/Training/EventLoop /home/muzi/Training/EventLoop/build /home/muzi/Training/EventLoop/build /home/muzi/Training/EventLoop/build/CMakeFiles/Event_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Event_test.dir/depend

