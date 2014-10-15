<script type="text/javascript">
	if (document.all && document.getElementById) // Si se trata de ie hay que cargar una hoja de estilo con cosas particulares
		document.write("<link rel='stylesheet' type='text/css' href='../includes/estiloie.css'>");

	if (document.all && document.getElementById) // Si se trata de ie hay que cargar una hoja de estilo particular para imprimier
		document.write("<link rel='stylesheet' type='text/css' href='../includes/estiloprintie.css' media='print'> ");

	if (<?php if ($estilo=="altocontraste") echo "1==1"; else echo "1==0"?>) // Si hemos elegido el estilo de Alto Contraste
		document.write("<link rel='stylesheet' type='text/css' href='../includes/estiloAltoContraste.css'>");

	if (<?php if ($estilo=="textogrande") echo "1==1"; else echo "1==0"?>) // Si hemos elegido el estilo de Texto Grande
		document.write("<link rel='stylesheet' type='text/css' href='../includes/estiloTextoGrande.css'>");
</script>
