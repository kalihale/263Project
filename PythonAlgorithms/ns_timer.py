import time

def acc_time():
    # Converted to floating point milliseconds
    return round(time.time_ns() / 1000000, 3)