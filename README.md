Aplicación para habilitar/deshabilitar filtros de red predefinidos en Laboratorios de Informática.
Los filtros deben estar aplicados y definidos en el router. Cada laboratorio tiene una subred diferente definida para él. 
Los OID deben adaptarse al router/firewall particular. 
Instalación
 1.-Crear las tablas del fichero sql/CONTROLRED.sql. 
 2.-Copiar el contenido del directorio www al lugar de nuestro servidor Web que deseemos (bajo el documentRoot) 
 3.-Configurar la conexión a la base de datos. Para ello en el fichero includes/globales.inc, se modifica el valor de las variables:
    a.-$gBaseDatos= "base de datos"
    b.-$gIP="ip del servidor"
    c.-$gUser="usuario" 
    d.-$gPassword="pass"
    e.-Los valores generales oid 
 4.-Nos aseguramos de tener instalado el paquete php5-snmp. Si no, ejecutamos apt-get install php5-snmp
 5.-Configuramos la comunidad SNMP: $comunidadsnmp="xxxx"

Comentarios:
La pá¡gina de inicio es www/controlred.phtml.
La autenticación de usarios recae en apache, por lo que el usuario identificado se obtiene de REMOTE_USER.
También de obtiene del servidor Web la variable REMOTE_ADDR para saber si el usuario (debe ser grupo profesores) está presente en el laboratorio del que quiere cambiar los filtros. 
Si es administrador, puede cambiar los filtros de cualquiera sin estar en el laboratorio.
