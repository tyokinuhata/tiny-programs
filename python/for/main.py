# for 変数 in リスト・辞書等: という書式

languages = {'English': '英語', 'French': 'フランス語', 'Japanese': '日本語'}
for language in languages:
    print(language)

for k, v in languages.items():
    print(str(k) + ': ' + str(v))

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for n in numbers:
    print(n)