# https://leetcode.com/problems/valid-phone-numbers
# Read from the file file.txt and output all valid phone numbers to stdout.
cat file.txt | grep -E "^(\([0-9]{3,3}\) |[0-9]{3,3}-){1,1}[0-9]{3,3}-[0-9]{4,4}$"
