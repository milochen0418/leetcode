# Read from the file file.txt and output the tenth line to stdout.
if [ "$(cat file.txt | wc -l)" -gt "9" ]; then cat file.txt | head -n 10 | tail -n 1; fi;