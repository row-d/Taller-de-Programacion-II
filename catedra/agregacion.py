from dataclasses import dataclass,field
from typing import List

@dataclass
class Lapiz:
  color: str
  
@dataclass
class Estuche:
  lapices: List[Lapiz] = field(default_factory=list)

@dataclass
class Alumno:
  nombre:str
  estuche: Estuche


@dataclass
class Asignatura:
  nombre: str
  alumnos_inscritos: List[Alumno]
  def __post_init__(self):
    if len(self.alumnos_inscritos) < 1:
      raise AttributeError(f"Debe haber al menos un alumno en la lista {self.alumnos_inscritos.__name__}")


alumno = Alumno("David",Estuche([Lapiz("Rojo")]))
progra2 = Asignatura("Programacion 2",[alumno])