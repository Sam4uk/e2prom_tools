cmake_minimum_required(VERSION 3.14)

project(    e2promtools
            VERSION 0.0.0.1
            DESCRIPTION "")

                                                                              
set(CMAKE_CXX_STANDARD 20)  

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

# find_package(Boost 1.60 REQUIRED
# 	COMPONENTS
#     program_options
# 		filesystem
# 		system
# )

# find_library(LOG4CPP NAMES log4cpp)
find_package(log4cxx REQUIRED)

IF( DEFINED variable )
    MESSAGE(STATUS "variable is defined" ${variable})
ELSE( DEFINED variable )
    MESSAGE(STATUS "variable is not defined")
ENDIF( DEFINED variable )

message(STATUS ${SS})
find_package(CURL REQUIRED)

IF(DEFINED NANIT_SCHEME)
add_compile_definitions(NANIT_SCHEME="""${NANIT_SCHEME}""")
ELSE(DEFINED NANIT_SCHEME)
MESSAGE(STATUS "variable is not defined")
ENDIF(DEFINED NANIT_SCHEME)


# add_compile_definitions(NANIT_HOST="""${variable}""")
# add_compile_definitions(NANIT_PATH_GET_SERIAL="""${variable}""")
# add_compile_definitions(NANIT_QUERY_GET_SERIAL="""${variable}""")
# add_compile_definitions(NANIT_PATH_CONFIRM_SERIAL="""${variable}""")
# add_compile_definitions(NANIT_QUERY_CONFIRM_SERIAL="""${variable}""")
# add_compile_definitions(NANIT_PATH_FAIL_SERIAL="""${variable}""")
# add_compile_definitions(NANIT_QUERY_FAIL_SERIAL="""${variable}""")
# include_directories(${Boost_INCLUDE_DIRS})
# add_executable(e2clean 
# source/e2clean.cpp
# )

add_executable(e2serial
source/e2serial.cxx
source/utils.cxx
)
                                                                       
include_directories(${LOG4CXX_INCLUDE_DIRS})  
target_link_libraries(e2serial 
                      PRIVATE 
                      ${CURL_LIBRARIES}
 )

# target_link_libraries(e2clean 
# LINK_PUBLIC ${Boost_LIBRARIES}
# )

include_directories(
    "./include"
)


