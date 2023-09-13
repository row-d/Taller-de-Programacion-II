from dataclasses import dataclass,InitVar,field


@dataclass
class Poligono:
  lados: int 
  
  def __repr__(self) -> str:
    return f"Numero de lados {self.lados}"
  
  def area(self) -> float:
    pass
  
@dataclass
class Cuadrado(Poligono):
  lados: int = field(init=False,default=4)
  lado: float
  valor_area: float = field(init=False)
  
  def __post_init__(self):
    self.valor_area = self.area()

  
  def area(self) -> float:
    return self.lado ** 2
  
Cuadrado()