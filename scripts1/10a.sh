#! /bin/bash
# breadth first bfs of directory tree with the first level of the tree marked as 0, second as 1 and so on...


dir_depth() {
  cd "$1"
  maxdepth=0
  for d in */.; do
    [ -d "$d" ] || continue
    depth=`dir_depth "$d"`
    maxdepth=$(($depth > $maxdepth ? $depth : $maxdepth))
  done
  echo $((1 + $maxdepth))
}

dir_depth "$@"


