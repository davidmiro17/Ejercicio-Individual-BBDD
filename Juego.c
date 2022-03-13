//#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int victorias;
	
	
	
	conn = mysql_init(NULL);
	if (conn==NULL) 
	{
		printf ("Error al crear la conexion: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "Juego",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}


	err=mysql_query (conn, "SELECT distinct jugadores.username,jugadores.victorias FROM (jugadores) WHERE jugadores.victorias = (SELECT MAX(jugadores.victorias) FROM (jugadores))");
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	
	resultado = mysql_store_result (conn);
	row = mysql_fetch_row (resultado);
	
	
	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
	printf ("Jugador que ha conseguido el mayor número de victorias:\n");	
	       while (row !=NULL)
		
	{		
			victorias = atoi(row[1]);
			
			printf ("Username del jugador:%s \nNúmero de victorias conseguidas: %d\n", row[0],victorias);
			
			row = mysql_fetch_row (resultado);
	}
	
	
		mysql_close (conn);
		exit(0);
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	


