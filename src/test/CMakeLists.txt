add_library(test)

target_sources(test PRIVATE ${CMAKE_CURRENT_LIST_DIR}/test.cpp)
target_sources(test PRIVATE ${CMAKE_CURRENT_LIST_DIR}/test.h)

target_include_directories(test PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)
