# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/crivac/robocomp/components/robocomp-crdt/crdt4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/crivac/robocomp/components/robocomp-crdt/crdt4

# Include any dependencies generated for this target.
include src/CMakeFiles/crdt4.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/crdt4.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/crdt4.dir/flags.make

src/CommonBehavior.cpp: /home/crivac/robocomp/interfaces/CommonBehavior.ice
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating CommonBehavior.cpp and CommonBehavior.h from CommonBehavior.ice"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && slice2cpp -I/home/crivac/robocomp//interfaces/ -I/home/crivac/robocomp/interfaces -I/opt/robocomp/interfaces -I. /home/crivac/robocomp/interfaces/CommonBehavior.ice --output-dir .

src/CommonBehavior.h: src/CommonBehavior.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate src/CommonBehavior.h

src/DSRD4.cpp: /home/crivac/robocomp/interfaces/DSRD4.ice
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating DSRD4.cpp and DSRD4.h from DSRD4.ice"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && slice2cpp -I/home/crivac/robocomp//interfaces/ -I/home/crivac/robocomp/interfaces -I/opt/robocomp/interfaces -I. /home/crivac/robocomp/interfaces/DSRD4.ice --output-dir .

src/DSRD4.h: src/DSRD4.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate src/DSRD4.h

src/CMakeFiles/crdt4.dir/specificworker.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/specificworker.cpp.o: src/specificworker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/crdt4.dir/specificworker.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/specificworker.cpp.o -c /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/specificworker.cpp

src/CMakeFiles/crdt4.dir/specificworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/specificworker.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/specificworker.cpp > CMakeFiles/crdt4.dir/specificworker.cpp.i

src/CMakeFiles/crdt4.dir/specificworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/specificworker.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/specificworker.cpp -o CMakeFiles/crdt4.dir/specificworker.cpp.s

src/CMakeFiles/crdt4.dir/specificworker.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/specificworker.cpp.o.requires

src/CMakeFiles/crdt4.dir/specificworker.cpp.o.provides: src/CMakeFiles/crdt4.dir/specificworker.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/specificworker.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/specificworker.cpp.o.provides

src/CMakeFiles/crdt4.dir/specificworker.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/specificworker.cpp.o


src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o: src/specificmonitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/specificmonitor.cpp.o -c /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/specificmonitor.cpp

src/CMakeFiles/crdt4.dir/specificmonitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/specificmonitor.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/specificmonitor.cpp > CMakeFiles/crdt4.dir/specificmonitor.cpp.i

src/CMakeFiles/crdt4.dir/specificmonitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/specificmonitor.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/specificmonitor.cpp -o CMakeFiles/crdt4.dir/specificmonitor.cpp.s

src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o.requires

src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o.provides: src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o.provides

src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o


src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o: /home/crivac/robocomp/classes/rapplication/rapplication.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o -c /home/crivac/robocomp/classes/rapplication/rapplication.cpp

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/classes/rapplication/rapplication.cpp > CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.i

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/classes/rapplication/rapplication.cpp -o CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.s

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o.requires

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o.provides: src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o.provides

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o


src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o: /home/crivac/robocomp/classes/sigwatch/sigwatch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o -c /home/crivac/robocomp/classes/sigwatch/sigwatch.cpp

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/classes/sigwatch/sigwatch.cpp > CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.i

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/classes/sigwatch/sigwatch.cpp -o CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.s

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o.requires

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o.provides: src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o.provides

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o


src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o: /home/crivac/robocomp/classes/qlog/qlog.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o -c /home/crivac/robocomp/classes/qlog/qlog.cpp

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/classes/qlog/qlog.cpp > CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.i

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/classes/qlog/qlog.cpp -o CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.s

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o.requires

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o.provides: src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o.provides

src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o


src/CMakeFiles/crdt4.dir/main.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/crdt4.dir/main.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/main.cpp.o -c /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/main.cpp

src/CMakeFiles/crdt4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/main.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/main.cpp > CMakeFiles/crdt4.dir/main.cpp.i

src/CMakeFiles/crdt4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/main.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/main.cpp -o CMakeFiles/crdt4.dir/main.cpp.s

src/CMakeFiles/crdt4.dir/main.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/main.cpp.o.requires

