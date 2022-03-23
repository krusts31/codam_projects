import pandas as pd
import describe

pd.set_option('display.max_columns', 20)
pd.set_option('display.min_rows', 7)

def example():
	aaa = describe.Check_input(None)
	df = pd.read_csv(aaa)
	print(df.describe())
example()
