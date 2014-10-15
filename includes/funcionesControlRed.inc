<?php 

function AltaACL($nombre,$item,$restriccion,$protocolo,$ipOrigen,$mascaraOrigen,$ipDestino,$mascaraDestino,$tose,$operPuertoOrigen,$puertoOrigen,$operPuertoDestino,$puertoDestino,$estado,$descripcion,$siempreActivo){
	
	$cmdSQL="INSERT INTO ROUTERACLITEMS (NOMBRE,ITEM,RESTRICCION,PROTOCOLO,IPORIGEN,MASCARAORIGEN,IPDESTINO,MASCARADESTINO,TOSE,OPERPUERTOORIGEN,PUERTOORIGEN,OPERPUERTODESTINO,PUERTODESTINO,ESTADO,DESCRIPCION,SIEMPREACTIVO ) VALUES ('".$nombre."', ".$item.", '".$restriccion."', '".$protocolo."', '".$ipOrigen."', '".$mascaraOrigen."', '".$ipDestino."', '".$mascaraDestino."', '".$tose."','".$operPuertoOrigen."', ".$puertoOrigen.", '".$operPuertoDestino."', ".$puertoDestino.", ".$estado.",'".$descripcion."','".$siempreActivo."')";
	$rsql=mysql_query($cmdSQL);
	
	if($rsql){
		return true;	
	}else{
		return false;
	}
}

function ExisteACLIgual($nombre,$item,$restriccion,$protocolo,$ipOrigen,$mascaraOrigen,$ipDestino,$mascaraDestino,$tose,$operPuertoOrigen,$puertoOrigen,$operPuertoDestino,$puertoDestino,$estado){

	$cmdSQL="SELECT NOMBRE, ITEM, RESTRICCION, PROTOCOLO, IPORIGEN, IPDESTINO, MASCARAORIGEN, MASCARADESTINO , TOSE, OPERPUERTOORIGEN, OPERPUERTODESTINO, ESTADO FROM ROUTERACLITEMS WHERE NOMBRE='".$nombre."' and  ITEM=".$item." and RESTRICCION='".$restriccion."' and PROTOCOLO='".$protocolo."' and IPORIGEN='".$ipOrigen."' and IPDESTINO='".$ipDestino."' and MASCARAORIGEN='".$mascaraOrigen."' AND MASCARADESTINO='".$mascaraDestino."' and TOSE='".$tose."' and OPERPUERTOORIGEN='".$operPuertoOrigen."' and OPERPUERTODESTINO='".$operPuertoDestino."'";

	 $rsql=mysql_query($cmdSQL);
	
	if(mysql_num_rows($rsql)!=0){
		return true;
	}else{
		return false;
	}
	
}

function ExisteACLDiferenteOrden($nombre,$item,$restriccion,$protocolo,$ipOrigen,$mascaraOrigen,$ipDestino,$mascaraDestino,$tose,$operPuertoOrigen,$puertoOrigen,$operPuertoDestino,$puertoDestino,$estado){

	$cmdSQL="SELECT NOMBRE, ITEM, RESTRICCION, PROTOCOLO, IPORIGEN, IPDESTINO, MASCARAORIGIEN, MASCARADESTINO , TOSE, OPERPUERTOORIGEN, OPERPUERTODESTINO, ESTADO FROM ROUTERACLITEMS";
	$cdmSQL.="WHERE NOMBRE='".$mobre."' and  RESTRICCION='".$restriccion."' and PROTOCOLO='".$protocolo."' and IPORIGEN='".$ipOrigen."' and IPDESTINO='".$ipDestino."' and MASCARAORIGIEN='".$mascaraOrigen."', MASCARADESTINO='".$mascaraDestino."' and TOSE='".$tose."' and OPERPUERTOORIGEN='".$operPuertoOrigen."' and OPERPUERTODESTINO='".$operPuertoDestino."'";

	$rsql=mysql_query($cmdSQL);
	
	if(mysql_num_rows($rsql)!=0){
		return true;
	}else{
		return false;
	}
	
}

