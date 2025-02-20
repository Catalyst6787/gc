#ifndef DMBGC_REPLACE_H
# define DMBGC_REPLACE_H

#define malloc(size) dmb_malloc(size)
#define free(size) dmb_free(size)

#endif