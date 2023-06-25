cmake_minimum_required(VERSION 3.14)

project(    e2promtools
            VERSION 0.0.0.1
            DESCRIPTION "")

add_compile_options(
#   -Werror
#   -pedantic-errors

  -Wpedantic

  -Wcast-align
#   -Wcast-qual
#   -Wconversion
#   -Wextra-semi
#   -Wfloat-equal

#   -Wnon-virtual-dtor
#   -Wold-style-cast
#   -Woverloaded-virtual
#   -Wredundant-decls
#   -Wsign-promo
#   -Wall
#   -Wextra  
)


file(WRITE "${PROJECT_BINARY_DIR}/.gitignore" [=[
# this .gitignore file
*.*
*
]=])

find_package(Boost 1.60 REQUIRED
	COMPONENTS
    program_options
		filesystem
		system
)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(e2clean 
source/e2clean.cpp
)
target_link_libraries(e2clean 
LINK_PUBLIC ${Boost_LIBRARIES}
)

include_directories(
    "./include"
)


