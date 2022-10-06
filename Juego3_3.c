#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	char nombre[25];
	char pass[15];
	char id[10];
	int i;
	char consulta [80];
	
		
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexin
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "JuegoBBDD",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	for (i=0; i<4; i++)
		printf ("Escribe el nombre, contrasenya y id de la persona, separados por un blanco\n") ;
	err = scanf ("%s %s %s", nombre, pass, id);
	if (err!=3)
	{
		printf ("Error al introducir los datos \n");
			exit (1);
	}
	
	strcpy (consulta, "INSERT INTO JUGADOR VALUES('");
	strcat (consulta, nombre);
	strcat (consulta, "','");
	
	strcat (consulta, pass);
	strcat (consulta, "','");
	
	strcat (consulta, id);
	strcat (consulta, "','");
	
	printf("consulta = %s\n", consulta);
	err = mysql_query(conn, consulta);
	
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	mysql_close (conn);
	exit(0);
}
