# Findlibcxxabi
# --------
#
# Find libcxxabi
#
# Find the native libcxxabi includes and library. This module defines:
#
#   LIBCXXABI_INCLUDE_DIRS, the headers needed to use libcxxabi.
#   LIBCXXABI_LIBRARIES, the libraries needed to use libcxxabi.
#   LIBCXXABI_FOUND, If false, do not try to use libcxxabi.

find_path(LIBCXXABI_INCLUDE_DIR __cxxabi_config.h
    PATH_SUFFIXES libcxxabi # Debian Bug #800492
)
find_library(LIBCXXABI_LIBRARY c++abi)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(libcxxabi DEFAULT_MSG LIBCXXABI_LIBRARY LIBCXXABI_INCLUDE_DIR)

if (LIBCXXABI_FOUND)
    set(LIBCXXABI_LIBRARIES ${LIBCXXABI_LIBRARY})
    set(LIBCXXABI_INCLUDE_DIRS ${LIBCXXABI_INCLUDE_DIR})
endif()

mark_as_advanced(LIBCXXABI_LIBRARY LIBCXXABI_INCLUDE_DIRS)
