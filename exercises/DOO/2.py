class Pinta(Enum):
    pass
class Numero(Enum):
    pass
class Reverso(Enum):
    pass

class Carta(Enum):
    pass

class Mano:
    pinta: Pinta
    numero: Numero
    reverso: Reverso
    puntos : int
    
    def __init__(self,pinta,numero,reverso,):
        self.pinta = Pinta[pinta]
        self.numero = Pinta[numero]
        self.reverso = Pinta[reverso]
        self.puntos = 0
        
    def contar_puntos():
        pass