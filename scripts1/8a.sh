#! /bin/bash
# Move all hidden file from a given directory to a newly created directory.


find $1 -type f \( -regex "./\..*" \) -exec mv {} $2 \;
