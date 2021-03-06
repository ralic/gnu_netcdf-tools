### configure.ac  -*- Autoconf -*-

AC_PREREQ(2.59)
AC_INIT([NetCDF tools], [0.1-rc1], [adir-devel@theory.asu.ru])
AC_CONFIG_SRCDIR([src/ncget.c])
AC_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE([foreign])

# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB

# Checks for libraries.

my_ac_check_lib_netcdf_save_LIBS="$LIBS"
LIBS="$LIBS_NETCDF_EXTRA $LIBS"
AC_CHECK_LIB([netcdf], [ncopen], [dnl
  AH_CHECK_LIB([netcdf])
  AC_DEFINE([HAVE_LIBNETCDF], 1)
  LIBS_NETCDF_EXTRA="-lnetcdf $LIBS_NETCDF_EXTRA"])
LIBS="$my_ac_check_lib_netcdf_save_LIBS"

## FIXME: shouldn't be necessary
my_ac_check_lib_df_save_LIBS="$LIBS"
LIBS="$LIBS_HDF4_EXTRA $LIBS"
AC_CHECK_LIB([df], [DFopen], [dnl
  AH_CHECK_LIB([df])
  AC_DEFINE([HAVE_LIBDF], 1)
  LIBS_HDF4_EXTRA="-ldf $LIBS_HDF4_EXTRA"])
LIBS="$my_ac_check_lib_df_save_LIBS"

my_ac_check_lib_mfhdf_save_LIBS="$LIBS"
LIBS="$LIBS_HDF4_EXTRA $LIBS"
AC_CHECK_LIB([mfhdf],  [ncopen], [dnl
  AH_CHECK_LIB([mfhdf])
  AC_DEFINE([HAVE_LIBMFHDF], 1)
  LIBS_HDF4_EXTRA="-lmfhdf $LIBS_HDF4_EXTRA"])
LIBS="$my_ac_check_lib_mfhdf_save_LIBS"

AS_IF([test "$ac_cv_lib_netcdf_ncopen" = no \
           && test "$ac_cv_lib_mfhdf_ncopen" = no],
      [AC_MSG_ERROR([Neither -lnetcdf nor -lmfhdf available])])
AC_SUBST([LIBS_NETCDF_EXTRA])
AC_SUBST([LIBS_HDF4_EXTRA])
AM_CONDITIONAL([HAVE_LIBNETCDF],
               [test "$ac_cv_lib_netcdf_ncopen" = yes])
AM_CONDITIONAL([HAVE_LIBHDF4],
               [test "$ac_cv_lib_mfhdf_ncopen" = yes])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([assert.h errno.h error.h stddef.h unistd.h])
AC_CHECK_HEADERS([netcdf.h hdf/netcdf.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([strchr strdup strtol])

AC_CONFIG_FILES([Makefile
                 doc/Makefile
                 lib/Makefile
                 src/Makefile])
AC_OUTPUT

### configure.ac ends here