src/CMakeFiles/crdt4.dir/main.cpp.o.provides: src/CMakeFiles/crdt4.dir/main.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/main.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/main.cpp.o.provides

src/CMakeFiles/crdt4.dir/main.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/main.cpp.o


src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o: src/genericmonitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/genericmonitor.cpp.o -c /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/genericmonitor.cpp

src/CMakeFiles/crdt4.dir/genericmonitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/genericmonitor.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/genericmonitor.cpp > CMakeFiles/crdt4.dir/genericmonitor.cpp.i

src/CMakeFiles/crdt4.dir/genericmonitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/genericmonitor.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/genericmonitor.cpp -o CMakeFiles/crdt4.dir/genericmonitor.cpp.s

src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o.requires

src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o.provides: src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o.provides

src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o


src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o: src/commonbehaviorI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o -c /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/commonbehaviorI.cpp

src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/commonbehaviorI.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/commonbehaviorI.cpp > CMakeFiles/crdt4.dir/commonbehaviorI.cpp.i

src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/commonbehaviorI.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/commonbehaviorI.cpp -o CMakeFiles/crdt4.dir/commonbehaviorI.cpp.s

src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o.requires

src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o.provides: src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o.provides

src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o


src/CMakeFiles/crdt4.dir/genericworker.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/genericworker.cpp.o: src/genericworker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/CMakeFiles/crdt4.dir/genericworker.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/genericworker.cpp.o -c /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/genericworker.cpp

src/CMakeFiles/crdt4.dir/genericworker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/genericworker.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/genericworker.cpp > CMakeFiles/crdt4.dir/genericworker.cpp.i

src/CMakeFiles/crdt4.dir/genericworker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/genericworker.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/genericworker.cpp -o CMakeFiles/crdt4.dir/genericworker.cpp.s

src/CMakeFiles/crdt4.dir/genericworker.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/genericworker.cpp.o.requires

src/CMakeFiles/crdt4.dir/genericworker.cpp.o.provides: src/CMakeFiles/crdt4.dir/genericworker.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/genericworker.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/genericworker.cpp.o.provides

src/CMakeFiles/crdt4.dir/genericworker.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/genericworker.cpp.o


src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o: src/dsrd4syncI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o -c /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/dsrd4syncI.cpp

src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/dsrd4syncI.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/dsrd4syncI.cpp > CMakeFiles/crdt4.dir/dsrd4syncI.cpp.i

src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/dsrd4syncI.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/dsrd4syncI.cpp -o CMakeFiles/crdt4.dir/dsrd4syncI.cpp.s

src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o.requires

src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o.provides: src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o.provides

src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o


src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o: src/dsrd4I.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/dsrd4I.cpp.o -c /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/dsrd4I.cpp

src/CMakeFiles/crdt4.dir/dsrd4I.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/dsrd4I.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/dsrd4I.cpp > CMakeFiles/crdt4.dir/dsrd4I.cpp.i

src/CMakeFiles/crdt4.dir/dsrd4I.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/dsrd4I.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/dsrd4I.cpp -o CMakeFiles/crdt4.dir/dsrd4I.cpp.s

src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o.requires

src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o.provides: src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o.provides

src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o


src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o: src/CommonBehavior.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/CommonBehavior.cpp.o -c /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/CommonBehavior.cpp

src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/CommonBehavior.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/CommonBehavior.cpp > CMakeFiles/crdt4.dir/CommonBehavior.cpp.i

src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/CommonBehavior.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/CommonBehavior.cpp -o CMakeFiles/crdt4.dir/CommonBehavior.cpp.s

src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o.requires

src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o.provides: src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o.provides

src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o


src/CMakeFiles/crdt4.dir/DSRD4.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/DSRD4.cpp.o: src/DSRD4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object src/CMakeFiles/crdt4.dir/DSRD4.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/DSRD4.cpp.o -c /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/DSRD4.cpp

src/CMakeFiles/crdt4.dir/DSRD4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/DSRD4.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/DSRD4.cpp > CMakeFiles/crdt4.dir/DSRD4.cpp.i

src/CMakeFiles/crdt4.dir/DSRD4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/DSRD4.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/DSRD4.cpp -o CMakeFiles/crdt4.dir/DSRD4.cpp.s

src/CMakeFiles/crdt4.dir/DSRD4.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/DSRD4.cpp.o.requires

