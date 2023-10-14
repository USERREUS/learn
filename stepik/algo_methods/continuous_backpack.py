'''
    https://stepik.org/lesson/13238/step/10?unit=3424
'''

N, space = map(int, input().split())
items = [tuple(map(int, input().split())) for _ in range(N)]
items.sort(key=lambda x: x[0] / x[1], reverse=True)

total = 0
for item in items:
    if space >= item[1]:
        total += item[0]
        space -= item[1]
    else:
        total += space * (item[0] / item[1])
        break
        
print("{:.3f}".format(total))