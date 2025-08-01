#
# Support file to uninstall the FLTK project using CMake
#
# Originally written by Michael Surette
#
# Copyright 1998-2024 by Bill Spitzak and others.
#
# This library is free software. Distribution and use rights are outlined in
# the file "COPYING" which should have been included with this file.  If this
# file is missing or damaged, see the license at:
#
#     https://www.fltk.org/COPYING.php
#
# Please see the following page on how to report bugs and issues:
#
#     https://www.fltk.org/bugs.php
#

if(NOT EXISTS "E:/computer science/Libraries/FLTK/fltk-1.4.3-source/fltk-1.4.3/build/install_manifest.txt")
  message(FATAL_ERROR
          "Cannot find install manifest: \"E:/computer science/Libraries/FLTK/fltk-1.4.3-source/fltk-1.4.3/build/install_manifest.txt\"")
endif()

file(READ "E:/computer science/Libraries/FLTK/fltk-1.4.3-source/fltk-1.4.3/build/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")

# Note 1: 'cmake -E remove [-f]' is deprecated since CMake 3.17 and the docs
# state: "The implementation was buggy and always returned 0. It cannot be
# fixed without breaking backwards compatibility. Use rm instead."
# Note 2: 'cmake -E rm [-f]' has been added in CMake 3.17
# Note 3:
# Remove this distinction if: cmake_minimum_required(VERSION 3.17) or higher.

if(CMAKE_VERSION VERSION_LESS 3.17)
  set(rm_cmd remove)
else()
  set(rm_cmd rm)
endif()

foreach(file ${files})
  message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  execute_process(
    COMMAND "${CMAKE_COMMAND}" -E ${rm_cmd} -f "$ENV{DESTDIR}${file}"
    OUTPUT_VARIABLE rm_out
    ERROR_VARIABLE  rm_err
    RESULT_VARIABLE rm_retval
  )

  if(NOT "${rm_retval}" STREQUAL 0)
    message(STATUS "Error removing \"$ENV{DESTDIR}${file}\"")
    message(STATUS "    Status = '${rm_retval}'")
    message(STATUS "    Output = '${rm_out}'")
    message(STATUS "    Error  = '${rm_err}'")
    message(FATAL_ERROR "Exiting - uninstall may be incomplete.")
  endif()

endforeach(file)
