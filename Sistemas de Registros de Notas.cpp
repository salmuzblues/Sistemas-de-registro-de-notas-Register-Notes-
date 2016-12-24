
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;
/*hacemos la struct;Las estructuras nos permiten agrupar varios datos, que mantengan algún tipo de
relación, aunque sean de distinto tipo, permitiendo manipularlos todos juntos, usando
un mismo identificador, o cada uno por separado.
• Las estructuras son llamadas también muy a menudo registros, o en inglés records.
Tienen muchos aspectos en común con los registros usados en bases de datos. Y
siguiendo la misma analogía, cada objeto de una estructura se denomina a menudo
campo, o field.*/
struct alumno 
{
	int codigo;
	char  nombres[50];
	char apellidos[50];
	char cursos[50];
	char metodo[50];
	/*int pc01;
	int pc02;
	int pc03;*/
	int pcProm;
	int ep;
	int ef;
	int promed;
	
};
struct profesor
{
    int codigo;
	char nombres[50];
	char apellidos[50];
	char cursos[50];
	
};
// declaramos los Procesos ;
void mantenimientoDeAlumnos();
//void mantenimientoDeNotas();
void crearRegistroAlumno();
void mostrarArchivoAlumno();
void editarArchivoAlumno();
//void eliminarArchivoAlumno();
void buscarArchivoAlumno();

void mantenimientoDeProfesores();
void crearRegistroProfesor();
void mostrarArchivoProfesor();
void editarArchivoProfesor();
//void eliminarArchivoAlumno();
void buscarArchivoProfesor();

void mantenimientoDeNotas();
void registroDeNotas();
void reporteDeNotas();

int main ()
{
	int opcion;
	char opc = 's';
	while (opc == 's')
	{
		system("cls");
		cout<<"\n\n";
		cout << "\t\t  ======  UNIVERSIDAD COPIE/PASTE   ======";
        cout <<"\n\n               ";
        cout << "   ====  ""Sistema de Registro de Notas"" ====";
        cout << "\n\n";
        cout << "\n \t\t\t 1. Mantenimiento de Profesores";
        cout << "\n \t\t\t 2. Mantenimiento de Alumnos";
        cout << "\n \t\t\t 3. Mantenimiento de Notas";
        cout << "\n\n";
        cout << "\t\t\t Seleccione su Opcion :=> ";
        cin>>opcion;
        if(opcion>3 && opcion <= 0){
            cout<<"\n \t\t\tOpcion invalida!!!"<<endl;
            cout<<"\n \t\t\tIngrese la Opcion Correcta: ";
            cin>>opcion;
        }
        switch(opcion)
        {
        	case 1:
    				mantenimientoDeProfesores();
					break;
			case 2: 
					mantenimientoDeAlumnos();
					break;
			case 3:
					mantenimientoDeNotas();
					break;	
		
		}
		cout<<"Desea Regresar al SISTEMA DE REGISTRO DE NOTAS  S/N ";
	    fflush(stdin);////It's a function which allows you to flush [clear] the input buffer.
		cin>>opc;
	
	}
	system("Pause()");
	return 0;
	
}

