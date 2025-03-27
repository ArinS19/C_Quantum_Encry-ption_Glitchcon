cmake_minimum_required(VERSION 3.10)

project(KyberDemo C)

set(CMAKE_C_STANDARD 99)

# Path to liboqs (adjust if needed)
include_directories(C:/Users/sinha/liboqs/install/include)

# Link against the liboqs library
link_directories(C:/Users/sinha/liboqs/install/lib)

# Compile kyber_demo.c
add_executable(kyber_demo kyber_demo.c)

# Link with liboqs
target_link_libraries(kyber_demo oqs)
