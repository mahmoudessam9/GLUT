#include <GL/glut.h>
#include <cmath>
const float PI = 22.0f / 7.0f;
void SetupRC() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0, 1.0, 5000.0);  
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(300.0, -300.0, 600.0,   
		0.0, 0.0, 0.0,    
		0.0, 1.0, 0.0);  
}

void Draw() {

}

void RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST); // Enable depth testing

	Draw(); //

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Enable depth buffer
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL Half Cylinder");

	SetupRC();
	glutDisplayFunc(RenderScene);
	glutMainLoop();
	return 0;
}
