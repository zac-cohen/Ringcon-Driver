# CMakeList.txt : CMake project for RingconDriver, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
set(VCPKG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../vcpkg")
#set(VCPKG_LOCAL_DIR "")
#set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

#set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>" CACHE STRING "" FORCE)


project ("RingconDriver")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



find_package(hidapi REQUIRED CONFIG)
# Add source to this project's executable.
add_executable (RingconDriver "Main.cpp" "Main.h" "joycon.hpp" "MouseController.hpp" "MyApp.h" "packet.h" "stdafx.h" "tools.hpp" "sio_client.cpp" "sio_socket.cpp" "internal/sio_client_impl.cpp" "internal/sio_packet.cpp" "internal/sio_client_impl.h" "internal/sio_packet.h" "sio_message.h")
target_compile_options(RingconDriver PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/std:c++17>
    $<$<CXX_COMPILER_ID:GNU>:-std=c++17>
    $<$<CXX_COMPILER_ID:Clang>:-std=c++17>
)
target_compile_definitions(RingconDriver PRIVATE UNICODE _UNICODE)
target_link_libraries(RingconDriver PRIVATE hidapi::hidapi)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})
target_link_libraries(RingconDriver PRIVATE ${wxWidgets_LIBRARIES})

find_package(OpenGL REQUIRED)
target_link_libraries(RingconDriver PRIVATE OpenGL::GL)


#find_package(ViGEmClient REQUIRED)
#target_link_libraries(RingconDriver PRIVATE ViGEmClient::ViGEmClient)
#set(VCPKG_ROOT "C:/Users/Zac/Desktop/projects/vcpkg")

set(VCPKG_INSTALLED_DIR "${VCPKG_ROOT}/installed/x64-windows")
target_link_libraries(RingconDriver PRIVATE "${VCPKG_INSTALLED_DIR}/lib/vigemclient.lib")

set_target_properties(RingconDriver PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
#include_directories("${VCPKG_INSTALLED_DIR}-static/include")
include_directories("${VCPKG_INSTALLED_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../socket.io-client-cpp/lib/asio/asio/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../socket.io-client-cpp/lib/websocketapp")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../socket.io-client-cpp/lib/rapidjson/include")
#
target_compile_definitions(RingconDriver PRIVATE BOOST_DATE_TIME_NO_LIB BOOST_REGEX_NO_LIB ASIO_STANDALONE _WEBSOCKETPP_CPP11_STL_ _WEBSOCKETPP_CPP11_FUNCTIONAL_)
target_include_directories(RingconDriver PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/lib/websocketpp")
#find_path(HIDAPI_INCLUDE_DIR hidapi.h PATHS ${VCPKG_INSTALLED_DIR}/include NO_DEFAULT_PATH)
#target_link_libraries(RingconDriver PRIVATE "${VCPKG_INSTALLED_DIR}/lib/")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RingconDriver PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
