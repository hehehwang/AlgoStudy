# 1181 단어 정렬
input = __import__('sys').stdin.readline
words = set([])
for _ in range(int(input())):
    words.add(input().strip())
list = sorted(words, key=lambda x: (len(x), x))
for word in list:
    print(word)