function CambiarOrdenALC($nuevoItem,$nombre,$restriccion,$protocolo,$ipOrigen,$mascaraOrigen,$ipDestino,$mascaraDestino,$tose,$operPuertoOrigen,$puertoOrigen,$operPuertoDestino,$puertoDestino,$estado){

	$cmdSQL="UPDATE ROUTERACLITEMS SET ITEM=".$nuevoItem;
	$cmdSQL.="WHERE NOMBRE='".$mobre."' and  RESTRICCION='".$restriccion."' and PROTOCOLO='".$protocolo."' and IPORIGEN='".$ipOrigen."' and IPDESTINO='".$ipDestino."' and MASCARAORIGIEN='".$mascaraOrigen."', MASCARADESTINO='".$mascaraDestino."' and TOSE='".$tose."' and OPERPUERTOORIGEN='".$operPuertoOrigen."' and OPERPUERTODESTINO='".$operPuertoDestino."'";
	$rsql=mysql_query($cmdSQL);
	if($rsql){
		return $cmdSQL;
	}else{
		return $cmdSQL;
	}
}

function ExisteNombreACL($nombre){

	$cmdSQL="SELECT NOMBRE FROM ROUTERACLITEMS WHERE NOMBRE='".$nombre."'";	
	$rsql=mysql_query($cmdSQL);
	
	if(mysql_num_rows($rsql)!=0){
		return true;
	}else{
		return false;
	}
}


function ObtenerDescripcionACL($nombre,$item,$restriccion,$protocolo,$ipOrigen,$mascaraOrigen,$ipDestino,$mascaraDestino,$tose,$operPuertoOrigen,$puertoOrigen,$operPuertoDestino,$puertoDestino,$estado){

	$cmdSQL="SELECT DESCRIPCION FROM ROUTERACLITEMS WHERE NOMBRE='".$nombre."' and  RESTRICCION='".$restriccion."' and PROTOCOLO='".$protocolo."' and IPORIGEN='".$ipOrigen."' and IPDESTINO='".$ipDestino."' and MASCARAORIGEN='".$mascaraOrigen."' and MASCARADESTINO='".$mascaraDestino."' and TOSE='".$tose."' and OPERPUERTOORIGEN='".$operPuertoOrigen."' and OPERPUERTODESTINO='".$operPuertoDestino."'";
	$rsql=mysql_query($cmdSQL);
	
	if(mysql_num_rows($rsql)!=0){
		while ($fila = mysql_fetch_array($rsql)){
			$descripcion=$fila["DESCRIPCION"];
		}
		return $descripcion;
	}else{
		return "";
	}
	
}

function BorrarListaACL($nombre){

	$cmdSQL="DELETE FROM ROUTERACLITEMS WHERE NOMBRE='".$nombre."'";
	$rsql=mysql_query($cmdSQL);
	if($rsql){
		return true;
	}else{
		return false;
	}
}


function AnyadirDescripcionACL($nombre, $item,$descripcion,$activo){
	
	$cmdSQL="UPDATE ROUTERACLITEMS SET DESCRIPCION='".$descripcion."', SIEMPREACTIVO='".$activo."' WHERE NOMBRE='".$nombre."' and ITEM=".$item."";
	$rsql=mysql_query($cmdSQL);
	if($rsql){
		return $cmdSQL;
	}else{
		return $cmdSQL;
	}

}

function ObtenerSiempreActiva($nombre,$item,$restriccion,$protocolo,$ipOrigen,$mascaraOrigen,$ipDestino,$mascaraDestino,$tose,$operPuertoOrigen,$puertoOrigen,$operPuertoDestino,$puertoDestino,$estado){

	$cmdSQL="SELECT SIEMPREACTIVO FROM ROUTERACLITEMS WHERE NOMBRE='".$nombre."' and  RESTRICCION='".$restriccion."' and PROTOCOLO='".$protocolo."' and IPORIGEN='".$ipOrigen."' and IPDESTINO='".$ipDestino."' and MASCARAORIGEN='".$mascaraOrigen."' and MASCARADESTINO='".$mascaraDestino."' and TOSE='".$tose."' and OPERPUERTOORIGEN='".$operPuertoOrigen."' and OPERPUERTODESTINO='".$operPuertoDestino."'";
	$rsql=mysql_query($cmdSQL);
	
	if(mysql_num_rows($rsql)!=0){
		while ($fila = mysql_fetch_array($rsql)){
			$descripcion=$fila["SIEMPREACTIVO"];
		}
		return $descripcion;
	}else{
		return "";
	}

}

function EstablecerACLActiva($nombreLista,$item){

	$cmdSQL="UPDATE ROUTERACLITEMS SET ESTADO=1 WHERE NOMBRE='".$nombreLista."' and ITEM='".$item."'";
	$rsql=mysql_query($cmdSQL);
	if($rsql){
		return false;
	}else{
		return true;
	}
}

