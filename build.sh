#!/bin/bash

# use in root dir pls:pray:

withbear="true"
openafterbuild="true"
executablename="rte.exe"

export LD_LIBRARY_PATH=$(pwd)/lib:$LD_LIBRARY_PATH # believe me idk why the heck this matters but gcc can't ffs find the libraries without it

if [ ! -d build ]; then
  mkdir build
fi

if [ "$withbear" == "false" ]; then
  gcc -Wall -Werror -Iinclude -o $executablename $(find src -type f -name "*.c") -Llib -lraylib
elif [ "$withbear" == "true" ]; then
  bear -- gcc -Wall -Werror -Iinclude -o $executablename $(find src -type f -name "*.c") -Llib -lraylib
else
  echo "withbear : $withbear has to be either \"true\" or \"false\" "
fi

echo "done"

if [ "$openafterbuild" == "false" ]; then
  echo "done"
elif [ "$openafterbuild" == "true" ]; then
  ./$executablename
else
  echo "openafterbuild : $openafterbuild has to be either \"true\" or \"false\" "
fi
