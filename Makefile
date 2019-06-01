# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/6im1/ebenhari/Documents/OPENGL/TowerDefense_SANGARE_BENHARIRA

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/6im1/ebenhari/Documents/OPENGL/TowerDefense_SANGARE_BENHARIRA

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/6im1/ebenhari/Documents/OPENGL/TowerDefense_SANGARE_BENHARIRA/CMakeFiles /home/6im1/ebenhari/Documents/OPENGL/TowerDefense_SANGARE_BENHARIRA/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/6im1/ebenhari/Documents/OPENGL/TowerDefense_SANGARE_BENHARIRA/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named itd_eva

# Build rule for target.
itd_eva: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 itd_eva
.PHONY : itd_eva

# fast build rule for target.
itd_eva/fast:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/build
.PHONY : itd_eva/fast

src/Building.o: src/Building.cpp.o

.PHONY : src/Building.o

# target to build an object file
src/Building.cpp.o:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Building.cpp.o
.PHONY : src/Building.cpp.o

src/Building.i: src/Building.cpp.i

.PHONY : src/Building.i

# target to preprocess a source file
src/Building.cpp.i:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Building.cpp.i
.PHONY : src/Building.cpp.i

src/Building.s: src/Building.cpp.s

.PHONY : src/Building.s

# target to generate assembly for a file
src/Building.cpp.s:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Building.cpp.s
.PHONY : src/Building.cpp.s

src/CatMonster.o: src/CatMonster.cpp.o

.PHONY : src/CatMonster.o

# target to build an object file
src/CatMonster.cpp.o:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/CatMonster.cpp.o
.PHONY : src/CatMonster.cpp.o

src/CatMonster.i: src/CatMonster.cpp.i

.PHONY : src/CatMonster.i

# target to preprocess a source file
src/CatMonster.cpp.i:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/CatMonster.cpp.i
.PHONY : src/CatMonster.cpp.i

src/CatMonster.s: src/CatMonster.cpp.s

.PHONY : src/CatMonster.s

# target to generate assembly for a file
src/CatMonster.cpp.s:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/CatMonster.cpp.s
.PHONY : src/CatMonster.cpp.s

src/Entity.o: src/Entity.cpp.o

.PHONY : src/Entity.o

# target to build an object file
src/Entity.cpp.o:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Entity.cpp.o
.PHONY : src/Entity.cpp.o

src/Entity.i: src/Entity.cpp.i

.PHONY : src/Entity.i

# target to preprocess a source file
src/Entity.cpp.i:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Entity.cpp.i
.PHONY : src/Entity.cpp.i

src/Entity.s: src/Entity.cpp.s

.PHONY : src/Entity.s

# target to generate assembly for a file
src/Entity.cpp.s:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Entity.cpp.s
.PHONY : src/Entity.cpp.s

src/Game.o: src/Game.cpp.o

.PHONY : src/Game.o

# target to build an object file
src/Game.cpp.o:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Game.cpp.o
.PHONY : src/Game.cpp.o

src/Game.i: src/Game.cpp.i

.PHONY : src/Game.i

# target to preprocess a source file
src/Game.cpp.i:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Game.cpp.i
.PHONY : src/Game.cpp.i

src/Game.s: src/Game.cpp.s

.PHONY : src/Game.s

# target to generate assembly for a file
src/Game.cpp.s:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Game.cpp.s
.PHONY : src/Game.cpp.s

src/Map.o: src/Map.cpp.o

.PHONY : src/Map.o

# target to build an object file
src/Map.cpp.o:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Map.cpp.o
.PHONY : src/Map.cpp.o

src/Map.i: src/Map.cpp.i

.PHONY : src/Map.i

# target to preprocess a source file
src/Map.cpp.i:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Map.cpp.i
.PHONY : src/Map.cpp.i

src/Map.s: src/Map.cpp.s

.PHONY : src/Map.s

# target to generate assembly for a file
src/Map.cpp.s:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Map.cpp.s
.PHONY : src/Map.cpp.s

src/TextureController.o: src/TextureController.cpp.o

.PHONY : src/TextureController.o

# target to build an object file
src/TextureController.cpp.o:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/TextureController.cpp.o
.PHONY : src/TextureController.cpp.o

src/TextureController.i: src/TextureController.cpp.i

.PHONY : src/TextureController.i

# target to preprocess a source file
src/TextureController.cpp.i:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/TextureController.cpp.i
.PHONY : src/TextureController.cpp.i

