cmake_minimum_required(VERSION 3.5)

project(maze)

############################################################
# Create a library
############################################################

#Generate the static library from the library sources
add_library(maze_library STATIC 
    src/random_maze.cpp
)

target_include_directories(maze_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(maze 
    src/main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( maze
    PRIVATE 
        maze_library
)
