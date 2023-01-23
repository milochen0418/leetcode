# https://leetcode.com/problems/word-frequency/
# Read from the file words.txt and output the word frequency list to stdout.
# for i in $(cat words.txt); do echo $i; done
# tr ' ' '\n' < words.txt | sort | uniq -c | awk '{print $2, $1}'
# for i in $(cat words.txt); do echo $i; done | tr ' ' '\n' | sort | uniq -c | awk '{print $2, $1}'
# The sort order in above is wrong
for i in $(cat words.txt); do echo $i; done | tr ' ' '\n' | sort | uniq -c | sort -rn | awk '{print $2, $1}'
