cache = {}
def lcs(a, b):
    try:
        return cache[tuple(sorted((tuple(a), tuple(b))))]
    except KeyError:
        if not (len(a) and len(b)):
            cache[tuple(sorted((tuple(a), tuple(b))))] = []
            return []
        if a[-1] == b[-1]:
            result = lcs(a[:-1], b[:-1]) + [a[-1]]
            cache[tuple(sorted((tuple(a), tuple(b))))] = result
            return result
        first = lcs(a, b[:-1])
        second = lcs(a[:-1], b)
        if len(first) > len(second):
            cache[tuple(sorted((tuple(a), tuple(b))))] = first
            return first
        cache[tuple(sorted((tuple(a), tuple(b))))] = second
        return second

raw_input()
a,b = map(int, raw_input().split()),map(int, raw_input().split())
print ' '.join(map(str, lcs(a, b)))
