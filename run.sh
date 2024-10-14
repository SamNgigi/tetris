#!/bin/bash

# Get the directory name
# $(pwd) gets the current working directory
# dirname extracts the path
# basename extracts the final component
dir_name=$(basename "$(pwd)")

# Defining paths for executables
# ${var} is a variable expansion, similar to %var% in batch
exe_path="build/Debug/${dir_name}.exe"
test_exe_path="build/Debug/${dir_name}_test.exe"

# Function to clean build artifacts/ directory
clean(){
  echo "Cleaning build directory..."
  # Checking if the build directory exists
  if [ -d "build" ]; then
    echo "Removing existing build directory..."
    # -rf: recursive and force option for rm
    rm -rf build
    # $? is a special variable that holds the exit status of the last command
    if [ $? -ne 0 ]; then
      echo "Failed to remove build directory."
      exit 1
    fi
  fi
  echo "Creating new build directory."
  mkdir build
  if [ $? -ne 0 ]; then
    echo "Failed to create build directory."
    exit 1
  fi
  echo "Clean completed successfully."
}

# Function to build project
build(){
  # -p action for mkdir creates parent directories if they don't exist
  mkdir -p build
  # We use this instead of cd as we won't change directory if pushd fails
  pushd build > /dev/null
  # IMPORTANT: Change the line below to match path to your cmake
  cmake -DCMAKE_TOOLCHAIN_FILE=/c/Users/samtn/vcpkg/scripts/buildsystems/vcpkg.cmake ..
  if [ $? -ne 0 ]; then
    echo "CMake configuration failed. Check DCMAKE_TOOLCHAIN_FILE path provided"
    popd > /dev/null
    exit 1
  fi
  cmake --build .
  if [ $? -ne 0 ]; then
    echo "Build failed."
    popd > /dev/null
    exit 1
  fi
  popd > /dev/null
  echo "Build completed successfully."
}

# Function to run the executable
run(){
  # -f test checks if a file exists and is a regular file
  if [ ! -f "$exe_path" ]; then
    echo "Executable not found. Building the project..."
    build
    if [ $? -ne 0 ]; then
      exit 1
    fi
  fi
  echo "Running executable..."
  "$exe_path"
}

test(){
  "Running tests..."
  "$test_exe_path"
}


# Main logic
if [ $# -eq 0 ]; then
  # No arguments provided default to 'run'
  run
else
  for arg in "$@"; do
    case $arg in
      build)
        build
        ;;
      clean)
        clean
        ;;
      run)
        run
        ;;
      test)
        test
        ;;
      *)
        echo "Unknown action or argument:: $arg"
        ;;
    esac
  done
fi
