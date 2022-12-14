class NotNumberException(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self) -> str:
        return f"Error: value type is not a number, received {type(self.value)}"        
        
class ZeroDivision(Exception):
    def __str__(self) -> str:
        return "Division Error: Cannot divide by zero"

def division(a,b):
    accepted_types = [int,float,complex]
    if type(a) not in accepted_types:
        raise NotNumberException(a)
    if type(b) not in accepted_types:
        raise NotNumberException(b)
    if b != 0:
        raise ZeroDivision() # o ZeroDivisionError() <- native exception 
    return a/b
