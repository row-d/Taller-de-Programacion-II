from dataclasses import dataclass

@dataclass
class Druida:
  magia: int = 4

@dataclass
class Ladron:
  habilidad: int = 7
  
@dataclass
class Heroes(Ladron,Druida):
  
  def __repr__(self) -> str:
    return f"magia: {self.magia} habilidad: {self.habilidad}"

h = Heroes()
print(isinstance(h,(Druida,Ladron)))
print(h)