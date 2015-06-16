cmake_minimum_required(VERSION 2.8.12)
project(gamesparks_tests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory (gtest ${CMAKE_BINARY_DIR}/bin/gtest)
add_subdirectory (../base/build_scripts/ ${CMAKE_BINARY_DIR}/bin/gs)



file(GLOB_RECURSE TEST_SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/base/*.cpp")

add_executable(
    ${PROJECT_NAME}
    ${TEST_SOURCES}
    "${CMAKE_CURRENT_SOURCE_DIR}/../base/samples/extra/usleep.cpp"
)
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../base/samples/extra")
target_link_libraries(${PROJECT_NAME} gtest Gamesparks ${WS_LIBS})


#file(GLOB_RECURSE tests RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/base" "${CMAKE_CURRENT_SOURCE_DIR}/base/*.cpp")

#foreach(test_file ${tests})
#    message(${test_file})
#
#    get_filename_component(test_name ${test_file} NAME_WE)
#
#    add_executable(
#        ${test_name}
#        "${CMAKE_CURRENT_SOURCE_DIR}/base/${test_file}"
#        "${CMAKE_CURRENT_SOURCE_DIR}/../base/samples/extra/usleep.cpp"
#    )
#    target_include_directories(${test_name} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../base/samples/extra")
#    target_link_libraries(${test_name} gtest Gamesparks ${WS_LIBS})
#endforeach(test_file)
