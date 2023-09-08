cmake_minimum_required(VERSION 3.12)

project(rogue
	DESCRIPTION "Rogue API example"
	LANGUAGES CXX)

find_package(Rogue REQUIRED)
add_library(Rogue::Rogue INTERFACE IMPORTED GLOBAL)
set_target_properties(Rogue::Rogue PROPERTIES
	INTERFACE_INCLUDE_DIRECTORIES "${ROGUE_INCLUDE_DIRS}"
	INTERFACE_LINK_LIBRARIES "${ROGUE_LIBRARIES}")

add_executable(app app.cxx)
target_link_libraries(app PRIVATE Rogue::Rogue)
