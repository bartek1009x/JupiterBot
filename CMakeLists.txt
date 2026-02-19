cmake_minimum_required(VERSION 3.10)
project(JupiterBot C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(JupiterBot main.c constants.c mention_handler.c)

target_include_directories(JupiterBot PRIVATE
    ${CMAKE_SOURCE_DIR}/concord/include
)

find_package(CURL REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

target_link_libraries(JupiterBot PRIVATE
    ${CMAKE_SOURCE_DIR}/concord/lib/libdiscord.a
    CURL::libcurl
    OpenSSL::SSL
    OpenSSL::Crypto
    ZLIB::ZLIB
    pthread
)