src/TextureController.s: src/TextureController.cpp.s

.PHONY : src/TextureController.s

# target to generate assembly for a file
src/TextureController.cpp.s:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/TextureController.cpp.s
.PHONY : src/TextureController.cpp.s

src/Tile.o: src/Tile.cpp.o

.PHONY : src/Tile.o

# target to build an object file
src/Tile.cpp.o:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Tile.cpp.o
.PHONY : src/Tile.cpp.o

src/Tile.i: src/Tile.cpp.i

.PHONY : src/Tile.i

# target to preprocess a source file
src/Tile.cpp.i:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Tile.cpp.i
.PHONY : src/Tile.cpp.i

src/Tile.s: src/Tile.cpp.s

.PHONY : src/Tile.s

# target to generate assembly for a file
src/Tile.cpp.s:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Tile.cpp.s
.PHONY : src/Tile.cpp.s

src/Tower.o: src/Tower.cpp.o

.PHONY : src/Tower.o

# target to build an object file
src/Tower.cpp.o:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Tower.cpp.o
.PHONY : src/Tower.cpp.o

src/Tower.i: src/Tower.cpp.i

.PHONY : src/Tower.i

# target to preprocess a source file
src/Tower.cpp.i:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Tower.cpp.i
.PHONY : src/Tower.cpp.i

src/Tower.s: src/Tower.cpp.s

.PHONY : src/Tower.s

# target to generate assembly for a file
src/Tower.cpp.s:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Tower.cpp.s
.PHONY : src/Tower.cpp.s

src/Tower_Defense_Main.o: src/Tower_Defense_Main.cpp.o

.PHONY : src/Tower_Defense_Main.o

# target to build an object file
src/Tower_Defense_Main.cpp.o:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Tower_Defense_Main.cpp.o
.PHONY : src/Tower_Defense_Main.cpp.o

src/Tower_Defense_Main.i: src/Tower_Defense_Main.cpp.i

.PHONY : src/Tower_Defense_Main.i

# target to preprocess a source file
src/Tower_Defense_Main.cpp.i:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Tower_Defense_Main.cpp.i
.PHONY : src/Tower_Defense_Main.cpp.i

src/Tower_Defense_Main.s: src/Tower_Defense_Main.cpp.s

.PHONY : src/Tower_Defense_Main.s

# target to generate assembly for a file
src/Tower_Defense_Main.cpp.s:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Tower_Defense_Main.cpp.s
.PHONY : src/Tower_Defense_Main.cpp.s

src/Window.o: src/Window.cpp.o

.PHONY : src/Window.o

# target to build an object file
src/Window.cpp.o:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Window.cpp.o
.PHONY : src/Window.cpp.o

src/Window.i: src/Window.cpp.i

.PHONY : src/Window.i

# target to preprocess a source file
src/Window.cpp.i:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Window.cpp.i
.PHONY : src/Window.cpp.i

src/Window.s: src/Window.cpp.s

.PHONY : src/Window.s

# target to generate assembly for a file
src/Window.cpp.s:
	$(MAKE) -f CMakeFiles/itd_eva.dir/build.make CMakeFiles/itd_eva.dir/src/Window.cpp.s
.PHONY : src/Window.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... itd_eva"
	@echo "... src/Building.o"
	@echo "... src/Building.i"
	@echo "... src/Building.s"
	@echo "... src/CatMonster.o"
	@echo "... src/CatMonster.i"
	@echo "... src/CatMonster.s"
	@echo "... src/Entity.o"
	@echo "... src/Entity.i"
	@echo "... src/Entity.s"
	@echo "... src/Game.o"
	@echo "... src/Game.i"
	@echo "... src/Game.s"
	@echo "... src/Map.o"
	@echo "... src/Map.i"
	@echo "... src/Map.s"
	@echo "... src/TextureController.o"
	@echo "... src/TextureController.i"
	@echo "... src/TextureController.s"
	@echo "... src/Tile.o"
	@echo "... src/Tile.i"
	@echo "... src/Tile.s"
	@echo "... src/Tower.o"
	@echo "... src/Tower.i"
	@echo "... src/Tower.s"
	@echo "... src/Tower_Defense_Main.o"
	@echo "... src/Tower_Defense_Main.i"
	@echo "... src/Tower_Defense_Main.s"
	@echo "... src/Window.o"
	@echo "... src/Window.i"
	@echo "... src/Window.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

