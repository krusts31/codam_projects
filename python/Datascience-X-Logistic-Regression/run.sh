#!/bin/bash
python3 describe.py datasets/dataset_train.csv
python3 pandas_test.py datasets/dataset_train.csv
python3 histogram.py datasets/dataset_train.csv
python3 scatter_plot.py datasets/dataset_train.csv
python3 pair_plot.py datasets/dataset_train.csv
python3 logreg_train.py datasets/dataset_train.csv
