class Node:
    def __init__(self):
        self.count = 0
        self.edges = {}

class Trie:
    def __init__(self):
        self.root = Node()


class Solution:
    def longestCommonPrefix(self, words: List[str], k: int) -> List[int]:
        trie = Trie()

        best = ""
        second_best = ""

        for word in words:
            current = trie.root
            p = 0
            longest = 0
            for w in word:
                if w not in current.edges:
                    current.edges[w] = Node()
                current = current.edges[w]
                current.count += 1
                p += 1
                if current.count >= k:  # get longest prefix >= k
                    longest = p

            # new word ? if we have a longer prefix 
            if len(best) < longest:
                second_best = best
                best = word[:longest]
            elif len(second_best) < longest:
                second_best = word[:longest]

        ans = []
        for word in words:
            if word.startswith(best):
                ans.append(len(second_best))
            else:
                ans.append(len(best))
        return ans