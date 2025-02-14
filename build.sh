#!/bin/bash

# use in root dir pls:pray:

withbear="true"
openafterbuild="true"
executablename="rte.exe"

if [ ! -d build ]; then
  mkdir build
fi

if [ "$withbear" == "false" ]; then
  gcc -Wall -Werror -Iinclude -o $executablename $(find src -type f -name "*.c") -Llib
elif [ "$withbear" == "true" ]; then
  bear -- gcc -Wall -Werror -Iinclude -o $executablename $(find src -type f -name "*.c") -Llib
else
  echo "withbear : $withbear has to be either \"true\" or \"false\" "
fi

echo "built"

if [ "$openafterbuild" == "false" ]; then
  echo "done"
elif [ "$openafterbuild" == "true" ]; then
  ./$executablename
else
  echo "openafterbuild : $openafterbuild has to be either \"true\" or \"false\" "
fi