function EstablecerACLInactiva($nombreLista,$item){

	$cmdSQL="UPDATE ROUTERACLITEMS SET ESTADO=2 WHERE NOMBRE='".$nombreLista."' and ITEM=".$item."";
	$rsql=mysql_query($cmdSQL);
	if($rsql){
		return true;
	}else{
		return false;
	}

}

function GuardarOpcionActivada($nombreLista, $nombreOpcion){

	$cmdSQL="UPDATE ROUTERACLITEMS SET OPCIONACTIVA='".$nombreOpcion."' WHERE NOMBRE='".$nombreLista."'";
	$rsql=mysql_query($cmdSQL);
	if($rsql){
		return $cmdSQL;
	}else{
		return $cmdSQL;
	}

}


function ObtenerOpcionActivada($nombreLista){

	$cmdSQL="SELECT DISTINCT(OPCIONACTIVA)FROM ROUTERACLITEMS WHERE NOMBRE='".$nombreLista."'";
	$rsql=mysql_query($cmdSQL);
	
	if(mysql_num_rows($rsql)!=0){
		while ($fila = mysql_fetch_array($rsql)){
			$descripcion=$fila["OPCIONACTIVA"];
		}
		return $descripcion;
	}else{
		return "";
	}

}




function ObtenerItemsActivos($nombreLista){

	$cmdSQL="SELECT ITEM FROM ROUTERACLITEMS WHERE  NOMBRE='".$nombreLista."' and ESTADO=1 ORDER BY ITEM";
	$rsql=mysql_query($cmdSQL);
	
	$cont=0;
	if(mysql_num_rows($rsql)!=0){
		while ($fila = mysql_fetch_array($rsql)){
			$retorno[$cont]=$fila["ITEM"];
			$cont++;
		}
		return $retorno;
	}else{
		return "";
	}
}

//Función:  ano
//Esta función obtiene el año de una fecha (en formato 'dd-mm-aaaa' o 'aaaa-mm-dd')
function ano($Fecha,$Formato) {
        switch($Formato) {
                case "dma":
                        $Ano=substr($Fecha,6,4);
                        break;
                case "amd":
                        $Ano=substr($Fecha,0,4);
                        break;
                default:
                        $Ano="";
        }
        return $Ano;
}

//Función:  dia
//Esta función obtiene el dia de una fecha (en formato 'dd-mm-aaaa' o 'aaaa-mm-dd')
function dia($Fecha,$Formato) {
        switch($Formato) {
                case "dma":
                        $Dia=substr($Fecha,0,2);
                        break;
                case "amd":
                        $Dia=substr($Fecha,8,2);
                        break;
                default:
                        $Dia="";
        }
        return $Dia;
}

function HoraActual(){
        return (date("H").":".date("i"));
}


function FechaActual(){
        return (date("Y")."-".date("m")."-".date("d"));
}

function GrupoUsuario($Codigo) {
        $sql = "select GRUPOSWEB.CODGRU from USUARIOSWEB, GRUPOSWEB where UPPER(USUARIOSWEB.CODUSU)=UPPER('$Codigo') and USUARIOSWEB.GIDNUMBER = GRUPOSWEB.GIDNUMBER  ";
        $rescont = mysql_query($sql);
        $datoscont = mysql_fetch_array($rescont);
        $codgru = $datoscont["CODGRU"];
        return $codgru;
}

function obtenerlang($zIdioma){
        if (!$zIdioma) $vcodigoidioma="es";
        if ($zIdioma=="cas") $vcodigoidioma="es";
        if ($zIdioma=="val") $vcodigoidioma="es-va";
        if ($zIdioma=="ing") $vcodigoidioma="en";
        return $vcodigoidioma;
}

function proc_Historico($Operacion, $IP, $Usuario, $Descripcion,$Aplicacion, $Idioma)
{

   $fechaActual = date("Y")."-".date("m")."-".date("d");
   $horaActual = date("H").":".date("i").":".date("s");

   if (!$Idioma) $Idioma="cas";
   // se trata de una operacion realizada sobre la tabla ULTIMASNOTICIAS
   //$Descripcion = proc_protegercadena($Descripcion);

   $sql = "insert into HISTORICOGENERAL (RUSER, RADDR,FECHA, HORA, OPERACION,DESCRIP,APLICACION,IDIOMA) values ('$Usuario','$IP', '$fechaActual', '$horaActual','$Operacion','$Descripcion','$Aplicacion','$Idioma')";
   $result = mysql_query($sql);
   if (!$result) echo "error "  . mysql_error();
   // si la insert ha ido bien la variable result valdrá cero
   return $result;
}

?>
