n = 1e6+5
a, wei, p = [0] * n, [0] * n, [0] * n
f, color, d = [0] * n, [0] * n, [0] * n

def lower_bound(lst, val):
    return lst[val]


def unique(lst):
    return lst


def readline():
    return map(int, input().split())


def find(x):
    if x == f[x]:
        return x
    f[x] = find(f[x])
    return f[x]


def main():
    top = 0
    k1 = [0] * 1000000
    nn, q = readline()
    a = list(readline())
    for i in range(1, nn + 1):
        a[i] = readline()
        f[i] = i
        wei[a[i]] = i

    for i in range(2, n):
        if p[i]:
            continue
        pp = -1
        for j in range(i, n, i):
            if wei[j]:
                if pp == -1:
                    color[i] = find(wei[j])
                else:
                    f[find(pp)] = find(wei[j])
                pp = wei[j]
            p[j] = i

    for i in range(2, n):
        if p[i] == i:
            color[i] = find(color[i])

    c = 0

    for i in range(1, nn + 1):
        az = a[i] + 1
        c += 1
        d[c] = find(i)

        while az > 1:
            c += 1
            d[c] = color[p[az]]
            az /= p[az]

        d[1:c + 1] = sorted(d[1:c + 1])
        c = unique(d[1: c + 1]) - d[0] - 1

        for k in range(1, c):
            for j in range(k + 1, c + 1):
                top += 1
                k1[top] = (d[k], d[j])

        c = 0

    k1[1:top + 1] = sorted(k1[1:top + 1])
    for i in range(1, q + 1):
        x, y = readline()
        x = find(x)
        y = find(y)
        if x == y:
            print(0)
        else:
            ask = (min(x, y), max(x, y))
            jz = lower_bound(k1[1: top + 1], ask)
            if 1 <= jz and jz <= top and k1[jz] == ask:
                print(1)
            else:
                print(2)


if __name__ == '__main__':
    main()
