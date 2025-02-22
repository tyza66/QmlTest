cmake_minimum_required(VERSION 3.16)

project(openssl_example VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置 OpenSSL 路径
set(OPENSSL_ROOT_DIR "D:/Environment/OpenSSL-Win64")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
set(OPENSSL_CRYPTO_LIBRARY "${OPENSSL_ROOT_DIR}/lib/VC/x64/MD/libcrypto.lib")
set(OPENSSL_SSL_LIBRARY "${OPENSSL_ROOT_DIR}/lib/VC/x64/MD/libssl.lib")

find_package(Qt6 REQUIRED COMPONENTS Quick)

# 查找 OpenSSL 库
find_library(OPENSSL_CRYPTO_LIBRARY NAMES libcrypto crypto PATHS ${OPENSSL_ROOT_DIR}/lib/VC/x64/MD NO_DEFAULT_PATH)
find_library(OPENSSL_SSL_LIBRARY NAMES libssl ssl PATHS ${OPENSSL_ROOT_DIR}/lib/VC/x64/MD NO_DEFAULT_PATH)

if(OPENSSL_CRYPTO_LIBRARY AND OPENSSL_SSL_LIBRARY)
    message(STATUS "Found OpenSSL: ${OPENSSL_ROOT_DIR}")
    message(STATUS "OpenSSL Include: ${OPENSSL_INCLUDE_DIR}")
    message(STATUS "OpenSSL Crypto Library: ${OPENSSL_CRYPTO_LIBRARY}")
    message(STATUS "OpenSSL SSL Library: ${OPENSSL_SSL_LIBRARY}")
else()
    message(FATAL_ERROR "Could not find OpenSSL libraries")
endif()

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appopenssl
    main.cpp
    cryptoopenssl.cpp
    cryptoopenssl.h
)

qt_add_qml_module(appopenssl
    URI openssl_example
    VERSION 1.0
    QML_FILES
        Main.qml
)

set_target_properties(appopenssl PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# 为 appopenssl 目标设置包含目录和链接库
target_include_directories(appopenssl PRIVATE ${OPENSSL_INCLUDE_DIR})
target_link_libraries(appopenssl PRIVATE ${OPENSSL_SSL_LIBRARY} ${OPENSSL_CRYPTO_LIBRARY} Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS appopenssl
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
