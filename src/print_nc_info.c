/*** print_nc_info.c --- NetCDF metadata printing  -*- C -*- */

/*** Copyright (C) 2006 Anton Reznikov */

/** This program is free software; you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation; either version 2 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful, but
 ** WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 ** General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program; if not, write to the Free Software
 ** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 ** 02110-1301 USA
 */

/*** Code: */
#include "ncget.h"

int
print_nc_attribute_info (int ncid, int varid,
                         const char *attribute_name, int attnum)
{
  int data_len;
  nc_type data_type;
  char sds_name[MAX_NC_NAME];
  int ndims, dimids[MAX_VAR_DIMS], natts;

  if(attribute_name == NULL) {
    attribute_name = calloc(MAX_NC_NAME, sizeof(char));
    ncattname(ncid, varid, attnum, attribute_name);
  }

  if(varid == NC_GLOBAL)
    printf("Global attribute : ");
  else {
    ncvarinq(ncid, varid, sds_name, &data_type, &ndims, dimids, &natts);
    printf("%s : ", sds_name);
  }

  ncattinq(ncid, varid, attribute_name, &data_type, &data_len);
  
  switch(data_type) {
  case NC_BYTE:
    printf("NC_BYTE   : ");
    break;
  case NC_CHAR:
    printf("NC_CHAR   : ");
    break;
    
  case NC_SHORT:
    printf("NC_SHORT  : ");
    break;

  case NC_LONG:
    printf("NC_LONG   : ");
    break;

  case NC_FLOAT:
    printf("NC_FLOAT  : ");    
    break;
    
  case NC_DOUBLE:
    printf("NC_DOUBLE : ");
    break;
    
  default:
    error(0, 0, "%s : Unknowed type", __FUNCTION__);
    return -1;
  }

  printf("%s [%d]\n", attribute_name, data_len);
  return 0;
}

int print_nc_sds_info(int ncid, int varid)
{
  int i;
  nc_type data_type;
  char sds_name[MAX_NC_NAME];
  int ndims, dimids[MAX_VAR_DIMS], natts;
  long long_tmp;

  ncvarinq(ncid, varid, sds_name, &data_type, &ndims, dimids, &natts);

  switch(data_type) {
  case NC_BYTE:
    printf("NC_BYTE   : ");
    break;
  case NC_CHAR:
    printf("NC_CHAR   : ");
    break;
    
  case NC_SHORT:
    printf("NC_SHORT  : ");
    break;

  case NC_LONG:
    printf("NC_LONG   : ");
    break;

  case NC_FLOAT:
    printf("NC_FLOAT  : ");    
    break;
    
  case NC_DOUBLE:
    printf("NC_DOUBLE : ");
    break;
    
  default:
    error(0, 0, "%s : Unknowed type", __FUNCTION__);
    return -1;
  }

  printf("%s ", sds_name);

  for (i = 0; i < ndims; i++){
    ncdiminq(ncid, dimids[i], (char *) 0 , &long_tmp);
    printf("[%ld]", long_tmp);
  }
  printf("\n");

  for(i = 0; i < natts; i++)
    print_nc_attribute_info(ncid, varid, (char *) NULL, i);
  return 0;
}

/*** print_nc_info.c ends here */
