cmake_minimum_required(VERSION 2.6)
get_filename_component(CURRENT_DIR ${CMAKE_CURRENT_LIST_FILE} PATH) # for cmake before 2.8.3

project(examples C CXX ASM)

if(NOT HFRAMEWORK_PATH)
	set(HFRAMEWORK_PATH "${CURRENT_DIR}/../")
endif()

include(${HFRAMEWORK_PATH}/hFramework.cmake)

if(DEVEL)
	add_component_src("${CURRENT_DIR}/../")
else()
	add_component_lib(hSensors "${CURRENT_DIR}/../")
endif()

add_hexecutable(hitechnic_accel ../examples/hitechnic_accel.cpp)
add_hexecutable(hitechnic_gyro ../examples/hitechnic_gyro.cpp)
add_hexecutable(hitechnic_compass ../examples/hitechnic_compass.cpp)
add_hexecutable(hitechnic_colorv2 ../examples/hitechnic_colorv2.cpp)
add_hexecutable(lego_light ../examples/lego_light.cpp)
add_hexecutable(lego_sound ../examples/lego_sound.cpp)
add_hexecutable(lego_touch ../examples/lego_touch.cpp)
add_hexecutable(lego_ultrasonic ../examples/lego_ultrasonic.cpp)
