# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kunala/Documents/BTP/Graphics-BTP/Demo/PCL_Register

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kunala/Documents/BTP/Graphics-BTP/Demo/PCL_Register/build

# Include any dependencies generated for this target.
include CMakeFiles/register.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/register.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/register.dir/flags.make

CMakeFiles/register.dir/register.cpp.o: CMakeFiles/register.dir/flags.make
CMakeFiles/register.dir/register.cpp.o: ../register.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/kunala/Documents/BTP/Graphics-BTP/Demo/PCL_Register/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/register.dir/register.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/register.dir/register.cpp.o -c /home/kunala/Documents/BTP/Graphics-BTP/Demo/PCL_Register/register.cpp

CMakeFiles/register.dir/register.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/register.dir/register.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/kunala/Documents/BTP/Graphics-BTP/Demo/PCL_Register/register.cpp > CMakeFiles/register.dir/register.cpp.i

CMakeFiles/register.dir/register.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/register.dir/register.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/kunala/Documents/BTP/Graphics-BTP/Demo/PCL_Register/register.cpp -o CMakeFiles/register.dir/register.cpp.s

CMakeFiles/register.dir/register.cpp.o.requires:
.PHONY : CMakeFiles/register.dir/register.cpp.o.requires

CMakeFiles/register.dir/register.cpp.o.provides: CMakeFiles/register.dir/register.cpp.o.requires
	$(MAKE) -f CMakeFiles/register.dir/build.make CMakeFiles/register.dir/register.cpp.o.provides.build
.PHONY : CMakeFiles/register.dir/register.cpp.o.provides

CMakeFiles/register.dir/register.cpp.o.provides.build: CMakeFiles/register.dir/register.cpp.o

# Object files for target register
register_OBJECTS = \
"CMakeFiles/register.dir/register.cpp.o"

# External object files for target register
register_EXTERNAL_OBJECTS =

