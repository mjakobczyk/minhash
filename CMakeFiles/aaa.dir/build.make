# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Repozytoria\MinHash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Repozytoria\MinHash

# Include any dependencies generated for this target.
include CMakeFiles/aaa.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aaa.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aaa.dir/flags.make

CMakeFiles/aaa.dir/src/main.cpp.obj: CMakeFiles/aaa.dir/flags.make
CMakeFiles/aaa.dir/src/main.cpp.obj: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Repozytoria\MinHash\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aaa.dir/src/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\aaa.dir\src\main.cpp.obj -c D:\Repozytoria\MinHash\src\main.cpp

CMakeFiles/aaa.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aaa.dir/src/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Repozytoria\MinHash\src\main.cpp > CMakeFiles\aaa.dir\src\main.cpp.i

CMakeFiles/aaa.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aaa.dir/src/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Repozytoria\MinHash\src\main.cpp -o CMakeFiles\aaa.dir\src\main.cpp.s

# Object files for target aaa
aaa_OBJECTS = \
"CMakeFiles/aaa.dir/src/main.cpp.obj"

# External object files for target aaa
aaa_EXTERNAL_OBJECTS =

aaa.exe: CMakeFiles/aaa.dir/src/main.cpp.obj
aaa.exe: CMakeFiles/aaa.dir/build.make
aaa.exe: CMakeFiles/aaa.dir/linklibs.rsp
aaa.exe: CMakeFiles/aaa.dir/objects1.rsp
aaa.exe: CMakeFiles/aaa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Repozytoria\MinHash\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable aaa.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\aaa.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aaa.dir/build: aaa.exe

.PHONY : CMakeFiles/aaa.dir/build

CMakeFiles/aaa.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\aaa.dir\cmake_clean.cmake
.PHONY : CMakeFiles/aaa.dir/clean

CMakeFiles/aaa.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Repozytoria\MinHash D:\Repozytoria\MinHash D:\Repozytoria\MinHash D:\Repozytoria\MinHash D:\Repozytoria\MinHash\CMakeFiles\aaa.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aaa.dir/depend

