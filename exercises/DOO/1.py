class ArchivoNoAudio(Exception):
    pass

class NoEsMP3(Exception):
    pass

class Audio(object):
    def __init__(self,dir):
        if ".mp3" not in dir:
            raise NoEsMP3()
        self.__direccion = dir
    
    def get_direccion(self):
        return self.__direccion
    
    def set_direccion(self,dir:str):
        if ".mp3" not in dir:
            raise NoEsMP3()
        self.__direccion = dir
        
class ListaDeReproduccion(object):
    
    def __init__(self,audios):
        if not isinstance(audios,list):
            raise ArchivoNoAudio()
        for audio in audios:
            if not isinstance(audio,Audio):
                raise ArchivoNoAudio()
        self.__audios = audios
    
    def get_lista_de_reproduccion(self):
        return self.__listaDeReproduccion
    
    def insert_audio(self,audio):
        self.__listaDeReproduccion.append(audio)
    
    def agregar_audio_desde_dir(self,dir):
        if ".mp3" not in dir:
            raise NoEsMP3("Archivo con formato incorrecto")
        self.__audios.append(Audio(dir))
    def reproducir(self):
            for audio in self.__audios:
                try:
                    archivo = open(audio.get_direccion(),"r")
                    print(archivo.read())
                except:
                    archivo.close()


lista = ListaDeReproduccion([Audio(f"{i}.mp3") for i in range(2)])

lista.reproducir()