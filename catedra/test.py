from functools import reduce
numeros = [ 1 ,2 , 3 ,4 ]


# def doble(x):
    # return x * 2
    
doble = lambda x: x * 2
espar = lambda x: x % 2 == 0

pares = filter(espar,numeros)
pordos = map(doble,numeros)
suma = reduce(lambda acc,actual: acc + actual,numeros,0)

print(suma)
