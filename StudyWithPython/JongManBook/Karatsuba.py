
# 큰 수를 곱하는 O(n^2) 시간 앍고리즘

# num[]의 자릿수 올림을 처리한다.
def normalize(num):
    num.append(0)
    # 자릿수 올림을 처리한다.
    for i in range(len(num)-1):
        if num[i] < 0:
            borrow = (abs(num[i])+9) // 10
            num[i+1] -= borrow
            num[i] += borrow*10
        else:
            num[i+1] += num[i] // 10
            num[i] %= 10
    while 1< len(num) and num[-1] == 0:
        num.pop()
# 두 긴 자연수의 곱을 반환한다.
# 각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다.
# 예: multiply([3,2,1], [6,5,4]) = 123* 456 = 56088 = [8,8,0,6,5]

def multiply(a, b):
    c = [0]*(len(a)+len(b)+1)
    for i in range(len(a)):
        for j in range(len(b)):
            c[i+j] += a[i]*b[j]
    normalize(c)
    return c

# a += b*(10^k)를 구현한다.
# 만약 a:456[6,5,4], b:12[2,1], k=1이라면
# b의 2는 5에 더해져야 한다.
def addTo(a, b, k):
    for i in range(len(b)):
        a[i+k] += b[i]

# a -= b를 구현한다.
def subFrom(a, b):
    for i in range(len(b)):
        a[i] -= b[i]

def karatsuba(a, b):
    an, bn = len(a), len(b)
    # a보다 b가 짧을 경우 둘을 바꾼다.
    if an<bn : return karatsuba(b, a)
    # 기저 사례 : a나 b가 비어있는 경우:
    if an == 0 or bn == 0: return []
    # 기저 사례 : a가 비교적 짧은 경우 O(n^2)곱셈으로 변경
    # if an<=50 : return multiply(a, b)

    half = an //2
    a0 = [a[i] for i in range(half)]
    a1 = [a[i] for i in range(half, an)]
    b0 = [b[i] for i in range(min(bn, half))]
    b1 = [b[i] for i in range(min(bn, half), bn)]
    # z2 = a1*b1
    z2 = karatsuba(a1, b1)
    # z0 = a0*b0
    z0 = karatsuba(a0, b0)
    # a0 = a0+a1, b0 = b0+b1
    addTo(a0, a1, 0)
    addTo(b0, b1, 0)
    z1 = karatsuba(a0, b0)
    subFrom(z1, z0)
    subFrom(z1, z2)
    # ret = z0 + z1 * 10^half + z2*10^(half*2)
    ret = [0]*an
    addTo(ret, z0, 0)
    addTo(ret, z1, half)
    addTo(ret, z2, half*2)
    return ret

print(karatsuba([6, 5, 4, 3], [4, 3, 2, 1]))