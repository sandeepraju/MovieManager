# Install script for directory: /home/sandeep/SpecialTopic/moviemanager/src

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/sandeep/kde/inst/master")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "debugfull")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/home/sandeep/kde/inst/master/bin/moviemanager" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/sandeep/kde/inst/master/bin/moviemanager")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/sandeep/kde/inst/master/bin/moviemanager"
         RPATH "/home/sandeep/kde/inst/master/lib:/home/sandeep/kde/inst/master/lib")
  ENDIF()
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/sandeep/kde/inst/master/bin/moviemanager")
FILE(INSTALL DESTINATION "/home/sandeep/kde/inst/master/bin" TYPE EXECUTABLE FILES "/home/sandeep/SpecialTopic/moviemanager/src/moviemanager")
  IF(EXISTS "$ENV{DESTDIR}/home/sandeep/kde/inst/master/bin/moviemanager" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/sandeep/kde/inst/master/bin/moviemanager")
    FILE(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/sandeep/kde/inst/master/bin/moviemanager"
         OLD_RPATH "/home/sandeep/kde/inst/master/lib::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/home/sandeep/kde/inst/master/lib:/home/sandeep/kde/inst/master/lib")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/sandeep/kde/inst/master/bin/moviemanager")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/sandeep/kde/inst/master/share/applications/kde4/moviemanager.desktop")
FILE(INSTALL DESTINATION "/home/sandeep/kde/inst/master/share/applications/kde4" TYPE PROGRAM FILES "/home/sandeep/SpecialTopic/moviemanager/src/moviemanager.desktop")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/sandeep/kde/inst/master/share/config.kcfg/moviemanager.kcfg")
FILE(INSTALL DESTINATION "/home/sandeep/kde/inst/master/share/config.kcfg" TYPE FILE FILES "/home/sandeep/SpecialTopic/moviemanager/src/moviemanager.kcfg")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/sandeep/kde/inst/master/share/apps/moviemanager/moviemanagerui.rc")
FILE(INSTALL DESTINATION "/home/sandeep/kde/inst/master/share/apps/moviemanager" TYPE FILE FILES "/home/sandeep/SpecialTopic/moviemanager/src/moviemanagerui.rc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

