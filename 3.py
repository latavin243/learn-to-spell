class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        str_len = len(s)
        if str_len <= 1:
            return str_len
        existing_ch = {s[0]}
        left, right = 0, 0
        res = 1
        while True:
            right += 1
            if right >= str_len:
                break
            cur = s[right]
            if cur in existing_ch:
                while left <= right:
                    existing_ch.remove(s[left])
                    if s[left] == cur:
                        left += 1
                        break
                    left += 1
            existing_ch.add(cur)
            cur_len = len(existing_ch)
            if cur_len > res:
                res = cur_len

        return res
