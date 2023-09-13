from dataclasses import dataclass,field
from typing import List

@dataclass
class Hoja:
  texto: str
  
@dataclass
class Libro:
  titulo: str
  autor: str
  hojas: List[Hoja] = field(default_factory=list)
  
  def __post_init__(self):
    if len(self.hojas) < 1:
      raise AttributeError("El libro debe tener al menos una hoja.")
    
  def __del__(self):
    del self.titulo, self.autor, self.hojas[::], self



hoja1 = Hoja("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.")
hoja2 = Hoja("Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.")
hojas = [hoja1,hoja2]
LoremIpsum = Libro("Lorem Ipsum","Marco Tulio Cicerón",hojas)

del LoremIpsum
print(hoja1)
print(hoja2)