void mantenimientoDeAlumnos()
{
	int opcion;
	char opc = 's';
	while (opc == 's')
	{
		system("cls");
	    cout << "\n\n";
        cout << "\t\t  ====== MANTENIMIENTO DE ALUMNOS ======";
        cout <<"\n\n                                          ";
     	cout << "\n \t\t\t 1. Registrar Alumno";
        cout << "\n \t\t\t 2. Mostrar Datos";
        cout << "\n \t\t\t 3. Editar Registro de Alumnos ";
        cout << "\n \t\t\t 4. Buscar Alumnos";
        cout << "\n \t\t\t 5. Mensaje de Salida";
        cout << "\n\n";
        cout << "\t\t\t Seleccione su Opcion :=> ";
        cin>>opcion;
        if(opcion>5 && opcion <= 0)
	    {
            cout<<"\n \t\t\tOpcion invalida!!!"<<endl;
            cout<<"\n \t\t\tIngrese la Opcion Correcta: ";
            cin>>opcion;
        }
        switch(opcion)
        {
        	case 1: 
         			crearRegistroAlumno();
         			break;
         	case 2:
         			mostrarArchivoAlumno();
         			break;
            case 3: 
         		    editarArchivoAlumno();
         			break;
         	case 4: 
         	        buscarArchivoAlumno();
         	        break;
         	case 5: 
                    cout<<"\n\n";
         	 		cout<<"Desea Regresar a MANTENIMIENTO DE ALUMNOS S/N ?\n"<<endl;
                    fflush(stdin);//It's a function which allows you to flush [clear] the input buffer. 
					cin>>opc;
					break;
       } 
        
	}
		system("Pause()");
		
}
void crearRegistroAlumno()
{
	system("cls");	
	FILE *F; // FILE es variable de tipo archivo y *file es el puntero;
	alumno A; // alumno es el tipo de estructura y la A la variable;
	
	//capturando Datos;
	do{
	cout<<"Codigo ---> "; 
	cin>>A.codigo;
	}while(A.codigo <= 99999 || A.codigo >= 999999);
	cout<<"Nombre ---> ";
	cin>>A.nombres;
	cout<<"Apellido ---> ";
	cin>>A.apellidos;
	cout<<"Curso ---> ";
	cin>>A.cursos;
	
	F = fopen("datosAlumno.txt","a+");//a+ (agregar) //fopen (abrir archivo)
	
	//Consistencia de exito de apertura del archivo
    
    if (F == NULL)
    {
    	cout<<"No se puede abrir el Archivo"<<endl;
    	exit(1);//(usually) indicates unsucessful termination
	}
	
	fwrite(&A,sizeof(A),1/* numero de archivoa a guardar*/,F/*(rn donde se guarda)*/);
	fclose(F);

	
	//avisando al usuario;
	cout<<"Alumno archivado\n\n"<<endl;
	
		system("Pause()");
}
 
void mostrarArchivoAlumno()
{
	system("cls");
	
	alumno A; 
	//leyendo disco;
	FILE *J;
	//G = fopen("c:/FDatos/Alumnos.dat","a+");
	J = fopen("datosAlumno.txt","a+");

	//Consistencia de exito de apertura del archivo
	if (J == NULL)
	{
		cout<<"No se puede Abrir el Archivo"<<endl;
		exit(1);
	}
	
	cout<<"========================================\n"<<endl;
    cout<<"Codigo\tNombre\tApellido\tCurso"<<endl;
    cout<<"----------------------------------------\n"<<endl;
    
    fread(&A,sizeof(A),1,J);
    while (!feof(J)) // Mientras no sea fin del archivo recorre,leemos cada archivo; feof(G) 
    {
    	// desplegando estructuras
    	cout<<A.codigo;
    	cout<<"\t"<<A.nombres;
    	cout<<"\t"<<A.apellidos;
    	cout<<setw(12)<<A.cursos;
    	cout<<"\n"<<endl;
    	fread(&A,sizeof(A),1,J);
	};// termina el while;
	
	fclose(J);
	
	cout<<"\n\n";
 system("Pause()");

}
void buscarArchivoAlumno()
{
	system("cls");
	FILE *H;
	alumno A;
	int codigo;
	// cargando la clave a buscar;
	cout<<"Codigo a Buscar ---> ";
	cin>>codigo;getchar();
	//abriendo; Leyendo ;cargando la estructura //
	H = fopen("datosAlumno.txt","a+");
	//consistencia de la apertura del archivo;
	if (H == NULL)
	{
		cout<<"No se Puede abrir el Archivo"<<endl;
		exit(1);
		
	}
	// aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyoñ{ñ-
    cout<<"========================================\n"<<endl;
    cout<<"Codigo\tNombre\tApellido\tCurso"<<endl;
    cout<<"----------------------------------------\n"<<endl;
    
    fread(&A, sizeof(A),1,/* se guarda un elemento por uno*/H); // H es donde se guardan los elementos donde se direcciona al puntero;
    
    // Desplegando el registro// lectura;
    while (!feof(H))
    {
    	if (A.codigo == codigo)
    	{
    		cout<<A.codigo;
    		cout<<"\t"<<A.nombres;
    		cout<<"\t"<<A.apellidos;
    		cout<<setw(12)<<A.cursos;
    		cout<<"\n"<<endl;
    		
		}
		fread(&A,sizeof(A),1,H);
	};
	//cerrando el archivo;
	fclose(H);
	system("Pause()");
	
}
void editarArchivoAlumno()
{
	system("cls");
	FILE *FF; //  variable Puntero para Abrir  el archivo existente;
	FILE *GG;// variable Puntero para crear un archivo temporal;
	alumno A;
	int hallado = 0;
	int remove01;
	int rename01;
	int codigo;
	//cargando clave para buscar;
	cout<<"Codigo a Editar ---> ";
	cin>>codigo;getchar(); // getchar solo te va capturar el primer caracter;
	//Abriendo, leyendo,cargando estructura;//
	FF = fopen("datosAlumno.txt","r+"); //  r == abre un fichero para lectura. Si el fichero no existe devuelve error. 
	                             // + == símbolo utilizado para abrir el fichero para lectura y escritura.
    // consistencia de la apertura del archivo;
    
    if (FF == NULL)
    {
    	cout<<"No se puede abrir el archivo\n "<<endl;
    	exit(1);
	}
	GG = fopen("Tempt.txt","a+");
	// consistencia del archivo;
	if (GG == NULL)
	{
		cout<<"No se puede abrir el Archivo\n";
		exit(1);
	}
	// aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo
     cout<<"========================================\n"<<endl;
     cout<<"Codigo\tNombre\tApellido\tCurso"<<endl;
     cout<<"----------------------------------------\n"<<endl;
	
     fread(&A,sizeof(A),1,FF);
	//proceso de  reescritura;	
	while(!feof(FF))
	{
		if (A.codigo == codigo)
		{
			cout<<"Nuevo Nombre ---> ";
			gets(A.nombres);
			cout<<"Nuevo Apellido ---> ";
			gets(A.apellidos);
			cout<<"Nuevo Curso ---> ";
			gets(A.cursos);
			fwrite(&A, sizeof(A), 1, GG); // fwrite (direcc_dato, tamaño_dato, numero_datos, punt_fichero);
			hallado = 1;
		}
		else
		{
			fwrite(&A,sizeof(A),1,GG);
		}
		   fread(&A,sizeof(A),1,FF);
		
	};// termina el while;
	// cerrando archivos;
	fclose(FF);
	fclose(GG);
	
	 //Removiendo y eliminando
    //Recordar que los nombres Directorios/carpetas y Archivos de datos no
    // pueden tener mas de 8.3  caracteres
    remove01 = remove("datosAlumno.txt");
    cout<<"REMOVIDO"<<"  "<<remove01;
    rename01 = rename("Tempt.txt","datosAlumno.txt");
    cout<<"RENOMBRADO"<<"  "<<rename01;
    // avisando;
    if ( hallado == 0)
    	cout<<"No existe este CODIGO \n\n";
	else
		cout<<"Registro Actualizado"<<endl;
	system("Pause()");
	
}

