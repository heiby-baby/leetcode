from collections import deque


class Solution:
    def kSimilarity(self, s1: str, s2: str) -> int:
        if s1 == s2:
            return 0

        queue = deque([(s1, 0)])
        visited = set([s1])

        while queue:
            current, swaps = queue.popleft()

            for i in range(len(current)):
                if current[i] == s2[i]:
                    continue

                for j in range(i + 1, len(current)):
                    if current[j] == s2[i]:
                        new_s = list(current)
                        new_s[i], new_s[j] = new_s[j], new_s[i]
                        new_s = ''.join(new_s)

                        if new_s == s2:
                            return swaps + 1

                        if new_s not in visited:
                            visited.add(new_s)
                            queue.append((new_s, swaps + 1))

                break

        return -1