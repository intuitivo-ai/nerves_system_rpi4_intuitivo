cmake_minimum_required(VERSION 3.10)
project(libsystemd-stub C)

add_library(systemd SHARED sd_stub.c)
target_include_directories(systemd PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)

include(GNUInstallDirs)

install(TARGETS systemd
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY systemd/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/systemd)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/libsystemd.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/libsystemd.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libsystemd.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
