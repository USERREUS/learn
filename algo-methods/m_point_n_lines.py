﻿'''
    https://stepik.org/lesson/13238/step/9?unit=3424
'''

segments = sorted([sorted(map(int,input().split())) for i in range(int(input()))], key=lambda x: x[1])
dots = [segments.pop(0)[1]]
for l, r in segments:
    if l > dots[-1]:
        dots.append(r)
print(str(len(dots)) + '\n' + ' '.join(map(str, dots)))