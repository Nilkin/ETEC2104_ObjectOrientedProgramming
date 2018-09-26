set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../lib)

link_directories(${PROJECT_SOURCE_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR}/extlibs/SFML/include)
link_libraries(sfml-system-2 sfml-window-2 sfml-graphics-2 sfml-audio-2 sfml-network-2)

set_option(BUILD_SHARED_LIBS TRUE BOOL "TRUE to build runtime as shared libraries, FALSE to build static libraries")

include_directories(${PROJECT_SOURCE_DIR}/include)

set(INC ${PROJECT_SOURCE_DIR}/include)
set(SRC ${PROJECT_SOURCE_DIR}/src)

set(PROJECT_FILES
	${SRC}/main.cpp
)

add_executable(Demo ${PROJECT_FILES})

set_property(TARGET Demo PROPERTY CXX_STANDARD 14)
set_property(TARGET Demo PROPERTY CXX_STANDARD_REQUIRED ON)
