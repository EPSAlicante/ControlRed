<?php
			if (!$zPaginaMantenida)
				$zPaginaMantenida="Página mantenida por el Servicio de Informática de la EPS";
			$zFechaUltima="Última actualización: ";
			$zPaginaPrincipal = "página principal";
			$zEnviarCorreo="enviar correo";
?>
	<div class="pie">
		<div class="pietexto">
			<?php echo $zPaginaMantenida?><br />
			<?php echo $zFechaUltima?><?php if ($vFechaSys) echo $vFechaSys; else echo $Fecha; ?>
		</div> <!-- div pietexto -->	 
		<div class="pieimagenes">
				 <a href="/"><img src="./imagenes/casa.gif" alt="<?php echo $zPaginaPrincipal?>" style="border:0 none;" /></a>			 
		</div> <!-- div pietexto -->	 
	</div> <!-- div pie -->



<?php @mysql_close()?>
