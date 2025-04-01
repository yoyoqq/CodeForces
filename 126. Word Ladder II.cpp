class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        depthMap = {}   # node, steps -> starting from begin
        ans = []

        # 3. find all paths that take us to the end -> begin
        def dfs(word, seq):
            if word == beginWord:
                ans.append(seq[::-1])
                return
            
            steps = depthMap[word]
            for i in range(len(word)):
                original = word 
                for ch in "abcdefghijklmnopqrstuvwxyz":
                    word = word[:i] + ch + word[i+1:]
                    if word in depthMap and steps == depthMap[word]+1:
                        seq.append(word)
                        dfs(word, seq)
                        seq.pop()
                word = original 
        
        q = deque([beginWord])
        depthMap[beginWord] = 1
        wordSet = set(wordList)
        wordSet.discard(beginWord)

        # 1. bfs to find the shortest path to the end  
        # keep track of the steps -> from begin to end 
        while q:
            word = q.popleft()
            if word == endWord:
                break
            original = word 
            step = depthMap[word]
            for i in range(len(word)):
                for ch in "abcdefghijklmnopqrstuvwxyz":
                    word = word[:i] + ch + word[i+1:]
                    if word in wordSet:
                        wordSet.discard(word)
                        q.append(word)
                        depthMap[word] = step + 1
                word = original 
        
        # 2. if we have a path  
        if endWord in depthMap:
            seq = [endWord]
            dfs(endWord, seq)

        return ans 