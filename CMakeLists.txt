
cmake_minimum_required(VERSION 3.22.1)

project(ProjectName
	LANGUAGES CXX C
)

set(CMAKE_POLICY_DEFAULT_CMP0072 NEW)

add_subdirectory(external)
add_subdirectory(src)