void mantenimientoDeProfesores()
{
	int opcion;
	char opc = 's';
	while (opc == 's')
	{
		system("cls");
	    cout << "\n\n";
        cout << "\t\t  ====== MANTENIMIENTO DE PROFESORES ======";
        cout <<"\n\n                                          ";
     	cout << "\n \t\t\t 1. Registrar Profesor";
        cout << "\n \t\t\t 2. Mostrar Datos";
        cout << "\n \t\t\t 3. Editar Profesor ";
        cout << "\n \t\t\t 4. Buscar Profesor";
        cout << "\n \t\t\t 5. Mensaje de Salida";
        cout << "\n\n";
        cout << "\t\t\t Seleccione su Opcion :=> ";
        cin>>opcion;
        if(opcion>5 && opcion <=0){
            cout<<"\n \t\t\tOpcion invalida!!!"<<endl;
            cout<<"\n \t\t\tIngrese la Opcion Correcta: ";
            cin>>opcion;
        }
        switch(opcion)
        {
        	case 1: 
         			crearRegistroProfesor();
         			break;
         	case 2:
         			mostrarArchivoProfesor();
         			break;
            case 3: 
         		    editarArchivoProfesor();
         			break;
         	case 4: 
         	        buscarArchivoProfesor();
         	        break;
         	case 5:
                cout<<"\n\n";
         		cout<<"Desea Regresar a MANTENIMIENTO DE PROFESORES S/N ?\n"<<endl;
        		fflush(stdin);//It's a function which allows you to flush [clear] the input buffer. 
				cin>>opc;
			         
       } 
        
	}
		system("Pause()");
		
}
void crearRegistroProfesor()
{
	system("cls");	
	FILE *P; // FILE es variable de tipo archivo y *file es el puntero;
	profesor B; // alumno es el tipo de estructura y la A la variable;
	
	//capturando Datos;
	do{
	cout<<"Codigo ---> "; 
	cin>>B.codigo;
    } while (B.codigo <= 99999|| B.codigo >= 999999);
	cout<<"Nombre ---> ";
	cin>>B.nombres;
	cout<<"Apellido ---> ";
	cin>>B.apellidos;
	cout<<"Curso a Dictar ---> ";
	cin>>B.cursos;
	
	P= fopen("datosProfesor.txt","a+");//a+ (agregar) //fopen (abrir archivo)
	
	//Consistencia de exito de apertura del archivo
     
    if (P == NULL)
    {
    	cout<<"No se puede abrir el Archivo"<<endl;
    	exit(1);
	}
	
	fwrite(&B,sizeof(B),1/* numero de archivoa a guardar*/,P/*(rn donde se guarda)*/);
	fclose(P);
	
	
	//avisando al usuario;
	cout<<"Profesor archivado\n\n"<<endl;
		system("Pause()");
}
void mostrarArchivoProfesor()
{
	system("cls");
	profesor B;
	FILE *G; 
	
	G = fopen("datosProfesor.txt","a+"); // G = fopen( "D:\UPN\Estructura de Datos\Proyect\Sistema de registro de Notas","a+");
	//consistencia del archivo
	if (G == NULL)
	{
		cout<<"No se puede abrir el archivo\n"<<endl;
		exit(1);
	}
		//aqui empieza la leida de lectura;
		//y fread () regresa siempre cuantas estructuras leyo;
	cout<<"========================================\n"<<endl;
    cout<<"Codigo\tNombre\tApellido\tCurso a Dictar"<<endl;
    cout<<"----------------------------------------\n"<<endl;
    
    fread(&B,sizeof(B),1,G);
    while (!feof(G)) // that returns nonzero (meaning TRUE) when there are no more data to be read from an input file stream, and zero (meaning FALSE) otherwise.
    { // desplegando estructura;
    	cout<<B.codigo;
    	cout<<"\t"<<B.nombres;
    	cout<<"\t"<<B.apellidos;
    	cout<<setw(12)<<B.cursos;
    	cout<<"\n"<<endl;
    	fread(&B,sizeof(B),1,G);
	};
	//no olvidar cerrar el archivo;
	fclose(G);
	
	cout<<"\n\n";
	system("Pause()");
}
void buscarArchivoProfesor()
{
	system("cls");
	profesor B;
	FILE *H;
	int codigo;
	//cargando la clave a buscar;
	cout<<"Codigo a Buscar ---> ";
	cin>>codigo;getchar();//This function reads in a character. It returns the character as the ASCII value of that character. 
	//This function will wait for a key to be pressed before continuing with the program. 
	
	//abirendo,leyendo y cargando la lectura;
	H = fopen("datosProfesor.txt","a+");
	//consistencia del archivo 
	if (H == NULL )
	{
		cout<<"No se puede abrir el archivo\n"<<endl;
		exit(1);
	}
	// aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyoñ{ñ-
    cout<<"========================================\n"<<endl;
    cout<<"Codigo\tNombre\tApellido\tCurso a Dictar"<<endl;
    cout<<"----------------------------------------\n"<<endl;
	fread(&B,sizeof(B),1,H);
	while(!feof(H))
    {
    	if(B.codigo == codigo)
    	{
        cout<<B.codigo;
    	cout<<"\t"<<B.nombres;
    	cout<<"\t"<<B.apellidos;
    	cout<<setw(12)<<B.cursos;
    	cout<<"\n";
        }  
    	fread(&B,sizeof(B),1,H);
	};
	// cerrar el archivo;
	fclose(H);
	
	cout<<"\n\n";
	system("Pause()");
}
void editarArchivoProfesor()
{
	system("cls");
	profesor B;
	FILE *PP;
	FILE *GG;
	int hallado=0;
	int codigo;
	int removed01;
	int renamed01;
	// cargando clave a buscar;
	cout<<"Codigo a Buscar ---> ";
	cin>>codigo;getchar();//This function reads in a character. It returns the character as the ASCII value of that character. 
	//This function will wait for a key to be pressed before continuing with the program. 
	
	// abriendo, leyendo y cargando archivo;
	PP = fopen("datosProfesor.txt","r+");
	//  r == abre un fichero para lectura. Si el fichero no existe devuelve error.
	// + == símbolo utilizado para abrir el fichero para lectura y escritura.
    // consistencia de la apertura del archivo;
    if (PP == NULL)
    {
    	cout<<"No se Puede abrir el Archivo\n"<<endl;
    	exit(1);
	}
	GG = fopen("Temporales.txt","a+");
	//a abre un fichero para añadir datos al final del mismo. Si no existe se crea 
	//+ símbolo utilizado para abrir el fichero para lectura y escritura.
	
	// consistencia del archivo;
	if (GG == NULL)
	{
		cout<<"No se puede abrir el Archivo\n"<<endl;
		exit(1);//exit(1) (usually) indicates unsucessful termination. However, it's usage is non-portable.
	}
	// aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo
    cout<<"========================================\n"<<endl;
    cout<<"Codigo\tNombre\tApellido\tCurso a Dictar"<<endl;
    cout<<"----------------------------------------\n"<<endl;
	fread(&B,sizeof(B),1,PP);
	
	while(!feof(PP)) // aquello retorna 1 o true cuando ya no hay mas data para ser leido desde del flujo de el archivo de entra, en otro caso sera 0;
	{
		if (B.codigo == codigo)
		{
			cout<<"Nuevo Nombre ---> ";
			 gets(B.nombres);
			cout<<"Nuevo Apellido ---> ";
			 gets(B.apellidos);
			cout<<"Nuevos Cursos a Dictar --> ";
			 gets(B.cursos);
			fwrite(&B,sizeof(B),1,GG);
			hallado = 1;
		}
		else
		{  //Para leer y escribir en ficheros que no sean de texto las operaciones que se
           // deben utilizar son fread y fwrite.
			fwrite(&B,sizeof(B),1,GG); 
             //Escribe tantos datos como indique numero de datos en el fichero, tomando los
             //datos a partir de la dirección del dato.
		}
		fread(&B,sizeof(B),1,PP);
		//Lee tantos datos como indique numero de datos del fichero, colocando
        //los datos leídos a partir de la dirección del dato.
	};
		fclose(PP);
        fclose(GG);
    
    //Removiendo y eliminando
    //Recordar que los nombres Directorios/carpetas y Archivos de datos no
    // pueden tener mas de 8.3  caracteres
    removed01 = remove("datosProfesor.txt");//elimina;
    cout<<"REMOVIDO"<<"  "<<removed01;
    renamed01 = rename("Temporales.txt","datosProfesor.txt");//renombrar;
    cout<<"RENOMBRADO"<<"  "<<renamed01;
    //avisando
    if ( hallado == 0 )
		cout<<"No Existe ese CODIGO ....\n\n";
	else
		cout<<"Registro Eliminado\n\n"<<endl;    

    
		system("Pause()");
}
	
