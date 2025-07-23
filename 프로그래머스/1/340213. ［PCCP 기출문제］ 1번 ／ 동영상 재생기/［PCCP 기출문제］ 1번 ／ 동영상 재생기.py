
def cal_time(command,video_sec, pos_sec,op_start_sec, op_end_sec):
    
    if op_start_sec <= pos_sec <= op_end_sec:
        pos_sec = op_end_sec
    
    if command == "next":
        pos_sec = min(pos_sec+10, video_sec)
    elif command == "prev":
        pos_sec = max(pos_sec-10, 0)
    
    if op_start_sec <= pos_sec <= op_end_sec:
        pos_sec = op_end_sec
    
    return pos_sec

def tran_time_to_sec(time_str):
    return int(time_str.split(":")[0]) * 60 + int(time_str.split(":")[1])

def solution(video_len, pos, op_start, op_end, commands):
    answer = ''
    video_sec = tran_time_to_sec(video_len)
    pos_sec = tran_time_to_sec(pos)
    op_start_sec = tran_time_to_sec(op_start)
    op_end_sec = tran_time_to_sec(op_end)
    
    for command in commands:
        pos_sec = cal_time(command, video_sec,
                pos_sec,op_start_sec, op_end_sec)
    
    answer = f"{ pos_sec//60:02}:{pos_sec%60:02}"
            
    
    return answer