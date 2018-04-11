//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s):Hugo Delgadillo Cortez *********************************//
//*************			version de visual Studio 2017								******//
//*************											******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;
int luna = 0;
float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat TierraDiffuse[] = { 0.0f, 0.5215f, 0.9294f, 1.0f };			// tierra
GLfloat TierraSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat TierraShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.8431f, 0.5607f, 0.0, 1.0f };			// venus
GLfloat VenusSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat VenusShininess[] = { 50.0 };

GLfloat MercurioDiffuse[] = { 0.9529f, 0.9058, 0.8078, 1.0f };			// Mercurio
GLfloat MercurioSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MercurioShininess[] = { 50.0 };

GLfloat SaturnoDiffuse[] = { 0.8313f, 0.9098, 0.0509, 1.0f };			// Saturno
GLfloat SaturnoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat SaturnoShininess[] = { 50.0 };

GLfloat JupiterDiffuse[] = { 0.5215, 0.2588, 0.0627, 1.0f };			// Jupiter
GLfloat JupiterSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat JupiterShininess[] = { 50.0 };

GLfloat UranoDiffuse[] = { 0.7686, 1.0, 0.9882, 1.0f };			// Urano
GLfloat UranoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat UranoShininess[] = { 50.0 };

GLfloat NeptunoDiffuse[] = { 0, 0.9001, 1, 1.0f };			// Neptuno
GLfloat NeptunoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat NeptunoShininess[] = { 50.0 };







void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunDiffuse);
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);//camara
	//sol
	glPushMatrix();
	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);
	glDisable(GL_LIGHTING);
	glutSolidSphere(2.7, 30, 30);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);

	glPopMatrix();
	//mercurio
	glPushMatrix();
	glRotatef(mercurio, 0, 1, 1);//Traslacion mercurio 
	glTranslatef(5, 0, 0);
	glColor3f(0.937, 0.286, 0.062);
	glRotatef(mercurio, 1, 0, 0);//rotacion mercurio 
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MercurioDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MercurioSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MercurioShininess);
	glutWireSphere(0.5, 20, 20);
	glPopMatrix();

	glPushMatrix();//Venus
	glRotatef(venus, 0, 1, 1);//Traslacion mercurio 
	glTranslatef(7, 0, 0);
	glColor3f(0.952, 0.635, 0.203);
	glRotatef(venus, 1, 0, 0);//rotacion mercurio 
	glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS,VenusShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();

	//tierra
	glPushMatrix();//tierra
	glRotatef(tierra, 0, 1, 1);//Traslacion tierrra
	glTranslatef(10, 0, 0);
	glColor3f(0.0705, 0.403, 0.945);
	glRotatef(tierra, 1, 0, 0);//rotacion tierra
	glMaterialfv(GL_FRONT, GL_DIFFUSE, TierraDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, TierraSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, TierraShininess);
	glutWireSphere(0.5, 30, 30);
	glPushMatrix();
	glRotatef(120,0,0,1);
	glRotatef(luna, 0, 1, 0);//Traslacion luna
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);//rotacion luna
	glRotatef(tierra, 1, 0, 0);//rotacion tierra
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//marte
	glRotatef(marte, 0, 1, 1);//Traslacion mercurio 
	glTranslatef(13, 0, 0);
	glColor3f(1.0, 0.0, 0.0);
	glRotatef(marte, 1, 0, 0);//rotacion mercurio 
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
	glutWireSphere(1, 30, 30);
	glPushMatrix();
	glRotatef(120, 0, 0, 1);
	glRotatef(luna, 0, 1, 0);//Traslacion luna
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);//rotacion luna
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(240, 0, 0, 1);
	glRotatef(luna, 0, 1, 0);//Traslacion luna
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);//rotacion luna
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//jupiter
	glRotatef(jupiter, 0, 1, 1);//Traslacion mercurio 
	glTranslatef(16, 0, 0);
	glColor3f(0.517, 0.419, 0.13337);
	glRotatef(jupiter, 8, 0, 0);//rotacion Jupiter
	glMaterialfv(GL_FRONT, GL_DIFFUSE, JupiterDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, JupiterSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);
	glutWireSphere(2.0, 30, 30);
	glPushMatrix();
	glRotatef(luna, 1, 0, 0);//Traslacion luna
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);//rotacion luna
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(luna, 0, 0, 1);//Traslacion luna
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);//rotacion luna
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//saturno
	glRotatef(saturno, 0, 1, 1);//Traslacion saturno 
	glTranslatef(19, 0, 0);
	glColor3f(1.0, 1.0, 0.0);
	glRotatef(saturno, 1, 0, 0);//rotacion saturno
	glMaterialfv(GL_FRONT, GL_DIFFUSE, SaturnoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SaturnoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, SaturnoShininess);
	glutSolidTorus(2, 2, 2, 20);
	glutWireSphere(1.0, 30, 30);
	glPushMatrix();
	glRotatef(luna, 1, 0, 0);//Traslacion luna
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);//rotacion luna
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(luna, 0, 0, 1);//Traslacion luna
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);//rotacion luna
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//urano
	glRotatef(urano, 0, 1, 1);//Traslacion urano
	glTranslatef(21, 0, 0);
	glColor3f(0.133337,0.9001, 0.713);
	glRotatef(urano, 1, 0, 0);//rotacion urano 
	glMaterialfv(GL_FRONT, GL_DIFFUSE, UranoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, UranoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, UranoShininess);
	glutWireSphere(1, 30, 30);
	glPushMatrix();
	glRotatef(luna, 1, 0, 0);//Traslacion luna
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);//rotacion luna
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(luna, 0, 0, 1);//Traslacion luna
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);//rotacion luna
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//neptuno
	glRotatef(neptuno, 0, 1, 1);//Traslacion neptuno
	glTranslatef(24, 0, 0);
	glColor3f(0.145, 0.125, 0.835);
	glRotatef(neptuno, 1, 0, 0);//rotacion neptuno
	glMaterialfv(GL_FRONT, GL_DIFFUSE, NeptunoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, NeptunoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, NeptunoShininess);
	glutWireSphere(1, 30, 30);
	glPushMatrix();
	glRotatef(120, 0, 0, 1);
	glRotatef(luna, 0, 1, 0);//Traslacion luna
	
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);//rotacion luna
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glRotatef(240, 0, 0, 1);
	glRotatef(luna, 0, 1, 0);//Traslacion luna
	glTranslatef(2, 0, 0);
	glColor3f(1.0, 1.0, 1.0);
	glRotatef(luna, 1, 0, 0);//rotacion luna
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glutWireSphere(0.5, 30, 30);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();


	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;
		mercurio = (mercurio - 10) % 360;
		venus = (venus - 8) % 360;
		tierra = (tierra - 7) % 360;
		marte = (marte - 6) % 360;
		jupiter = (jupiter - 5) % 360;
		saturno = (saturno - 4) % 360;
		urano = (urano - 3) % 360;
		neptuno = (neptuno - 1) % 360;
		luna = (luna - 9) % 360;

		
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}