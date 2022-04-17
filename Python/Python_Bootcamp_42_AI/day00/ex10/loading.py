import time
import sys

def ft_progress(lst):
	prefix = "ETA: "
	size = 40
	file=sys.stdout
	count = len(lst)
	def show(j):
		t = time.perf_counter()
		x = int(size*j/count)
		precent = int(100*j/count)
		estimate = (101 - precent) / t
		if (estimate <= 0.15):
			estimate = 0
		file.write("{}{:.2f}s [{}%][{}{}{}] {} / {} | elapsed time {:.2f}s\r".format("ETA: ", estimate, precent, "="*x, ">", " "*(size-x), j, count, t))
		file.flush()
	show(0)
	for i, item in enumerate(lst):
		yield item
		show(i+1)
	file.write("\n")
	file.flush()

listy = range(3333)
ret = 0
for elem in ft_progress(listy):
	ret += (elem + 3) % 5
	time.sleep(0.001)
print()
print(ret)
