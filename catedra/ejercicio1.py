from dataclasses import dataclass
from random import random


@dataclass
class Persona:
    fechaDeNacimiento:str
    rut:str

@dataclass

class IngenieroInformatico(Persona):
    proyectosRealizados:int = 0
    cargo: str


    def __init__(fecha,rut,proyectos,cargo):
        super(fecha,rut)
    
    def hacerProyecto(self) -> None:
        self.proyectosRealizados += 1

@dataclass(order=True)
class AlumnoEnPracticaDeInformatica(IngenieroInformatico):
    proyectosArruinados:int = 0
    fechaDeIngreso: str

    def hacerProyecto(self) -> None: # Polimorfismo
        prob = random()
        if prob < 0.3:
            super().hacerProyecto()
        else:
            self.proyectosArruinados += 1
persona1 = Persona("05/15/1964","16061494-3")
persona2 = Persona("04/19/1950","12647509-8")   