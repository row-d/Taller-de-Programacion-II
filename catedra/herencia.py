from dataclasses import dataclass

@dataclass
class Vehiculo:
    nombre: str
    ruedas: int
    cap: int
    
    def __repr__(self) -> str:
        return f"Este Vehiculo se llama {self.nombre}, tiene {self.ruedas} ruedas y capacidad de {self.cap} personas"
    
@dataclass
class VehiculoTerrestre(Vehiculo):
    ruedas = 5


hijo = VehiculoTerrestre("Auto",cap=5)

print(hijo)    
