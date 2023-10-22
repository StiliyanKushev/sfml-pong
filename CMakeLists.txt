cmake_minimum_required(VERSION 3.16)
project(SFMLPong LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

#[[ include all hpp headers in `include` folder ]]
include_directories(include)

#[[ add all cpp source files to the compiler ]]
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
add_executable(SFMLPong ${SOURCES})

target_link_libraries(SFMLPong PRIVATE sfml-graphics)
target_compile_features(SFMLPong PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET SFMLPong
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:SFMLPong>
        VERBATIM)
endif()

install(TARGETS SFMLPong)
