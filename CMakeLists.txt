cmake_minimum_required(VERSION 3.12)
project(c_revision C)

set(CMAKE_C_STANDARD 99)

add_executable(c_revision main.c pointers.c pointers.h array.c array.h structure.c structure.h datastructures/singly_linked_list.c datastructures/singly_linked_list.h datastructures/doubly_linked_list.c datastructures/doubly_linked_list.h datastructures/hash_table.c datastructures/hash_table.h datastructures/queue.c datastructures/queue.h datastructures/binary_tree.c datastructures/binary_tree.h datastructures/circular_ring_buffer.c datastructures/circular_ring_buffer.h function_pointers.c function_pointers.h file_operations.c file_operations.h preprocessors.c preprocessors.h singly_linked_list_2.c singly_linked_list_2.h)