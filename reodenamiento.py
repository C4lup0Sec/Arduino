import os
import shutil

# Define la estructura de carpetas
estructura = {
    "Proyectos": [],
    "Recursos": ["Diagramas", "Imágenes", "Documentación"],
    "Librerías": [],
    "Ejemplos": [],
}

# Función para crear carpetas según la estructura
def crear_carpetas(estructura, base_path):
    for carpeta, subcarpetas in estructura.items():
        carpeta_path = os.path.join(base_path, carpeta)
        os.makedirs(carpeta_path, exist_ok=True)
        for sub in subcarpetas:
            os.makedirs(os.path.join(carpeta_path, sub), exist_ok=True)

# Función para mover archivos a carpetas categorizadas
def mover_archivos(base_path):
    archivos = os.listdir(base_path)
    for archivo in archivos:
        archivo_path = os.path.join(base_path, archivo)
        if os.path.isfile(archivo_path):
            # Clasificar por extensión
            ext = archivo.split(".")[-1].lower()
            if ext in ["jpg", "jpeg", "png", "gif"]:
                destino = os.path.join(base_path, "Recursos", "Imágenes", archivo)
            elif ext in ["pdf", "txt"]:
                destino = os.path.join(base_path, "Recursos", "Documentación", archivo)
            elif ext in ["ino", "c", "cpp"]:
                proyecto_dir = os.path.join(base_path, "Proyectos", archivo.split(".")[0])
                os.makedirs(proyecto_dir, exist_ok=True)  # Crear subcarpeta para el proyecto
                destino = os.path.join(proyecto_dir, archivo)
            elif ext in ["zip", "rar"]:
                destino = os.path.join(base_path, "Librerías", archivo)
            else:
                destino = os.path.join(base_path, archivo)  # Sin clasificar

            # Mover archivo al destino
            shutil.move(archivo_path, destino)
            print(f"Movido: {archivo} -> {destino}")

# Ruta base
base_path = os.getcwd()

# Crear la estructura de carpetas
crear_carpetas(estructura, base_path)

# Mover archivos
mover_archivos(base_path)

print("Organización completada.")
