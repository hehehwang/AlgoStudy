# 17081 RPG Extreme
input = __import__('sys').stdin.readline

fR, fC = map(int, input().split())
field = [list(input().strip()) for _ in range(fR)]
mobs = [[[] for _ in range(fC)] for _ in range(fR)]
boxes = [[[] for _ in range(fC)] for _ in range(fR)]
commands = list(input().strip())
mobCnt, boxCnt = 0, 0
isGameOver = False

for i in range(fR):
    for j in range(fC):
        C = field[i][j]
        if C == '@':
            heroInit = (i, j)
            heroCoord = heroInit[:]
            field[i][j] = '.'
        elif C == '&' or C == 'M':
            mobCnt += 1
        elif C == 'B':
            boxCnt += 1
for i in range(mobCnt):
    mr, mc, mn, ma, md, mh, me = input().strip().split()
    mr, mc, ma, md, mh, me = map(int, [mr, mc, ma, md, mh, me])
    mobs[mr-1][mc-1] = {'name': mn, 'att': ma, 'def': md, 'hpMax': mh, 'exp': me}
for i in range(boxCnt):
    br, bc, typ, itm = input().strip().split()
    br, bc = int(br), int(bc)
    if typ == 'O': boxes[br-1][bc-1] = [typ, itm]
    else: boxes[br-1][bc-1] = [typ, int(itm)]

stat = {'lv': 1, 'hp': 20, 'hpMax' : 20, 'att': 2, 'def': 2, 'exp': 0}
inven = {'weapon': 0,
         'armor': 0,
         'accCnt': 0,
         'acc': {'HR': False,
                 'RE': False,
                 'CO': False,
                 'EX': False,
                 'DX': False,
                 'HU': False,
                 'CU': False}}
turns = 0

def lvUp():
    stat['lv'] += 1
    stat['hpMax'] += 5
    stat['hp'] = stat['hpMax']
    stat['att'] += 2
    stat['def'] += 2
    stat['exp'] = 0

def expGain(n):
    stat['exp'] += int(n*1.2) if inven['acc']['EX'] else n
    if stat['lv'] * 5 <= stat['exp']: lvUp()

def move(s):
    global fR, fC, turns, heroCoord
    turns += 1
    r, c = heroCoord
    if s == 'U':
        nr, nc = r - 1, c
    elif s == 'D':
        nr, nc = r + 1, c
    elif s == 'L':
        nr, nc = r, c - 1
    elif s == 'R':
        nr, nc = r, c + 1
    else:
        raise NotImplementedError
    if nr < 0 or nc < 0 or fR <= nr or fC <= nc \
            or field[nr][nc] == '#':
        heroCoord = (r, c)
    else: heroCoord = (nr, nc)


def events(c):
    move(c)
    hr, hc = heroCoord
    curr = field[hr][hc]
    if curr == 'B':
        itm = boxes[hr][hc]
        if itm[0] == 'O':
            if inven['accCnt'] == 4 or inven['acc'][itm[1]]: pass
            else:
                inven['acc'][itm[1]] = True
                inven['accCnt'] += 1
        elif itm[0] == 'W': inven['weapon'] = itm[1]
        elif itm[0] == 'A': inven['armor'] = itm[1]
        field[hr][hc] = '.'
    elif curr == '^':
        if inven['acc']['DX']: stat['hp'] -= 1
        else: stat['hp'] -= 5
        if stat['hp'] <= 0: dead(hr, hc)
    elif curr == '&' or curr == 'M':
        battle(hr, hc)

def battle(hr, hc):
    monster = mobs[hr][hc]
    # {'name': mn, 'att': ma, 'def': md, 'hpMax': mh, 'exp': me}
    mhp = monster['hpMax']
    firstAtk = True
    if field[hr][hc] == 'M':
        pass
    if field[hr][hc] == 'M' and inven['acc']['HU']:
        stat['hp'] = stat['hpMax']

    while 1:
        # hero attacks
        if firstAtk and inven['acc']['CO']:
            if inven['acc']['DX']:
                mhp -= max((stat['att']+inven['weapon'])*3 - monster['def'], 1)
            else: mhp -= max((stat['att']+inven['weapon'])*2 - monster['def'], 1)
        else: mhp -= max(stat['att']+inven['weapon'] - monster['def'], 1)

        # battle ends
        if stat['hp'] <= 0:
            dead(hr, hc)
            break
        if mhp <= 0:
            expGain(monster['exp'])
            if inven['acc']['HR']:
                stat['hp'] = min(stat['hp']+3, stat['hpMax'])
            if field[hr][hc] == 'M':
                field[hr][hc] = '.'
                youWin()
            field[hr][hc] = '.'
            break

        # monster attacks
        if firstAtk and inven['acc']['HU'] and field[hr][hc] == 'M':
            pass
        else:
            stat['hp'] -= max((monster['att'] - (stat['def'] + inven['armor'])), 1)

        if firstAtk: firstAtk = False

def dead(hr, hc):
    global heroCoord
    if not inven['acc']['RE']:
        gameOver(0)
        if field[hr][hc] == '^':
            print('YOU HAVE BEEN KILLED BY SPIKE TRAP..')
        else:
            print(f'YOU HAVE BEEN KILLED BY {mobs[hr][hc]["name"]}..')
    else:
        inven['acc']['RE'] = False
        heroCoord = heroInit[:]
        stat['hp'] = stat['hpMax']


def youWin():
    gameOver(1)
    print('YOU WIN!')

def keyToContinue():
    gameOver(1)
    print('Press any key to continue.')

def gameOver(n):
    global turns, isGameOver, heroCoord
    isGameOver = True
    for i in range(fR):
        for j in range(fC):
            if n and (i, j) == heroCoord: print('@', end='')
            else: print(field[i][j], end='')
        print()
    print('Passed Turns :', turns)
    print('LV :', stat['lv'])
    print(f"HP : {max(stat['hp'], 0)}/{stat['hpMax']}")
    print(f"ATT : {stat['att']}+{inven['weapon']}")
    print(f"DEF : {stat['def']}+{inven['armor']}")
    print(f"EXP : {stat['exp']}/{stat['lv']*5}")


for c in commands:
    if isGameOver: break
    events(c)
if not isGameOver: keyToContinue()
