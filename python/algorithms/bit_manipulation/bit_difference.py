def minBitFlips(start: int, goal: int) -> int:
    count = 0
    diff = start ^ goal

    while diff :
        if diff & 1 :
            count += 1
        diff = diff >> 1
    return count

print(minBitFlips(10, 7))
print(minBitFlips(7, 82))
