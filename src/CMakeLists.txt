add_executable(${PROJECT_NAME} 
	main.cpp
	base_graph.cpp
	complete_graph.cpp
	grid_graph.cpp
)

target_link_libraries(${PROJECT_NAME} 
	raylib
)
