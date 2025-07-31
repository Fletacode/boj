def solution(array, commands):
    answer = []
    for command in commands:
        i = command[0] - 1
        j = command[1]
        k = command[2] - 1
        temp = sorted(array[i:j])
        print(temp)
        answer.append(temp[k])
        
    return answer