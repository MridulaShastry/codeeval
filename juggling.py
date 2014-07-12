# coding=utf-8
import sys
 
 
def convert1(s):
	elements = s.split(" ")
	b = []
	for flag, seq in zip(*[iter(elements)] * 2):
		if flag == "0":
			b.append(seq)
		elif flag == "00":
			for _ in list(seq):
				b.append("1")
	return "".join(b)
	 
 
def convert2(s):
	d = 0
	for i, b in enumerate(list(s)):
		if b == '1':
			d += 2 ** (len(s) - i - 1)
		return d
 
 
def main():
	with open(sys.argv[1], "r") as f:
		for line in f:
			print convert2(convert1(line.rstrip()))
 
 
if __name__ == "__main__":
	main()