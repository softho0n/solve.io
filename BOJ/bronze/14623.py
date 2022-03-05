b1 = input()
b2 = input()

mul = int(b1, 2) * int(b2, 2)
bin_mul = bin(mul)

print(str(bin_mul)[2:])
