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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/robot/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robot/catkin_ws/build

# Include any dependencies generated for this target.
include wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/depend.make

# Include the progress variables for this target.
include wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/progress.make

# Include the compile flags for this target's objects.
include wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/flags.make

wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o: wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/flags.make
wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o: /home/robot/catkin_ws/src/wpb_home_apps_2017/src/speech_recognition.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/robot/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o"
	cd /home/robot/catkin_ws/build/wpb_home_apps_2017 && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o -c /home/robot/catkin_ws/src/wpb_home_apps_2017/src/speech_recognition.cpp

wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.i"
	cd /home/robot/catkin_ws/build/wpb_home_apps_2017 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/robot/catkin_ws/src/wpb_home_apps_2017/src/speech_recognition.cpp > CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.i

wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.s"
	cd /home/robot/catkin_ws/build/wpb_home_apps_2017 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/robot/catkin_ws/src/wpb_home_apps_2017/src/speech_recognition.cpp -o CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.s

wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o.requires:
.PHONY : wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o.requires

wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o.provides: wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o.requires
	$(MAKE) -f wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/build.make wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o.provides.build
.PHONY : wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o.provides

wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o.provides.build: wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o

# Object files for target speech_recognition
speech_recognition_OBJECTS = \
"CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o"

# External object files for target speech_recognition
speech_recognition_EXTERNAL_OBJECTS =

/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/build.make
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libpcl_ros_filters.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libpcl_ros_io.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libpcl_ros_tf.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_common.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_octree.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_io.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_kdtree.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_search.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_sample_consensus.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_filters.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_features.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_keypoints.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_segmentation.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_visualization.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_outofcore.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_registration.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_recognition.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_surface.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_people.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_tracking.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libpcl_apps.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libqhull.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libOpenNI.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libflann_cpp_s.a
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libvtkCommon.so.5.8.0
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libvtkRendering.so.5.8.0
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libvtkHybrid.so.5.8.0
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libvtkCharts.so.5.8.0
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libdynamic_reconfigure_config_init_mutex.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libnodeletlib.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libbondcpp.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libuuid.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/librosbag.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/librosbag_storage.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libroslz4.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/liblz4.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libtopic_tools.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libcv_bridge.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libimage_transport.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libclass_loader.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/libPocoFoundation.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libdl.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libroslib.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/librospack.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libtinyxml.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libtf.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libtf2_ros.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libmessage_filters.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libtf2.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libimage_geometry.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libactionlib.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libroscpp.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/librosconsole.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/librosconsole_log4cxx.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/librosconsole_backend_interface.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/liblog4cxx.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libxmlrpcpp.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libroscpp_serialization.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/librostime.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /opt/ros/indigo/lib/libcpp_common.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition: wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable /home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition"
	cd /home/robot/catkin_ws/build/wpb_home_apps_2017 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/speech_recognition.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/build: /home/robot/catkin_ws/devel/lib/wpb_home_apps_2017/speech_recognition
.PHONY : wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/build

wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/requires: wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/src/speech_recognition.cpp.o.requires
.PHONY : wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/requires

wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/clean:
	cd /home/robot/catkin_ws/build/wpb_home_apps_2017 && $(CMAKE_COMMAND) -P CMakeFiles/speech_recognition.dir/cmake_clean.cmake
.PHONY : wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/clean

wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/depend:
	cd /home/robot/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robot/catkin_ws/src /home/robot/catkin_ws/src/wpb_home_apps_2017 /home/robot/catkin_ws/build /home/robot/catkin_ws/build/wpb_home_apps_2017 /home/robot/catkin_ws/build/wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : wpb_home_apps_2017/CMakeFiles/speech_recognition.dir/depend

