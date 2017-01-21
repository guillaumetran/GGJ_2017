<<<<<<< HEAD
# Install script for directory: /home/guillaume/CLionProjects/GGJ_2017
=======
# Install script for directory: /Users/killin_m/Documents/Projets/Personnel/C++/GGJ_2017
>>>>>>> 5a84a5fe61b789b259de2d42218126afebeb9434

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "/home/guillaume/CLionProjects/GGJ_2017/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "/Users/killin_m/Documents/Projets/Personnel/C++/GGJ_2017/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> 5a84a5fe61b789b259de2d42218126afebeb9434
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