void mantenimientoDeNotas()
{
	system("cls");
    int opcion;
	char opc = 's';
	while (opc == 's')
	{
		system("cls");
	    cout << "\n\n";
        cout << "\t\t  ====== MANTENIMIENTO NOTAS ======";
        cout <<"\n\n                                          ";
     	cout << "\n \t\t\t 1. Registrar Notas";
        cout << "\n \t\t\t 2. Reporte de Notas por Alumnos";
        cout << "\n \t\t\t 3. Mensaje de Salida";
        cout << "\n\n";
        cout << "\t\t\t Seleccione su Opcion :=> ";
        cin>>opcion;
        if(opcion>5 && opcion <= 0)
	    {
            cout<<"\n \t\t\tOpcion invalida!!!"<<endl;
            cout<<"\n \t\t\tIngrese la Opcion Correcta: ";
            cin>>opcion;
        }
        switch(opcion)
        {
        	case 1: 
         			registroDeNotas();
         			break;
        
         	case 2: 
         			reporteDeNotas();
         			break;
         	case 3:		
                    cout<<"\n\n";
         	 		cout<<"Desea Regresar a MANTENIMIENTO DE ALUMNOS S/N ?\n"<<endl;
                    fflush(stdin);//It's a function which allows you to flush [clear] the input buffer. 
					cin>>opc;
					break;
       } 
        
	}
		system("Pause()");
		
}
void registroDeNotas()
{   
    	system("cls");
	FILE *FF; //  variable Puntero para Abrir  el archivo existente;
	FILE *GG;// variable Puntero para crear un archivo temporal;
	alumno A;
	int hallado = 0;
	int remove01;
	int rename01;
	int codigo;
	//cargando clave para buscar;
	cout<<"Codigo a Buscar ---> ";
	cin>>codigo;getchar(); // getchar solo te va capturar el primer caracter;
	//Abriendo, leyendo,cargando estructura;//
	FF = fopen("datosAlumno.txt","r+"); //  r == abre un fichero para lectura. Si el fichero no existe devuelve error. 
	                             // + == símbolo utilizado para abrir el fichero para lectura y escritura.
    // consistencia de la apertura del archivo;
    
    if (FF == NULL)
    {
    	cout<<"No se puede abrir el archivo\n "<<endl;
    	exit(1);
	}
	GG = fopen("Tempt.txt","a+");
	// consistencia del archivo;
	if (GG == NULL)
	{
		cout<<"No se puede abrir el Archivo\n";
		exit(1);
	}
	// aqui siempre debe empezar el ciclo de lectura
    // y fread() regresa siempre cuantas estructuras leyo
     cout<<"========================================\n"<<endl;
     cout<<"Nombre\tApellido\tCursos"<<endl;
     cout<<"----------------------------------------\n"<<endl;
	
     fread(&A,sizeof(A),1,FF);
	//proceso de  reescritura;	
	while(!feof(FF))
	{
		if (A.codigo == codigo)
		{
			cout<<A.nombres;
    		cout<<"\t"<<A.apellidos;
    		cout<<setw(12)<<A.cursos;
    		cout<<"\n";
			cout<<"\n\t\t----INGRESE LAS NOTAS-----"<<endl;
    		cout<<"\n";
    		cout<<"Promedio de Practicas: "<<endl;
    	    cin>>A.pcProm;
    		cout<<"E.Parcial: "<<endl;
    		cin>>A.ep;
    		cout<<"E.Final: "<<endl;
    		cin>>A.ef;
			fwrite(&A, sizeof(A), 1, GG); // fwrite (direcc_dato, tamaño_dato, numero_datos, punt_fichero);
			hallado = 1;
			
		}
		else
		{
			fwrite(&A,sizeof(A),1,GG);
		}
		   fread(&A,sizeof(A),1,FF);
		
	};// termina el while;
	// cerrando archivos;
	
	fclose(FF);
	fclose(GG);
	
	 //Removiendo y eliminando
    //Recordar que los nombres Directorios/carpetas y Archivos de datos no
    // pueden tener mas de 8.3  caracteres
    remove01 = remove("datosAlumno.txt");
    cout<<"REMOVIDO"<<"  "<<remove01;
    rename01 = rename("Tempt.txt","datosAlumno.txt");
    cout<<"AGREGADO NOTAS"<<"  "<<rename01;
    // avisando;
    if ( hallado == 0)
    	cout<<"No existe este CODIGO \n\n";
	else
		cout<<"Registro Actualizado"<<endl;
	system("Pause()");

}
void reporteDeNotas()
{
	system("cls");
	
	alumno A; 
	//leyendo disco;
	FILE *J;
	//G = fopen("c:/FDatos/Alumnos.dat","a+");
	J = fopen("datosAlumno.txt","a+");

	//Consistencia de exito de apertura del archivo
	if (J == NULL)
	{
		cout<<"No se puede Abrir el Archivo"<<endl;
		exit(1);
	}
	
	cout<<"=======================================================\n"<<endl;
    cout<<"Nombre\tApellido\tCurso\tPromedioPC\tE.Parcial\tE.Final"<<endl;
    cout<<"-------------------------------------------------------\n"<<endl;
    
    fread(&A,sizeof(A),1,J);
    while (!feof(J)) // Mientras no sea fin del archivo recorre,leemos cada archivo; feof(G) 
    {
    	// desplegando estructuras
    	
    	cout<<A.nombres;
    	cout<<"\t"<<A.apellidos;
    	cout<<setw(12)<<A.cursos;
    	cout<<setw(12)<<A.pcProm;
		cout<<"\t\t"<<A.ep;
    	cout<<"\t\t"<<A.ef;
    	cout<<"\n"<<endl;
    	fread(&A,sizeof(A),1,J);
	};// termina el while;
	
	fclose(J);
	
	cout<<"\n\n";
 system("Pause()");
}


