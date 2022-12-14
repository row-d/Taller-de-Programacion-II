from exceptions import division

a = 1
b = 0
try:
    division(a,b)
except Exception as expt:
    print(expt)