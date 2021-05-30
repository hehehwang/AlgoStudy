n = int(input())  # 원하는 값
m = int(input())  # 고장난 버튼 개수
broke = set(map(str, input().split())) if m else set() # 고장난 버튼을 str로 해서 set에 저장
k = 0
# k를 1씩 늘려가면서 n-k,n+k가 리모컨에서 입력 가능한지 확인했다
while m != 10 and m != 9:  # 고장난 버튼이 9/10개 제외일 때만 구했다.
    broker = False
    if n > k and set(str(n - k)) & broke == set():  # n-k의 숫자와 고장난 버튼의 숫자가 안겹치는 경우
        s = True
        broker = True
    elif set(str(n + k)) & broke == set():  # n+k의 숫자와 고장난 버튼의 숫자가 안겹치는 경우
        s = False
        broker = True
    # 이 때 n-k가 n+k보다 자릿수가 적거나 같으므로 둘 다 가능할 때는 s가 True가 되어 n-k로 계산했다.
    if broker:  # 안겹치는게 생기면 그 수까지 가는 경우를 세고 break한다.
        if s:
            t = n - k
        else:
            t = n + k
        answer1 = len(str(t)) + k  # n-k/n+k의 자릿수 + 그 수에서 n까지 이동하는 숫자인 k
        break
    k += 1
answer2 = abs(n - 100)  # 100에서 시작해서 원하는 위치까지 가는 횟수

# 출력하는 부분
if m != 10 and m != 9:  # 고장난 버튼이 0~8개일 때
    print(min(answer1, answer2))  # while문에서 구한 값과 100에서 시작할 때 중 작은 값

elif m == 10:  # 고장난 버튼 10개-> 100에서 시작하는 것만 생각
    print(answer2)

elif m == 9:  # 고장난 버튼 9개-> 100에서 시작/n-1자리/n자리/n+1자리의 aaaaa..에서 시작하는 것만 생각
    ok = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'} - broke  # 집합끼리 빼서 정상인 버튼 구함
    a = int(ok.pop())  # 고장안난 버튼의 숫자= a(정수)

    if a == 0:  # a==0이면 0에서 시작/100에서 시작 두 개만 생각
        print(min(answer2, n + 1))
    else:
        if len(str(n)) > 1:  # n이 한자리면 n-1자리 불가능
            s0 = str(a) * (len(str(n)) - 1)

        s1 = str(a) * len(str(n))
        s2 = str(a) * (len(str(n)) + 1)
        if len(str(n)) > 1:  # 100시작/n-1자리/n자리/n+1자리 중 최소값
            print(min(answer2, len(s0) + abs(int(s0) - n), len(s1) + abs(int(s1) - n), len(s2) + abs(int(s2) - n)))
        else:  # 100시작/n자리/n+1자리 중 최소값
            print(min(answer2, len(s1) + abs(int(s1) - n), len(s2) + abs(int(s2) - n)))