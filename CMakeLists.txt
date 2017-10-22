cmake_minimum_required(VERSION 3.8)
project(Graphs)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        graph.txt
        Structures/Graph.c
        Structures/Graph.h
        Structures/Link.h
        Structures/LinkedList.c
        Structures/LinkedList.h
        Structures/Queue.c
        Structures/Queue.h
        Main.c)

add_executable(Graphs ${SOURCE_FILES})