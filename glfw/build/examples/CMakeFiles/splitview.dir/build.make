# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/splitview.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/splitview.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/splitview.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/splitview.dir/flags.make

examples/CMakeFiles/splitview.dir/splitview.c.o: examples/CMakeFiles/splitview.dir/flags.make
examples/CMakeFiles/splitview.dir/splitview.c.o: ../examples/splitview.c
examples/CMakeFiles/splitview.dir/splitview.c.o: examples/CMakeFiles/splitview.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/splitview.dir/splitview.c.o"
	cd /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/splitview.dir/splitview.c.o -MF CMakeFiles/splitview.dir/splitview.c.o.d -o CMakeFiles/splitview.dir/splitview.c.o -c /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/examples/splitview.c

examples/CMakeFiles/splitview.dir/splitview.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/splitview.dir/splitview.c.i"
	cd /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/examples/splitview.c > CMakeFiles/splitview.dir/splitview.c.i

examples/CMakeFiles/splitview.dir/splitview.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/splitview.dir/splitview.c.s"
	cd /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/examples/splitview.c -o CMakeFiles/splitview.dir/splitview.c.s

examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.o: examples/CMakeFiles/splitview.dir/flags.make
examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.o: ../deps/glad_gl.c
examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.o: examples/CMakeFiles/splitview.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.o"
	cd /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.o -MF CMakeFiles/splitview.dir/__/deps/glad_gl.c.o.d -o CMakeFiles/splitview.dir/__/deps/glad_gl.c.o -c /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/deps/glad_gl.c

examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/splitview.dir/__/deps/glad_gl.c.i"
	cd /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/deps/glad_gl.c > CMakeFiles/splitview.dir/__/deps/glad_gl.c.i

examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/splitview.dir/__/deps/glad_gl.c.s"
	cd /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/deps/glad_gl.c -o CMakeFiles/splitview.dir/__/deps/glad_gl.c.s

# Object files for target splitview
splitview_OBJECTS = \
"CMakeFiles/splitview.dir/splitview.c.o" \
"CMakeFiles/splitview.dir/__/deps/glad_gl.c.o"

# External object files for target splitview
splitview_EXTERNAL_OBJECTS =

examples/splitview: examples/CMakeFiles/splitview.dir/splitview.c.o
examples/splitview: examples/CMakeFiles/splitview.dir/__/deps/glad_gl.c.o
examples/splitview: examples/CMakeFiles/splitview.dir/build.make
examples/splitview: src/libglfw3.a
examples/splitview: /usr/lib/x86_64-linux-gnu/libm.so
examples/splitview: /usr/lib/x86_64-linux-gnu/librt.so
examples/splitview: /usr/lib/x86_64-linux-gnu/libm.so
examples/splitview: /usr/lib/x86_64-linux-gnu/libX11.so
examples/splitview: examples/CMakeFiles/splitview.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable splitview"
	cd /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/splitview.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/splitview.dir/build: examples/splitview
.PHONY : examples/CMakeFiles/splitview.dir/build

examples/CMakeFiles/splitview.dir/clean:
	cd /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/splitview.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/splitview.dir/clean

examples/CMakeFiles/splitview.dir/depend:
	cd /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/examples /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/examples /home/shasha/Janessa/vscode/OpenGl/GLFW/glfw/build/examples/CMakeFiles/splitview.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/splitview.dir/depend
