def solution(bandage, health, attacks):
    answer = 0
    max_health = health
    time = 0
    
    for attack in attacks:
        during_time = attack[0] - time - 1
        heal_val_per_sec = during_time * bandage[1]
        heal_val_per_add = during_time // bandage[0] * bandage[2]
        # print("sec:", heal_val_per_sec, "add", heal_val_per_add)
        health = min(max_health, health + heal_val_per_sec + heal_val_per_add)
        # print("attack", attack[1])
        if health-attack[1] <= 0:
            return -1
        health = max(0,health-attack[1])
        time = attack[0]
    
    return health