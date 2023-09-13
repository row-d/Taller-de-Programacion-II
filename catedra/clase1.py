n=10 
x=10.0 
s='hola' 
L=[n ,x , s]

# ejercicio 1
print(L)

# ejercicio 2
LL = [L,L]
print(LL)

# ejercicio 3

print(range(10))
print(list(range(10)))
print(list(range(0,10,2)))
print([i for i in range(0,10,2)])
A = False or L or "mundo"
isEven = lambda x : x % 2 == 0
evenFilter = filter(isEven,[1,2,3,4,5,6])
factorial = lambda x : x * factorial(x - 1) if x != 1  else 1  
print(list(evenFilter))



## pipe

def pipeList(iterable,*args):
    if isinstance(iterable,list):
        for y in args:
            for i in range(len(iterable)):     
                iterable[i] = y(iterable[i])
                
M = [1,2,3,4,5]

pipeList(M,
     lambda x : x *2,
     lambda x : x - 1)

print(M)