from collections import *

class Solution:
    def maxFreqSum(self, s: str) -> int:
        vowels = "aeiou"
        vowels_dict = defaultdict(int)
        consonant_dict = defaultdict(int)
        for c in s:
            if c in vowels:
                vowels_dict[c] += 1
            else:
                consonant_dict[c] += 1

        vowel_count = 0
        consonant_count = 0
        for k, v in vowels_dict.items():
            vowel_count = max(vowel_count, v)
        for k, v in consonant_dict.items():
            consonant_count = max(consonant_count, v)
        
        return vowel_count + consonant_count