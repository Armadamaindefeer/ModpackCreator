add_executable(ModpackCreator main.cpp)
add_subdirectory(test)
add_subdirectory(target)

target_link_libraries(ModpackCreator PRIVATE 
	test
)
