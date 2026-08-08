add_library(target)

target_sources(target PRIVATE ${CMAKE_CURRENT_LIST_DIR}/target.cpp)
target_sources(target PRIVATE ${CMAKE_CURRENT_LIST_DIR}/target.h)

target_include_directories(target PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)
