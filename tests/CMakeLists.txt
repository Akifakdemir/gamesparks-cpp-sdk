cmake_minimum_required(VERSION 2.8.12)
project(GameSparksTests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DGS_TESTING=1")

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

if (APPLE)
	TARGET_LINK_LIBRARIES (${PROJECT_NAME} "-framework Foundation")
endif()
