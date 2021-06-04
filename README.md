## About

fetch a string terminated by a '\n' from a file descriptor passing as argument.


## Setup

```bash
# Clone the repository
$ git clone git@github.com:Robright20/get_next_line.git gnl

# copy the source file to your sources directory
# you may need also to update your Makefile
$ cp gnl/get_next_line.c [your_sources_path]

# build the libft library and move it to your libraries
$ make -C libft && cp libft/libft.a [your_libraries_path]

# copy the headers files to you includes
# you may need also to update your Makefile
$ cp get_next_line.h libft/libft.h [your_includes_path]
```

## Building
For the building, you may use a Makefile or the compiler.

With a Makefile:
1. Update your sources variable depending on the way it's
called. (some may use SRC other SOURCE etc...)
```Makefile
# by appending it
SRC += get_next_line.c
# OR adding at the end of the values already there
SRC = ... get_next_line.c
```
2. Update the LDFLAGS.
```Makefile
# by appending it
LDFLAGS += -lft
# OR adding at the end of the values already there
SRC = ... -lft
```
## Usage

Inside you C file:
```C
#include "get_next_line.h"

/*
* some codes....
*/

// create a variable
char *line;

// open a file
int fd = open("filename", O_RDONLY);

// read a line from a file
int ret = get_next_line(fd, &line);

/*
* NOTE: ret = 0 if there is no more lines to read
*	    = 1 if the read succeeded, in which case
*		the line will be stored in the variable
*		line.
*	    = -1 if there was an error
*/
```
## Authors
- Robert Bright : [email](robright28@gmail.com)