src/CMakeFiles/crdt4.dir/DSRD4.cpp.o.provides: src/CMakeFiles/crdt4.dir/DSRD4.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/DSRD4.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/DSRD4.cpp.o.provides

src/CMakeFiles/crdt4.dir/DSRD4.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/DSRD4.cpp.o


src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o: src/CMakeFiles/crdt4.dir/flags.make
src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o: src/crdt4_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o -c /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/crdt4_autogen/mocs_compilation.cpp

src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.i"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/crdt4_autogen/mocs_compilation.cpp > CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.i

src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.s"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/crdt4_autogen/mocs_compilation.cpp -o CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.s

src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o.requires:

.PHONY : src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o.requires

src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o.provides: src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/crdt4.dir/build.make src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o.provides.build
.PHONY : src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o.provides

src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o.provides.build: src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o


# Object files for target crdt4
crdt4_OBJECTS = \
"CMakeFiles/crdt4.dir/specificworker.cpp.o" \
"CMakeFiles/crdt4.dir/specificmonitor.cpp.o" \
"CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o" \
"CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o" \
"CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o" \
"CMakeFiles/crdt4.dir/main.cpp.o" \
"CMakeFiles/crdt4.dir/genericmonitor.cpp.o" \
"CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o" \
"CMakeFiles/crdt4.dir/genericworker.cpp.o" \
"CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o" \
"CMakeFiles/crdt4.dir/dsrd4I.cpp.o" \
"CMakeFiles/crdt4.dir/CommonBehavior.cpp.o" \
"CMakeFiles/crdt4.dir/DSRD4.cpp.o" \
"CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o"

# External object files for target crdt4
crdt4_EXTERNAL_OBJECTS =

bin/crdt4: src/CMakeFiles/crdt4.dir/specificworker.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/main.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/genericworker.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/DSRD4.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o
bin/crdt4: src/CMakeFiles/crdt4.dir/build.make
bin/crdt4: /usr/lib/x86_64-linux-gnu/libQtOpenGL.so
bin/crdt4: /usr/lib/x86_64-linux-gnu/libQtGui.so
bin/crdt4: /usr/lib/x86_64-linux-gnu/libQtXml.so
bin/crdt4: /usr/lib/x86_64-linux-gnu/libQtCore.so
bin/crdt4: /usr/lib/x86_64-linux-gnu/libIce.so
bin/crdt4: /usr/lib/x86_64-linux-gnu/libIceStorm.so
bin/crdt4: src/CMakeFiles/crdt4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/crivac/robocomp/components/robocomp-crdt/crdt4/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable ../bin/crdt4"
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/crdt4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/crdt4.dir/build: bin/crdt4

.PHONY : src/CMakeFiles/crdt4.dir/build

src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/specificworker.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/specificmonitor.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/rapplication/rapplication.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/sigwatch/sigwatch.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/home/crivac/robocomp/classes/qlog/qlog.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/main.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/genericmonitor.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/commonbehaviorI.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/genericworker.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/dsrd4syncI.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/dsrd4I.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/CommonBehavior.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/DSRD4.cpp.o.requires
src/CMakeFiles/crdt4.dir/requires: src/CMakeFiles/crdt4.dir/crdt4_autogen/mocs_compilation.cpp.o.requires

.PHONY : src/CMakeFiles/crdt4.dir/requires

src/CMakeFiles/crdt4.dir/clean:
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4/src && $(CMAKE_COMMAND) -P CMakeFiles/crdt4.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/crdt4.dir/clean

src/CMakeFiles/crdt4.dir/depend: src/CommonBehavior.cpp
src/CMakeFiles/crdt4.dir/depend: src/CommonBehavior.h
src/CMakeFiles/crdt4.dir/depend: src/DSRD4.cpp
src/CMakeFiles/crdt4.dir/depend: src/DSRD4.h
	cd /home/crivac/robocomp/components/robocomp-crdt/crdt4 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crivac/robocomp/components/robocomp-crdt/crdt4 /home/crivac/robocomp/components/robocomp-crdt/crdt4/src /home/crivac/robocomp/components/robocomp-crdt/crdt4 /home/crivac/robocomp/components/robocomp-crdt/crdt4/src /home/crivac/robocomp/components/robocomp-crdt/crdt4/src/CMakeFiles/crdt4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/crdt4.dir/depend
