class Solution {
    fun mergeAlternately(word1: String, word2: String): String {
        val result = StringBuilder()
        val maxLength:Int = maxOf(word1.length, word2.length)
        var i = 0
        while (i<maxLength) {
            if(i<word1.length) result.append(word1[i])
            if(i<word2.length) result.append(word2[i])
            i++
        }
        return result.toString()
    }
}