t = (123, 123, 132.42222, 10000, 12345.67)

part_day = '{day}, '.format(
	day="day_" + str(t[0]).zfill(2),
)

part_ex = "{ex} : ".format(
	ex="ex_" + str(t[1]).zfill(2),
)

part_arg = "{:.2f}, ".format(t[2])
part_arg2 = "{:.2e}, ".format(t[3])
part_arg3 = "{:.2e}".format(t[4])

print(part_day + part_ex + part_arg + part_arg2 + part_arg3)
