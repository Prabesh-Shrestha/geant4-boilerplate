cmake_minimum_required(VERSION 3.24)
project(MYPROJECT)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)


# downloads all submodules
find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}.git")
    option(GIT_SUBMODULE "check submodules", ON)
    if(GIT_SUBMODULE)
        message(STATUS "submodules update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} 
            RESULT_VARIABLE GIT_SUBMOD_RESULT
        )
        if( NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submoudle update failed, \n ${GIT_SUBMOD_RESULT}")
        endif()
    endif()
endif()

add_executable(main main.cc ${sources} ${headers})

target_link_libraries(main ${Geant4_LIBRARIES})

add_custom_target(MYPROJECT DEPENDS main)


