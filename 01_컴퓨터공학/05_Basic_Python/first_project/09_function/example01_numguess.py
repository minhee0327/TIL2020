import random
answer = random.randint(1,100)
# print(answer)
def numguess(answer):
    try_cnt = 5
    while True:
        if try_cnt == 0:
            print("기회를 모두 소진하였습니다.\n 정답은 {} 였습니다.".format(answer))
            break
        n = eval(input("입력해주세요: "))
        if n == answer:
            print("정답")
            break
        elif n < answer:
            print("정답은 {}보다 큽니다.".format(n))
        else:
            print("정답은 {}보다 작습니다.".format(n))
        try_cnt -= 1

numguess(answer)