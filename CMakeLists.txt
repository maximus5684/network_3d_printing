cmake_minimum_required(VERSION 3.5)
project(network_3d_printing)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(wxWidgets_CONFIGURATION mswu)

find_package(wxWidgets COMPONENTS
  core
  base
  adv
  REQUIRED
)

include_directories(
  include
)

include("${wxWidgets_USE_FILE}")

add_executable(${PROJECT_NAME}_browser
  src/browser.cpp
)

target_link_libraries(${PROJECT_NAME}_browser
  ${wxWidgets_LIBRARIES}
)

## Mark executables and/or libraries for installation
install(TARGETS ${PROJECT_NAME}_browser
  RUNTIME DESTINATION bin
)
