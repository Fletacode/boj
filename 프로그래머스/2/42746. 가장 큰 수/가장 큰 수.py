from functools import cmp_to_key

def compare(a,b):
    if a+b > b+a:
        return 1
    elif a+b < b+a:
        return -1
    else:
        return 0
                
def solution(numbers):
    answer = ''
    li = [f"{i}" for i in numbers]
    li.sort(key=cmp_to_key(compare), reverse=True)

    answer = str(int(''.join(s for s in li)))
    return answer