register: CMakeFiles/register.dir/register.cpp.o
register: CMakeFiles/register.dir/build.make
register: /usr/lib/x86_64-linux-gnu/libboost_system.so
register: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
register: /usr/lib/x86_64-linux-gnu/libboost_thread.so
register: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
register: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
register: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
register: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
register: /usr/lib/x86_64-linux-gnu/libpthread.so
register: /usr/local/lib/libpcl_common.so
register: /usr/local/lib/libpcl_octree.so
register: /usr/lib/libOpenNI.so
register: /usr/lib/libOpenNI2.so
register: /usr/lib/libvtkCommon.so.5.8.0
register: /usr/lib/libvtkFiltering.so.5.8.0
register: /usr/lib/libvtkImaging.so.5.8.0
register: /usr/lib/libvtkGraphics.so.5.8.0
register: /usr/lib/libvtkGenericFiltering.so.5.8.0
register: /usr/lib/libvtkIO.so.5.8.0
register: /usr/lib/libvtkRendering.so.5.8.0
register: /usr/lib/libvtkVolumeRendering.so.5.8.0
register: /usr/lib/libvtkHybrid.so.5.8.0
register: /usr/lib/libvtkWidgets.so.5.8.0
register: /usr/lib/libvtkParallel.so.5.8.0
register: /usr/lib/libvtkInfovis.so.5.8.0
register: /usr/lib/libvtkGeovis.so.5.8.0
register: /usr/lib/libvtkViews.so.5.8.0
register: /usr/lib/libvtkCharts.so.5.8.0
register: /usr/local/lib/libpcl_io.so
register: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
register: /usr/local/lib/libpcl_kdtree.so
register: /usr/local/lib/libpcl_search.so
register: /usr/local/lib/libpcl_sample_consensus.so
register: /usr/local/lib/libpcl_filters.so
register: /usr/local/lib/libpcl_features.so
register: /usr/local/lib/libpcl_keypoints.so
register: /usr/local/lib/libpcl_segmentation.so
register: /usr/local/lib/libpcl_visualization.so
register: /usr/local/lib/libpcl_outofcore.so
register: /usr/local/lib/libpcl_tracking.so
register: /usr/lib/x86_64-linux-gnu/libqhull.so
register: /usr/local/lib/libpcl_surface.so
register: /usr/local/lib/libpcl_registration.so
register: /usr/local/lib/libpcl_recognition.so
register: /usr/local/lib/libpcl_people.so
register: /usr/lib/x86_64-linux-gnu/libboost_system.so
register: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
register: /usr/lib/x86_64-linux-gnu/libboost_thread.so
register: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
register: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
register: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
register: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
register: /usr/lib/x86_64-linux-gnu/libpthread.so
register: /usr/lib/x86_64-linux-gnu/libqhull.so
register: /usr/lib/libOpenNI.so
register: /usr/lib/libOpenNI2.so
register: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
register: /usr/lib/libvtkCommon.so.5.8.0
register: /usr/lib/libvtkFiltering.so.5.8.0
register: /usr/lib/libvtkImaging.so.5.8.0
register: /usr/lib/libvtkGraphics.so.5.8.0
register: /usr/lib/libvtkGenericFiltering.so.5.8.0
register: /usr/lib/libvtkIO.so.5.8.0
register: /usr/lib/libvtkRendering.so.5.8.0
register: /usr/lib/libvtkVolumeRendering.so.5.8.0
register: /usr/lib/libvtkHybrid.so.5.8.0
register: /usr/lib/libvtkWidgets.so.5.8.0
register: /usr/lib/libvtkParallel.so.5.8.0
register: /usr/lib/libvtkInfovis.so.5.8.0
register: /usr/lib/libvtkGeovis.so.5.8.0
register: /usr/lib/libvtkViews.so.5.8.0
register: /usr/lib/libvtkCharts.so.5.8.0
register: /usr/local/lib/libpcl_common.so
register: /usr/local/lib/libpcl_octree.so
register: /usr/local/lib/libpcl_io.so
register: /usr/local/lib/libpcl_kdtree.so
register: /usr/local/lib/libpcl_search.so
register: /usr/local/lib/libpcl_sample_consensus.so
register: /usr/local/lib/libpcl_filters.so
register: /usr/local/lib/libpcl_features.so
register: /usr/local/lib/libpcl_keypoints.so
register: /usr/local/lib/libpcl_segmentation.so
register: /usr/local/lib/libpcl_visualization.so
register: /usr/local/lib/libpcl_outofcore.so
register: /usr/local/lib/libpcl_tracking.so
register: /usr/local/lib/libpcl_surface.so
register: /usr/local/lib/libpcl_registration.so
register: /usr/local/lib/libpcl_recognition.so
register: /usr/local/lib/libpcl_people.so
register: /usr/lib/libvtkViews.so.5.8.0
register: /usr/lib/libvtkInfovis.so.5.8.0
register: /usr/lib/libvtkWidgets.so.5.8.0
register: /usr/lib/libvtkVolumeRendering.so.5.8.0
register: /usr/lib/libvtkHybrid.so.5.8.0
register: /usr/lib/libvtkParallel.so.5.8.0
register: /usr/lib/libvtkRendering.so.5.8.0
register: /usr/lib/libvtkImaging.so.5.8.0
register: /usr/lib/libvtkGraphics.so.5.8.0
register: /usr/lib/libvtkIO.so.5.8.0
register: /usr/lib/libvtkFiltering.so.5.8.0
register: /usr/lib/libvtkCommon.so.5.8.0
register: /usr/lib/libvtksys.so.5.8.0
register: CMakeFiles/register.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable register"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/register.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/register.dir/build: register
.PHONY : CMakeFiles/register.dir/build

CMakeFiles/register.dir/requires: CMakeFiles/register.dir/register.cpp.o.requires
.PHONY : CMakeFiles/register.dir/requires

CMakeFiles/register.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/register.dir/cmake_clean.cmake
.PHONY : CMakeFiles/register.dir/clean

CMakeFiles/register.dir/depend:
	cd /home/kunala/Documents/BTP/Graphics-BTP/Demo/PCL_Register/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kunala/Documents/BTP/Graphics-BTP/Demo/PCL_Register /home/kunala/Documents/BTP/Graphics-BTP/Demo/PCL_Register /home/kunala/Documents/BTP/Graphics-BTP/Demo/PCL_Register/build /home/kunala/Documents/BTP/Graphics-BTP/Demo/PCL_Register/build /home/kunala/Documents/BTP/Graphics-BTP/Demo/PCL_Register/build/CMakeFiles/register.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/register.dir/depend

