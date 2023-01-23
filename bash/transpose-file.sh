# https://leetcode.com/problems/transpose-file
# Read from the file file.txt and print its transposed content to stdout.
awk \
'{
    for(i=1; i<=NF; ++i) {
        if (word[i] == "") {
            word[i] = $i
        } else {
            word[i] = word[i]" "$i
        }
    }
} END {
    for(i=1; i<=NF; ++i) {
        print word[i]
    }
}' \
file.txt
    