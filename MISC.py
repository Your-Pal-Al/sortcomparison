# -*- coding: utf-8 -*-
"""
@author: Alexa
Created: Sun Oct 10 19:53:04 2021
Project:
Description: 
"""
import pandas as pd
import random
import time

def sort_integers():
    a = pd.read_csv("random_integers.csv")

    b = a.values.tolist()
           
    start = time.perf_counter_ns() #start clock
    b.sort() #sort list
    stop = time.perf_counter_ns() #end clock
    
    print(f"Elapsed Time: {stop-start}")

def gen_integers(min_value=0, max_value=2147483640, count=1000000):
    a = [random.randint(min_value, max_value) for i in range(count)]
    a = pd.DataFrame(a)
    a.to_csv("random_integers.csv", index=False, header=False)

#main function
def main():
    sort_integers()

#auto-run main
if __name__ == "__main__":
    main()
    
#TODO: 